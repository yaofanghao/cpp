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

	printf("Press ENTER to continue.\r\n");
	ReadLastCharOfLine();

	printf("\r\n---------------------- Open Device --------------------------\r\n");
	char* addressOfFile = "E:\\\\MyGithub\\Cpp\\OpenNI\\StudyOpenNI\\openni_cookbook_code\\chapter2\\6_OpenFileAsDeviceMultipleHands_From_OpenNIorg.oni";
	printf("Opening ONI file from %s as device ...\r\n", addressOfFile);
	Device device;
	status = device.open(addressOfFile);
	if (!HandleStatus(status)) return 1;
	printf("%s Opened, Completed.\r\n",
		device.getDeviceInfo().getName());

	printf("Press ENTER to continue.\r\n");
	ReadLastCharOfLine();
	
	printf("\r\n---------------------- Depth Stream -------------------------\r\n");
	printf("Checking if depth stream is supported ...\r\n");
	if (false && !device.hasSensor(SENSOR_DEPTH))
	{
		printf("Depth stream not supported by this device. "
				"Press ENTER to exit.\r\n");
		ReadLastCharOfLine();
		return 1;
	}

	printf("Asking device to create a depth stream ...\r\n");
	VideoStream sensor;
	status = sensor.create(device, SENSOR_DEPTH);
	if (!HandleStatus(status)) return 1;
	printf("Completed.\r\n");

	printf("Starting stream ...\r\n");
	status = sensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Completed.\r\n");

	printf("Press ENTER to exit.\r\n");
	ReadLastCharOfLine();
	sensor.destroy();
	device.close();
	OpenNI::shutdown();
	return 0;
}

