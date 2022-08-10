#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <OpenNI.h>

using namespace std;
using namespace cv;
using namespace openni;

int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 450;
int WINDOW_FPS = 30;

// 鼠标点击事件
bool lButtonDown = false;
static Point p;
static int pointNum = 0;
void onMouse(int event, int x, int y, int flags, void* depth)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        pointNum++; 
        p.x = x;
        p.y = y;
        lButtonDown = true;
    }
}

bool HandleStatus(Status status)
{
    if (status == STATUS_OK)
        return true;
    printf("ERROR: #%d, %s", status,
        OpenNI::getExtendedError());
    //ReadLastCharOfLine();
    return false;
}

int main(int argc, char** argv)
{
    // 1. Initial OpenNI
    Status status = STATUS_OK;    
    if (OpenNI::initialize() != STATUS_OK)
    {
        cerr << "OpenNI Initial Error: "
            << OpenNI::getExtendedError() << endl;
        return -1;
    }

    // 2. Open Device
    Device mDevice;
    if (mDevice.open(ANY_DEVICE) != STATUS_OK)
    {
        cerr << "Can't Open Device: "
            << OpenNI::getExtendedError() << endl;
        return -1;
    }

    // 3. Create depth stream
    VideoStream mDepthStream;
    if (mDevice.hasSensor(SENSOR_DEPTH))
    {
        if (mDepthStream.create(mDevice, SENSOR_DEPTH) == STATUS_OK)
        {
            // 3a. set video mode
            VideoMode mMode;
            mMode.setResolution(WINDOW_WIDTH, WINDOW_HEIGHT);
            mMode.setFps(WINDOW_FPS);
            mMode.setPixelFormat(PIXEL_FORMAT_DEPTH_1_MM);
            if (mDepthStream.setVideoMode(mMode) != STATUS_OK)
            {
                cout << "Can't apply VideoMode: "
                    << OpenNI::getExtendedError() << endl;
            }
        }
        else
        {
            cerr << "Can't create depth stream on device: "
                << OpenNI::getExtendedError() << endl;
            return -1;
        }
    }
    else
    {
        cerr << "ERROR: This device does not have depth sensor" << endl;
        return -1;
    }

    // 4. Create color stream
    VideoStream mColorStream;
    if (mDevice.hasSensor(SENSOR_COLOR))
    {
        if (mColorStream.create(mDevice, SENSOR_COLOR) == STATUS_OK)
        {
            // 4a. set video mode
            VideoMode mMode;
            mMode.setResolution(WINDOW_WIDTH, WINDOW_HEIGHT);
            mMode.setFps(WINDOW_FPS);
            mMode.setPixelFormat(PIXEL_FORMAT_RGB888);

            if (mColorStream.setVideoMode(mMode) != STATUS_OK)
            {
                cout << "Can't apply VideoMode: "
                    << OpenNI::getExtendedError() << endl;
            }

            // 4b. image registration
            if (mDevice.isImageRegistrationModeSupported(IMAGE_REGISTRATION_DEPTH_TO_COLOR))
            {
                mDevice.setImageRegistrationMode(IMAGE_REGISTRATION_DEPTH_TO_COLOR);
            }
        }
        else
        {
            cerr << "Can't create color stream on device: "
                << OpenNI::getExtendedError() << endl;
            return -1;
        }
    }
    else
    {
        cerr << "ERROR: This device does not have color sensor" << endl;
        return -1;
    }

    // 5. create OpenCV Window
    cv::namedWindow("Depth Image", cv::WindowFlags::WINDOW_NORMAL);
    cv::namedWindow("Color Image", cv::WindowFlags::WINDOW_NORMAL);
    cv::namedWindow("Image Center", cv::WindowFlags::WINDOW_NORMAL);

    // 6. start
    VideoFrameRef  mColorFrame;
    VideoFrameRef  mDepthFrame;
    mDepthStream.start();
    mColorStream.start();
    int iMaxDepth = mDepthStream.getMaxPixelValue();
    while (true)
    {
        // 7. check is color stream is available
        if (mColorStream.isValid())
        {
            // 7a. get color frame
            if (mColorStream.readFrame(&mColorFrame) == STATUS_OK)
            {
                // 7b. convert data to OpenCV format
                const cv::Mat mImageRGB(mColorFrame.getHeight(), mColorFrame.getWidth(), CV_8UC3, (void*)mColorFrame.getData());
                // 7c. convert form RGB to BGR
                cv::Mat cImageBGR;
                cv::cvtColor(mImageRGB, cImageBGR, cv::COLOR_RGB2BGR);
                // 7d. show image
                //cv::imshow("Color Image", cImageBGR);
                
                 if (mDepthStream.readFrame(&mDepthFrame) == STATUS_OK)
                {
                    // 在rgb上画出图像中心点深度值
                    const cv::Mat mImageDepth(mDepthFrame.getHeight(), mDepthFrame.getWidth(), CV_16UC1, (void*)mDepthFrame.getData());
                    openni::DepthPixel* pDepth = (DepthPixel*)mDepthFrame.getData();  // 指向图像第一个像素的指针  
                    DepthPixel* centerPixel =
                        (DepthPixel*)((char*)mDepthFrame.getData() +
                            (mDepthFrame.getHeight() * mDepthFrame.getStrideInBytes() / 2)) +
                        (mDepthFrame.getWidth() / 2);
                    float wX, wY, wZ;
                    status = CoordinateConverter::convertDepthToWorld(
                        mDepthStream,
                        (float)(mDepthFrame.getWidth() / 2),
                        (float)(mDepthFrame.getHeight() / 2),
                        (float)(*centerPixel),
                        &wX, &wY, &wZ);
                    if (!HandleStatus(status)) return 1;
                    printf("Center pixel's at distance is %gmm "
                        "located at %gmmx%gmm\r\n",
                        wZ, wX, wY);

                    // 显示图像中心点深度值
                    circle(cImageBGR, Point2d(mDepthFrame.getWidth() / 2, mDepthFrame.getHeight() / 2), 5, Scalar(0, 0, 255), 2); // 给人脸中心点画圆
                    putText(cImageBGR, to_string(wZ), Point2d(mDepthFrame.getWidth() / 2, mDepthFrame.getHeight() / 2), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255));
                    //cv::imshow("Image Center", cImageBGR);

                    // 在rgb上画出鼠标任意点击处的深度值
                    setMouseCallback("Image Center", onMouse);
                    if (lButtonDown)
                    {
                        // 读取鼠标点击处坐标、深度值
                        // 采用上述方法2的原理实现
                        DepthPixel* buttonPixel =
                            (DepthPixel*)((char*)mDepthFrame.getData() +
                                (p.y * mDepthFrame.getStrideInBytes())) +
                            (p.x * mDepthFrame.getStrideInBytes() / mDepthFrame.getWidth());
                        //cout << p.x << ", " << p.y << endl;
                        //cout << mDepthFrame.getStrideInBytes() << endl; //640
                        //cout << mDepthFrame.getHeight() << endl; //240
                        //cout << mDepthFrame.getWidth() << endl; //320

                        int dX2, dY2, dZ2;
                        dX2 = p.x;
                        dY2 = p.y;
                        dZ2 = *buttonPixel;
                        float wX2, wY2, wZ2;
                        status = CoordinateConverter::convertDepthToWorld(
                            mDepthStream,
                            dX2, dY2, dZ2,
                            &wX2, &wY2, &wZ2);
                        if (!HandleStatus(status)) return 1;
                        cout << "pixel is at " << dX2 << "," << dY2 << "," << dZ2 << endl;
                        //cout << "located at " << wX << "," << wY << endl; // 目前暂不清楚x y具体表示的所在位置
                        cout << "distance is " << wZ2 << "mm" << endl;
                        //cout << *buttonPixel << endl;
                        cout << "-----------" << endl;

                        circle(cImageBGR, Point2d(dX2, dY2), 5, Scalar(255, 0, 0), 2); // 给人脸中心点画圆
                        putText(cImageBGR, to_string(wZ2), Point2d(dX2, dY2), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));


                        if (cv::waitKey(1) == 'q')
                            break;
                        //lButtonDown = false;
                    }
                    cv::imshow("Image Center", cImageBGR);
                }
                //------------
            }
        }

        // 8a. get depth frame
        if (mDepthStream.readFrame(&mDepthFrame) == STATUS_OK)
        {
            // 8b. convert data to OpenCV format
            const cv::Mat mImageDepth(mDepthFrame.getHeight(), mDepthFrame.getWidth(), CV_16UC1, (void*)mDepthFrame.getData()); 
            // 8c. re-map depth data [0,Max] to [0,255]
            cv::Mat mScaledDepth;
            mImageDepth.convertTo(mScaledDepth, CV_8U, 255.0 / iMaxDepth);
            // 8d. show image
            cv::imshow("Depth Image", mScaledDepth);

            //openni::DepthPixel* pDepth = (DepthPixel*)mDepthFrame.getData();  // 指向图像第一个像素的指针  
            ////// ---------读取图像某点深度的两种方法，以中心点为例：        
            ////// 方法1 访问该处元素值
            ////int middleIndex = (mDepthFrame.getHeight() + 1) * mDepthFrame.getWidth() / 2;                  
            ////// 方法2 指针偏移至该处
            ////DepthPixel* centerPixel =
            ////    (DepthPixel*)((char*)mDepthFrame.getData() +
            ////    (mDepthFrame.getHeight() * mDepthFrame.getStrideInBytes() / 2)) + 
            ////    (mDepthFrame.getWidth() / 2);
            ////// 两种方法对比输出，结果相等
            ////cout << "method1: depth is " << pDepth[middleIndex] << endl;
            ////cout << "method2: depth is " << *centerPixel << endl;
            ////cout << "-----------" << endl;

            //// //float wX, wY, wZ;
            ////status = CoordinateConverter::convertDepthToWorld(
            ////    mDepthStream,
            ////    (float)(mDepthFrame.getWidth() / 2),
            ////    (float)(mDepthFrame.getHeight() / 2),
            ////    (float)(*centerPixel),
            ////    &wX, &wY, &wZ);
            ////if (!HandleStatus(status)) return 1;
            ////printf("Center pixel's at distance is %gmm "
            ////    "located at %gmmx%gmm\r\n",
            ////    wZ, wX, wY);

            //// ---------------------
            //setMouseCallback("Depth Image", onMouse);
            //if (lButtonDown)
            //{
            //    // 读取鼠标点击处坐标、深度值
            //    // 采用上述方法2的原理实现
            //    DepthPixel* buttonPixel =
            //        (DepthPixel*)((char*)mDepthFrame.getData() +
            //            (p.y * mDepthFrame.getStrideInBytes())) +
            //        (p.x * mDepthFrame.getStrideInBytes() / mDepthFrame.getWidth());
            //    //cout << p.x << ", " << p.y << endl;
            //    //cout << mDepthFrame.getStrideInBytes() << endl; //640
            //    //cout << mDepthFrame.getHeight() << endl; //240
            //    //cout << mDepthFrame.getWidth() << endl; //320
            //    
            //    int dX, dY, dZ;
            //    dX = p.x;
            //    dY = p.y;
            //    dZ = *buttonPixel;
            //    float wX, wY, wZ;
            //    status = CoordinateConverter::convertDepthToWorld(
            //        mDepthStream,
            //        dX, dY, dZ,
            //        &wX, &wY, &wZ);
            //    if (!HandleStatus(status)) return 1;
            //    cout << "pixel is at " << dX << "," << dY << "," << dZ << endl;
            //    //cout << "located at " << wX << "," << wY << endl; // 目前暂不清楚x y具体表示的所在位置
            //    cout << "distance is " << wZ << "mm" << endl;
            //    //cout << *buttonPixel << endl;
            //    cout << "-----------" << endl;

            //    lButtonDown = false;
            //}
            Sleep(100);

        }

        // 6a. check keyboard
        if (cv::waitKey(1) == 'q')
            break;
    }

    // 9. stop
    mDepthStream.destroy();
    mColorStream.destroy();
    mDevice.close();
    OpenNI::shutdown();

    return 0;
}