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
	printf("Opening any device ...\r\n");
	Device device;
	status = device.open(ANY_DEVICE);
	if (!HandleStatus(status)) return 1;
	printf("%s Opened, Completed.\r\n",
		device.getDeviceInfo().getName());

	printf("Press ENTER to continue.\r\n");
	ReadLastCharOfLine();

	printf("Checking if depth stream is supported ...\r\n");
	if (false && !device.hasSensor(SENSOR_DEPTH))
	{
		printf("Depth stream not supported by this device. "
				"Press ENTER to exit.\r\n");
		ReadLastCharOfLine();
		return 1;
	}

	printf("\r\n---------------------- Depth Stream -------------------------\r\n");
	printf("Asking device to create a depth stream ...\r\n");
	VideoStream sensor;
	status = sensor.create(device, SENSOR_DEPTH);
	if (!HandleStatus(status)) return 1;
	printf("Completed.\r\n");

	printf("Retrieving list of possible video modes for this "
				"stream ...\r\n");
	const Array<VideoMode> *supportedVideoModes =
		&(sensor.getSensorInfo().getSupportedVideoModes());
	int numOfVideoModes = supportedVideoModes->getSize();
	if (numOfVideoModes == 0)
	{
		printf("No supported video mode available, press ENTER "
					"to exit.\r\n");
		ReadLastCharOfLine();
		return 1;
	}
	
	for (int i = 0; i < numOfVideoModes; i++)
	{
		VideoMode vm = (*supportedVideoModes)[i];
		printf("%c. %dx%d at %dfps with %d format \r\n",
				'a' + i,
				vm.getResolutionX(),
				vm.getResolutionY(),
				vm.getFps(),
				vm.getPixelFormat());
	}
	printf("Completed.\r\n");

	int selected = 0;
	do
	{
		printf("Select your desired video mode and then press "
					"ENTER to continue.\r\n");
		selected = ReadLastCharOfLine() - 'a';
	} while (selected < 0 || selected >= numOfVideoModes);

	VideoMode vm = (*supportedVideoModes)[selected];
	printf("%dx%d at %dfps with %d format selected. "
				"Requesting video mode ... \r\n",
			vm.getResolutionX(),
			vm.getResolutionY(),
			vm.getFps(),
			vm.getPixelFormat());
	status = sensor.setVideoMode(vm);
	if (!HandleStatus(status)) return 1;

	printf("Accepted. Starting stream ...\r\n");
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

