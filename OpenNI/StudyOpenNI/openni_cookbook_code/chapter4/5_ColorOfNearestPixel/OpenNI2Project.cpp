// OpenNI2Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// General headers
#include <stdio.h>
// OpenNI2 headers
#include <OpenNI.h> 
#include <conio.h>
using namespace openni;

char ReadLastCharOfLine()
{
	int newChar = 0;
	int lastChar;
	fflush(stdout);
	do 
	{
		lastChar = newChar;
		newChar = getchar();
	}
	while ((newChar != '\n') 
		&& (newChar != EOF));
	return (char)lastChar;
}

bool HandleStatus(Status status)
{
	if (status == STATUS_OK)
		return true;
	printf("ERROR: #%d, %s", status,
		OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Status status = STATUS_OK;
	printf("\r\n---------------------- Init OpenNI --------------------------\r\n");
	printf("Scanning machine for devices and loading "
			"modules/drivers ...\r\n");
	
	status = OpenNI::initialize();
	if (!HandleStatus(status)) return 1;
	printf("Completed.\r\n");

	printf("\r\n---------------------- Open Device --------------------------\r\n");
	printf("Opening first device ...\r\n");
	Device device;
	status = device.open(ANY_DEVICE);
	if (!HandleStatus(status)) return 1;
	printf("%s Opened, Completed.\r\n",
		device.getDeviceInfo().getName());

	printf("\r\n---------------------- Depth Stream --------------------------\r\n");
	printf("Checking if stream is supported ...\r\n");
	if (!device.hasSensor(SENSOR_DEPTH))
	{
		printf("Stream not supported by this device.\r\n");
		return 1;
	}
	VideoStream depthSensor;
	printf("Asking device to create a depth stream ...\r\n");
	status = depthSensor.create(device, SENSOR_DEPTH);
	if (!HandleStatus(status)) return 1;

	printf("Setting video mode to 640x480x30 Depth 1MM ...\r\n");
	VideoMode vmod;
	vmod.setFps(30);
	vmod.setPixelFormat(PIXEL_FORMAT_DEPTH_1_MM);
	vmod.setResolution(640, 480);
	status = depthSensor.setVideoMode(vmod);
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Starting stream ...\r\n");
	status = depthSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- Image Stream --------------------------\r\n");
	printf("Checking if stream is supported ...\r\n");
	if (!device.hasSensor(SENSOR_COLOR))
	{
		printf("Stream not supported by this device.\r\n");
		return 1;
	}
	VideoStream colorSensor;
	printf("Asking device to create a color stream ...\r\n");
	status = colorSensor.create(device, SENSOR_COLOR);
	if (!HandleStatus(status)) return 1;

	printf("Setting video mode to 640x480x30 RGB ...\r\n");
	vmod.setFps(30);
	vmod.setPixelFormat(PIXEL_FORMAT_RGB888);
	vmod.setResolution(640, 480);
	status = colorSensor.setVideoMode(vmod);
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Starting stream ...\r\n");
	status = colorSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- Reading Data -------------------------\r\n");
	printf("Enabling Frame Sync ...\r\n");
	//status = device.setDepthColorSyncEnabled(true);
	if (!HandleStatus(status)) return 1;
	printf("Press any key to exit ...\r\n");
	while (true)
	{
		if (kbhit())
			break;
		VideoFrameRef depthFrame, colorFrame;
		status = depthSensor.readFrame(&depthFrame);
		if (status == STATUS_OK && depthFrame.isValid())
		{
			int nearDepthX, nearDepthY;
			DepthPixel nearDepth =
				depthSensor.getMinPixelValue();
			for	(int y = 0; y < depthFrame.getHeight(); ++y)
			{
				DepthPixel* depthCell = (DepthPixel*)(
					(char*)depthFrame.getData() + 
					(y * depthFrame.getStrideInBytes())
					);
				for	(int x = 0; x < depthFrame.getWidth();
					++x, ++depthCell)
					if (nearDepth < *depthCell)
					{
						nearDepth = *depthCell;
						nearDepthX = x;
						nearDepthY = y;
					}
			}

			status = colorSensor.readFrame(&colorFrame);
			if (status == STATUS_OK && colorFrame.isValid() && nearDepth > 0)
			{
				int cX, cY;
				status = CoordinateConverter::convertDepthToColor(
							depthSensor,
							colorSensor,
							nearDepthX,
							nearDepthY,
							nearDepth,
							&cX, &cY);
				if (status == STATUS_OK){
					RGB888Pixel* nearColorPixel = (RGB888Pixel*)(
						(char*)colorFrame.getData() + 
						(cY  * colorFrame.getStrideInBytes())) + (cX);
					printf("Nearest Pixel's color is %d,%d,%d\r\n",
						nearColorPixel->r,
						nearColorPixel->g,
						nearColorPixel->b);
				}
			}
		}
		Sleep(100);
	}
	depthSensor.destroy();
	OpenNI::shutdown();
	return 0;
}

