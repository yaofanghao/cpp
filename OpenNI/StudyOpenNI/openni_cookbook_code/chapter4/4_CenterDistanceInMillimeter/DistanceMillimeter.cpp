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

	printf("Starting stream ...\r\n");
	status = depthSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- Reading Data -------------------------\r\n");
	printf("Press any key to exit ...\r\n");
	while (true)
	{
		if (_kbhit())
			break;
		VideoFrameRef newFrame;
		status = depthSensor.readFrame(&newFrame);
		if (status == STATUS_OK && newFrame.isValid())
		{
			DepthPixel* centerPixel = 
				(DepthPixel*)((char*)newFrame.getData() + 
				(newFrame.getHeight()  * 
					newFrame.getStrideInBytes() / 2))
				+ (newFrame.getWidth() / 2);
			float wX, wY ,wZ;
			status = CoordinateConverter::convertDepthToWorld(
				depthSensor,
				(float)(newFrame.getWidth() / 2),
				(float)(newFrame.getHeight() / 2),
				(float)(*centerPixel), 
				&wX, &wY, &wZ);  
			if (!HandleStatus(status)) return 1;
			printf("Center Pixel's distance is %gmm "
				"located at %gmmx%gmm\r\n",
				wZ, wX, wY);
		}
		Sleep(100);
	}
	depthSensor.destroy();
	OpenNI::shutdown();
	return 0;
}

