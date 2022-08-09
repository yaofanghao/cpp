#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <OpenNI.h>

#include "handDetection.h"

using namespace std;
using namespace cv;
using namespace openni;

// ������ʾ����
int WINDOW_WIDTH = 600;
int WINDOW_HEIGHT = 450;
int WINDOW_FPS = 30;

// ������¼�
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
    cv::namedWindow("Depth Image", cv::WindowFlags::WINDOW_AUTOSIZE);
    cv::namedWindow("Color Image", cv::WindowFlags::WINDOW_AUTOSIZE);

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
                //cv::cvtColor(mImageRGB, cImageBGR, cv::COLOR_RGB2GRAY);
                // 7d. show image

                //cv::Canny(cImageBGR, cImageBGR, 50, 200, 3);
                cv::imshow("Color Image", cImageBGR);
                //cv::imshow("Canny Image", cImageBGR);

                // ��rgbͼ�ֲ���ⲿ��
                blur(cImageBGR, cImageBGR, cv::Size(3, 3));
                // ��ż������mat
                Mat frameDest;
                frameDest = Mat::zeros(cImageBGR.rows, cImageBGR.cols, CV_8UC3); //Returns a zero array of same size as src mat.
                // �ֲ�����ֵ��
                mySkinDetect(cImageBGR, frameDest);
                imshow("MySkinDetect", frameDest);

                // Convex Hull implementation ͹���㷨
                Mat drawing;
                myContourDetect(frameDest, drawing);

                // ��ʾ�����
                imshow("MyContour", drawing);

                if (waitKey(1) == 27)
                {
                    cout << "esc key is pressed by user" << endl;
                    break;
                }


                // -----------------
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

            openni::DepthPixel* pDepth = (DepthPixel*)mDepthFrame.getData();  // ָ��ͼ���һ�����ص�ָ��  
            //// ---------��ȡͼ��ĳ����ȵ����ַ����������ĵ�Ϊ����        
            //// ����1 ���ʸô�Ԫ��ֵ
            //int middleIndex = (mDepthFrame.getHeight() + 1) * mDepthFrame.getWidth() / 2;                  
            //// ����2 ָ��ƫ�����ô�
            //DepthPixel* centerPixel =
            //    (DepthPixel*)((char*)mDepthFrame.getData() +
            //    (mDepthFrame.getHeight() * mDepthFrame.getStrideInBytes() / 2)) + 
            //    (mDepthFrame.getWidth() / 2);
            //// ���ַ����Ա������������
            //cout << "method1: depth is " << pDepth[middleIndex] << endl;
            //cout << "method2: depth is " << *centerPixel << endl;
            //cout << "-----------" << endl;

            // //float wX, wY, wZ;
            //status = CoordinateConverter::convertDepthToWorld(
            //    mDepthStream,
            //    (float)(mDepthFrame.getWidth() / 2),
            //    (float)(mDepthFrame.getHeight() / 2),
            //    (float)(*centerPixel),
            //    &wX, &wY, &wZ);
            //if (!HandleStatus(status)) return 1;
            //printf("Center pixel's at distance is %gmm "
            //    "located at %gmmx%gmm\r\n",
            //    wZ, wX, wY);

            // ---------------------
            setMouseCallback("Depth Image", onMouse);
            if (lButtonDown)
            {
                // ��ȡ����������ꡢ���ֵ
                // ������������2��ԭ��ʵ��
                DepthPixel* buttonPixel =
                    (DepthPixel*)((char*)mDepthFrame.getData() +
                        (p.y * mDepthFrame.getStrideInBytes())) +
                    (p.x * mDepthFrame.getStrideInBytes() / mDepthFrame.getWidth());
                //cout << p.x << ", " << p.y << endl;
                //cout << mDepthFrame.getStrideInBytes() << endl; //640
                //cout << mDepthFrame.getHeight() << endl; //240
                //cout << mDepthFrame.getWidth() << endl; //320
                
                int dX, dY, dZ;
                dX = p.x;
                dY = p.y;
                dZ = *buttonPixel;
                float wX, wY, wZ;
                status = CoordinateConverter::convertDepthToWorld(
                    mDepthStream,
                    dX, dY, dZ,
                    &wX, &wY, &wZ);
                if (!HandleStatus(status)) return 1;
                cout << "pixel is at " << dX << "," << dY << "," << dZ << endl;
                //cout << "located at " << wX << "," << wY << endl; // Ŀǰ�ݲ����x y�����ʾ������λ��
                cout << "distance is " << wZ << "mm" << endl;
                //cout << *buttonPixel << endl;
                cout << "-----------" << endl;

                lButtonDown = false;
            }
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