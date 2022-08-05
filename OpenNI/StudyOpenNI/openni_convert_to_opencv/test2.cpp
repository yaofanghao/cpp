#include <OpenNI.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/videoio/videoio.hpp"

#include <iostream>

using namespace cv;
using namespace std;
using namespace openni;

int main() {
    cout << "opening device" << endl;

    VideoCapture sensor1;

    sensor1.open(CAP_OPENNI_ASUS);

    if (!sensor1.isOpened()) {
        cout << "CAP_OPENNI_ASUS can not open capture object " << endl;
    }

    sensor1.open(CAP_OPENNI2_ASUS);

    if (!sensor1.isOpened()) {
        cout << "CAP_OPENNI2_ASUS can not open capture object " << endl;
    }

    openni::Status rc = openni::STATUS_OK;

    openni::Device device;
    openni::VideoStream depth, color;
    //const char* deviceURI = openni::ANY_DEVICE;
    rc = openni::OpenNI::initialize();

    printf("After initialization:\n%s\n", openni::OpenNI::getExtendedError());
    
    
    //rc = device.open(deviceURI);
    rc = device.open(ANY_DEVICE);
    if (rc != openni::STATUS_OK)
    {
        printf("SimpleViewer: Device open failed:\n%s\n", openni::OpenNI::getExtendedError());
        openni::OpenNI::shutdown();
        return 1;
    }

    rc = depth.create(device, openni::SENSOR_DEPTH);
    if (rc == openni::STATUS_OK)
    {
        rc = depth.start();
        if (rc != openni::STATUS_OK)
        {
            printf("SimpleViewer: Couldn't start depth stream:\n%s\n", openni::OpenNI::getExtendedError());
            depth.destroy();
        }
    }
    else
    {
        printf("SimpleViewer: Couldn't find depth stream:\n%s\n", openni::OpenNI::getExtendedError());
    }

 /*   rc = color.create(device, openni::SENSOR_COLOR);
    if (rc == openni::STATUS_OK)
    {
        rc = color.start();
        if (rc != openni::STATUS_OK)
        {
            printf("SimpleViewer: Couldn't start color stream:\n%s\n", openni::OpenNI::getExtendedError());
            color.destroy();
        }
    }
    else
    {
        printf("SimpleViewer: Couldn't find color stream:\n%s\n", openni::OpenNI::getExtendedError());
    }

    if (!depth.isValid() || !color.isValid())
    {
        printf("SimpleViewer: No valid streams. Exiting\n");
        openni::OpenNI::shutdown();
        return 2;
    }*/

    openni::VideoMode vm = depth.getVideoMode();
    int cols, rows;
    cols = vm.getResolutionX();
    rows = vm.getResolutionY();

    openni::VideoFrameRef frame;
    depth.start();

    for (;;) {
        depth.readFrame(&frame);

        openni::DepthPixel* dData = (openni::DepthPixel*)frame.getData();
        Mat depthMat(rows, cols, CV_16UC1, dData);
        Mat depthShow;
        const float scaleFactor = 0.05f;
        depthMat.convertTo(depthShow, CV_8UC1, scaleFactor);
        //Mat depth1;

        /*if (!sensor1.grab()) {
            cout << "Sensor1 can not grab images." << endl;
            return -1;
        }

        else if (sensor1.retrieve(depthMat, CAP_OPENNI_DEPTH_MAP)) imshow("depthMat", depthMat);
        */

        if (!depthMat.empty())
        {
            imshow("depth", depthShow);
        }

        if (waitKey(30) == 27)   break;

    }

    depth.stop();

    openni::OpenNI::shutdown();
}