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

bool HandleStatus(nite::Status status)
{
	if (status == nite::STATUS_OK)
		return true;
	printf("ERROR: #%d, %s", status,
		openni::OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}


int _tmain(int argc, _TCHAR* argv[])
{
	nite::Status status = nite::STATUS_OK;
	printf("\r\n---------------------- Init NiTE --------------------------\r\n");
	status = nite::NiTE::initialize();
	if (!HandleStatus(status)) return 1;

	printf("Creating user tracker ...\r\n");
	nite::UserTracker uTracker;
	status = uTracker.create();
	if (!HandleStatus(status)) return 1;
	printf("Reading data from user tracker ...\r\n");
	while(!_kbhit())
	{
		nite::UserTrackerFrameRef newFrame;
		status = uTracker.readFrame(&newFrame);
		if (!HandleStatus(status) ||
			!newFrame.isValid()) return 1;
		system("cls");
		const nite::Array<nite::UserData>& users =
			newFrame.getUsers();
		for (int i = 0; i < users.getSize(); ++i)
		{
			if (users[i].isNew()){
				uTracker.startPoseDetection(
					users[i].getId(),
					nite::POSE_PSI);
			}
			printf("User #%d %s - %s \r\n",
				users[i].getId(), 
				(users[i].isVisible()) ?
				"is Visible" :
				"is not Visible",
				(users[i].getPose(nite::POSE_PSI).isHeld()) ?
					"In PSI Pose" :	"In No Pose");
		}
	}
	uTracker.destroy();
	nite::NiTE::shutdown();
	return 0;
}
