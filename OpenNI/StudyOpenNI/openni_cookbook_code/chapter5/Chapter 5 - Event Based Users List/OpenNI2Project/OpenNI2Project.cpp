t// OpenNI2Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// General headers
#include <stdio.h>
#include <conio.h>
// OpenNI2 headers
#include <OpenNI.h> 
using namespace openni;
// NITE2 headers
#include <NiTE.h> 

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

bool HandleStatus(nite::Status status)
{
	if (status == nite::STATUS_OK)
		return true;
	printf("ERROR: #%d, %s", status,
		openni::OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}

struct uTrackerNewFrameListener :
	public nite::UserTracker::Listener
{
    void onNewFrame(nite::UserTracker& utracker)
    {
		nite::Status status = nite::STATUS_OK;
		nite::UserTrackerFrameRef newFrame;
		status = utracker.readFrame(&newFrame);
		if (!HandleStatus(status) || !newFrame.isValid()) return;
		system("cls");
		const nite::Array<nite::UserData>& users = newFrame.getUsers();
		for (int i = 0; i < users.getSize(); ++i)
		{
			printf("User #%d %s \r\n",
				users[i].getId(), 
				(users[i].isVisible()) ? "is Visible" : "is not Visible");
		}
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	nite::Status status = nite::STATUS_OK;
	printf("Initializing NiTE ...\r\n");
	status = nite::NiTE::initialize();
	if (!HandleStatus(status)) return 1;
	printf("Done\r\n");

	printf("Creating user tracker ...\r\n");
	nite::UserTracker utracker;
	status = utracker.create();
	if (!HandleStatus(status)) return 1;
	uTrackerNewFrameListener listener;
	utracker.addListener(&listener);

	printf("Reading data from user tracker ...\r\n");

	ReadLastCharOfLine();

	utracker.destroy();
	nite::NiTE::shutdown();
	return 0;
}

