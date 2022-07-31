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

struct OurOpenNIEventMonitorer : 
	public OpenNI::DeviceDisconnectedListener,
	public OpenNI::DeviceConnectedListener
{
	void onDeviceConnected(const DeviceInfo* device){
		printf("%d. %s->%s (VID: %d | PID: %d) Connected "
				"to %s\r\n",
			clock(),
			device->getVendor(),
			device->getName(),
			device->getUsbVendorId(),
			device->getUsbProductId(),
			device->getUri());
	}
	void onDeviceDisconnected(const DeviceInfo* device){
		printf("%d. %s->%s (VID: %d | PID: %d) Disconnected "
				"from %s\r\n",
			clock(),
			device->getVendor(),
			device->getName(),
			device->getUsbVendorId(),
			device->getUsbProductId(),
			device->getUri());
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Status status = STATUS_OK;
	printf("\r\n---------------------- Init OpenNI --------------------------\r\n");
	printf("Scanning machine for devices and loading "
			"modules/drivers ...\r\n");
	status = OpenNI::initialize();
	if (!HandleStatus(status)) return 1;
	printf("Completed. Adding listener ...\r\n");

	OurOpenNIEventMonitorer eventMonitorer;
	status = OpenNI::addDeviceConnectedListener(&eventMonitorer);
	if (!HandleStatus(status)) return 1;
	status = OpenNI::addDeviceDisconnectedListener(&eventMonitorer);
	if (!HandleStatus(status)) return 1;

	printf("Done. Listening to OpenNI's event, Press ENTER to exit.\r\n");
	ReadLastCharOfLine();
	return 0;
}

