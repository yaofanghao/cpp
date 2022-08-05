// OpenNI2Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// General headers
#include <stdio.h>
#include <conio.h>
// OpenNI2 headers
#include <OpenNI.h> 
// NITE2 headers
#include <NiTE.h> 
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
		openni::OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}

bool HandleStatus(nite::Status status)
{
	return HandleStatus((openni::Status)status);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Status status = STATUS_OK;
	printf("\r\n---------------------- Init OpenNI --------------------------\r\n");
	printf("Scanning machine for devices and loading "
			"modules/drivers ...\r\n");
	
	status = openni::OpenNI::initialize();
	if (!HandleStatus(status)) return 1;
	printf("Completed.\r\n");

	printf("\r\n---------------------- Open Device --------------------------\r\n");
	printf("Opening first device ...\r\n");
	openni::Device device;
	status = device.open(openni::ANY_DEVICE);
	if (!HandleStatus(status)) return 1;
	printf("%s Opened, Completed.\r\n",
		device.getDeviceInfo().getName());

	nite::Status niStatus = nite::STATUS_OK;
	printf("\r\n---------------------- Init NiTE --------------------------\r\n");
	niStatus = nite::NiTE::initialize();
	if (!HandleStatus(niStatus)) return 1;
	printf("Done\r\n");

	printf("Creating user tracker ...\r\n");
	nite::UserTracker uTracker;
	niStatus = uTracker.create(&device);
	if (!HandleStatus(niStatus)) return 1;
	printf("Reading data from user tracker ...\r\n");
	while(!kbhit())
	{
		nite::UserTrackerFrameRef newFrame;
		niStatus = uTracker.readFrame(&newFrame);
		if (!HandleStatus(niStatus) ||
			!newFrame.isValid()) return 1;
		system("cls");
		const nite::Array<nite::UserData>& users =
			newFrame.getUsers();
		for (int i = 0; i < users.getSize(); ++i)
		{
			printf("User #%d %s \r\n",
				users[i].getId(), 
				(users[i].isVisible()) ? "is Visible" :
				"is not Visible");
		}
	}

	nite::NiTE::shutdown();
	openni::OpenNI::shutdown();
	return 0;
}

