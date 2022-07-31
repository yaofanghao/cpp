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
	printf("Retrieving list of connected devices ...\r\n");
	openni::Array<openni::DeviceInfo> listOfDevices;
	openni::OpenNI::enumerateDevices(&listOfDevices);
	int numberOfDevices = listOfDevices.getSize();
	if (numberOfDevices > 0){
		printf("%d Device(s) are available to use.\r\n\r\n", 
			numberOfDevices);
		for (int i = 0; i < numberOfDevices; i++)
		{
			openni::DeviceInfo device = listOfDevices[i];
			printf("%c. %s->%s (VID: %d | PID: %d) is connected "
					"at %s\r\n",
				'a' + i,
				device.getVendor(),
				device.getName(),
				device.getUsbVendorId(),
				device.getUsbProductId(),
				device.getUri());
		}
	}else{
		printf("No device connected to this machine.");
	}

	int selected = 0;
	do
	{
		printf("Select your desired device and then press "
					"ENTER to continue.\r\n");
		selected = ReadLastCharOfLine() - 'a';
	} while (selected < 0 || selected >= numberOfDevices);

	DeviceInfo di = listOfDevices[selected];
	printf("%s->%s (VID: %d | PID: %d) Selected\r\n",
		di.getVendor(),
		di.getName(),
		di.getUsbVendorId(),
		di.getUsbProductId());

	printf("Opening device at %s ...\r\n", di.getUri());
	Device device;
	status = device.open(di.getUri());
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

