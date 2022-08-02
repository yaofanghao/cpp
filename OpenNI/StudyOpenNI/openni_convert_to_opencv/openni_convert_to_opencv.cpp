#include <stdlib.h>
#include <iostream>
#include <string>
#include "OpenNI.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include <opencv2/highgui/highgui_c.h>”


using namespace std;
using namespace cv;
using namespace openni;

//该函数用于将OpenNI数据转换为OpenCV下的格式 
Mat oni2mat(VideoFrameRef& ocv);

int main()
{
	/* initialize OpenNI2 */
	Status result = OpenNI::initialize();
	if (result != STATUS_OK)
	{
		printf("Initialize failed\n%s\n", OpenNI::getExtendedError());
		return 1;
	}

	/* open device */
	Device device;
	result = device.open(ANY_DEVICE);
	if (result != STATUS_OK)
	{
		printf("Couldn't open device\n%s\n", OpenNI::getExtendedError());
		OpenNI::shutdown();
		return 2;
	}

	/* create color stream */
	VideoStream oniColorStream;
	VideoFrameRef oniColorImg;
	// set color video mode
	VideoMode modeColor;
	modeColor.setResolution(640, 480);
	modeColor.setFps(20);
	modeColor.setPixelFormat(PIXEL_FORMAT_RGB888);
	oniColorStream.setVideoMode(modeColor);
	// start color stream
	result = oniColorStream.create(device, SENSOR_COLOR);
	if (result == STATUS_OK)
	{
		result = oniColorStream.start();
		if (result != STATUS_OK)
		{
			printf("Couldn't start color stream:\n%s\n", OpenNI::getExtendedError());
			oniColorStream.destroy();
		}
	}
	else
	{
		printf("Couldn't find color stream:\n%s\n", OpenNI::getExtendedError());
	}

	/* create depth stream */
	VideoStream oniDepthStream;
	VideoFrameRef oniDepthImg;
	// set depth video mode
	VideoMode modeDepth;
	modeDepth.setResolution(640, 480);
	modeDepth.setFps(25);
	modeDepth.setPixelFormat(PIXEL_FORMAT_DEPTH_1_MM);
	oniDepthStream.setVideoMode(modeDepth);
	// start depth stream
	result = oniDepthStream.create(device, SENSOR_DEPTH);
	if (result == STATUS_OK)
	{
		result = oniDepthStream.start();
		if (result != STATUS_OK)
		{
			printf("Couldn't start depth stream:\n%s\n", OpenNI::getExtendedError());
			oniDepthStream.destroy();
		}
	}
	else
	{
		printf("Couldn't find depth stream:\n%s\n", OpenNI::getExtendedError());
	}

	char key = 0;
	//int rows = ocv.getHeight();

	while (key != 27)
	{
		// read color frame
		if (oniColorStream.readFrame(&oniColorImg) == STATUS_OK)
		{
			Mat cvRGBMat = oni2mat(oniColorImg);
			//IplImage* cvRGBImg = (&(IplImage)cvRGBMat);
			IplImage cvRGBImg = cvIplImage(cvRGBMat);
			namedWindow("RGB Image", WINDOW_NORMAL);
			//cvMoveWindow("RGB Image", 600, 100);
			imshow("RGB Image", cvRGBMat);
		}

		// read depth frame
		if (oniDepthStream.readFrame(&oniDepthImg) == STATUS_OK)
		{
			Mat cvDepthMat = oni2mat(oniDepthImg);
			Mat cvFusionMat;
			cvDepthMat.convertTo(cvFusionMat, CV_8U, 255.0 / (oniDepthStream.getMaxPixelValue()));
			cvtColor(cvFusionMat, cvFusionMat, CV_GRAY2BGR);
			//IplImage* cvDepthImg = (&(IplImage)cvFusionMat);
			IplImage cvDepthImg = cvIplImage(cvDepthMat);
			cvNamedWindow("Depth Image", CV_WINDOW_NORMAL);
			//cvMoveWindow("Depth Image", 0 , 1000);
			imshow("Depth Image", cvDepthMat);
		}

		key = waitKey(20);
	}

	//CV destroy
	cvDestroyWindow("RGB Image");
	cvDestroyWindow("Depth Image");

	//NI destroy
	oniDepthStream.destroy();
	oniColorStream.destroy();
	device.close();
	OpenNI::shutdown();

	return 0;
}

Mat oni2mat(VideoFrameRef& ocv)
{
	Mat cv_frame;
	//int rows = ocv.getHeight();
	//int cols = ocv.getWidth();

	if (ocv.getSensorType() == SENSOR_COLOR)
	{
		RGB888Pixel* dData = (RGB888Pixel*)ocv.getData();
		cv_frame = Mat(ocv.getHeight(), ocv.getWidth(), CV_8UC3, dData).clone();
		cvtColor(cv_frame, cv_frame, CV_RGB2BGR);
	}
	else if (ocv.getSensorType() == SENSOR_DEPTH)
	{
		DepthPixel* dData = (DepthPixel*)ocv.getData();
		cv_frame = Mat(ocv.getHeight(), ocv.getWidth(), CV_16UC1, dData).clone();
	}
	else
	{
		throw runtime_error("Unsupported sensor type.");
	}

	return cv_frame;
}