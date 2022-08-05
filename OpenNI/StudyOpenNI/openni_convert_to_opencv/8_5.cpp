#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <OpenNI.h>

using namespace std;
using namespace cv;
using namespace openni;

int WINDOW_WIDTH = 320;
int WINDOW_HEIGHT = 240;

int main(int argc, char** argv)
{
    // 1. Initial OpenNI
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
            mMode.setFps(30);
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
            mMode.setFps(30);
            mMode.setPixelFormat(PIXEL_FORMAT_RGB888);

            if (mColorStream.setVideoMode(mMode) != STATUS_OK)
            {
                cout << "Can't apply VideoMode: "
                    << OpenNI::getExtendedError() << endl;
            }

            // 4b. image registration
            if (mDevice.isImageRegistrationModeSupported(
                IMAGE_REGISTRATION_DEPTH_TO_COLOR))
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
                const cv::Mat mImageRGB(
                    mColorFrame.getHeight(), mColorFrame.getWidth(),
                    CV_8UC3, (void*)mColorFrame.getData());
                // 7c. convert form RGB to BGR
                cv::Mat cImageBGR;
                //cv::cvtColor(mImageRGB, cImageBGR, cv::COLOR_RGB2BGR);
                cv::cvtColor(mImageRGB, cImageBGR, cv::COLOR_RGB2GRAY);
                // 7d. show image

                Mat cannyout;
                cv::Canny(cImageBGR, cImageBGR, 50, 200, 3);

                cv::imshow("Color Image", cImageBGR);
            }
        }

        // 8a. get depth frame
        if (mDepthStream.readFrame(&mDepthFrame) == STATUS_OK)
        {
            // 8b. convert data to OpenCV format
            const cv::Mat mImageDepth(
                mDepthFrame.getHeight(), mDepthFrame.getWidth(),
                CV_16UC1, (void*)mDepthFrame.getData());
            // 8c. re-map depth data [0,Max] to [0,255]
            cv::Mat mScaledDepth;
            mImageDepth.convertTo(mScaledDepth, CV_8U, 255.0 / iMaxDepth);
            // 8d. show image
            cv::imshow("Depth Image", mScaledDepth);
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