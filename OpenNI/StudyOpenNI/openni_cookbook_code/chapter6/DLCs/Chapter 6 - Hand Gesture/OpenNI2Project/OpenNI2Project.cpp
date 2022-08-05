// OpenNI2Project.cpp : Defines the entry point for the console application.
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


int _tmain(int argc, _TCHAR* argv[])
{
	nite::Status status = nite::STATUS_OK;
	printf("\r\n---------------- Init NiTE and Hand Tracker -----------------\r\n");
	status = nite::NiTE::initialize();
	if (!HandleStatus(status)) return 1;

	printf("Creating hand tracker ...\r\n");
	nite::HandTracker hTracker;
	status = hTracker.create();
	if (!HandleStatus(status)) return 1;
	printf("Searching for Wave, Hand Raise and "
		"Click gestures ...\r\n");
	hTracker.startGestureDetection(nite::GESTURE_WAVE);
	hTracker.startGestureDetection(nite::GESTURE_HAND_RAISE);
	hTracker.startGestureDetection(nite::GESTURE_CLICK);
	printf("Reading data from hand tracker ...\r\n");

	while(!_kbhit())
	{
		nite::HandTrackerFrameRef newFrame;
		status = hTracker.readFrame(&newFrame);
		if (!HandleStatus(status) ||
			!newFrame.isValid()) return 1;
		const nite::Array<nite::GestureData>& gestures =
			newFrame.getGestures();
		for (int i = 0; i < gestures.getSize(); ++i)
		{
			printf("%s Gesture Detected @ %g,%g,%g - %s \r\n",
				(gestures[i].getType() == 
				nite::GESTURE_CLICK) ? "Click" :
				((gestures[i].getType() == 
				nite::GESTURE_HAND_RAISE) ? "Hand Raise" :
				"Wave"),
				gestures[i].getCurrentPosition().x,
				gestures[i].getCurrentPosition().y,
				gestures[i].getCurrentPosition().z,
				(gestures[i].isInProgress()) ? "In Progress" : 
				((gestures[i].isComplete()) ? "Completed" :
				"Initilizing"));
		}
	}

	nite::NiTE::shutdown();
	openni::OpenNI::shutdown();
	return 0;
}

