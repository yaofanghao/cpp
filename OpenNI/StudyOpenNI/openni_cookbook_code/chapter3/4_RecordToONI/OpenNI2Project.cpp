// OpenNI2Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// General headers
#include <stdio.h>
// OpenNI2 headers
#include <OpenNI.h>
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
	Device device;
	printf("Opening first device ...\r\n");
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

	printf("Asking device to create a depth stream ...\r\n");
	VideoStream depthSensor;
	status = depthSensor.create(device, SENSOR_DEPTH);
	if (!HandleStatus(status)) return 1;

	printf("Starting stream ...\r\n");
	status = depthSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- Recorder --------------------------\r\n");
	printf("Creating a recorder ...\r\n");
	Recorder recorder;
	status = recorder.create("C:\sample.oni");
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Attaching to depth sensor ...\r\n");
	status = recorder.attach(depthSensor);
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Starting recorder ...\r\n");
	status = recorder.start();
	if (!HandleStatus(status)) return 1;
	printf("Done. Now recording ...\r\n");

	ReadLastCharOfLine();
	recorder.destroy();
	depthSensor.destroy();
	device.close();
	OpenNI::shutdown();

	return 0;
}

