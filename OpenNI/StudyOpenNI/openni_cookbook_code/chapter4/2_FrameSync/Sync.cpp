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

	printf("Starting stream ...\r\n");
	status = colorSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");


	printf("\r\n---------------------- Reading Data -------------------------\r\n");
	printf("Press ESC to exit, "
		"any other key to toggle Frame Sync");
	bool sync = false;
	int avgDiff = 0;
	int framesRead = 0;
	bool canceled = false;
	while (!canceled)
	{
		if (_kbhit())
		{
			while (_kbhit())
				if (_getch() == 27)
					canceled = true;
			sync = !sync;
			status = device.setDepthColorSyncEnabled(sync);
			if (!HandleStatus(status)) return 1;
			avgDiff = 0;
			framesRead = 0;
			printf("Sync is %s\r\n", ((sync) ?
				"Activated" : "Deactivated"));
		}
		VideoFrameRef newFrame;
		status = depthSensor.readFrame(&newFrame);
		if (status == STATUS_OK &&
			newFrame.isValid())
		{
			int diff = 0;
			printf("Depth Ready at %d\r\n",
				newFrame.getTimestamp());
			diff = newFrame.getTimestamp();
			status = colorSensor.readFrame(&newFrame);
			if (status == STATUS_OK &&
				newFrame.isValid())
			{
				diff = abs(
					(int)newFrame.getTimestamp() - diff);
				avgDiff = (
					(avgDiff * framesRead) + diff) / 
					(framesRead + 1);
				framesRead++;
				printf("Color Ready at %d, "
						"Diff: %d, Avg Diff: %d\r\n",
					newFrame.getTimestamp(),
					diff, avgDiff);

			}
		}
		Sleep(100);
	}
	depthSensor.destroy();
	colorSensor.destroy();
	OpenNI::shutdown();
	return 0;
}

