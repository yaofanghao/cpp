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
	printf("\r\n---------------------- Init NiTE --------------------------\r\n");
	status = nite::NiTE::initialize();
	if (!HandleStatus(status)) return 1;

	printf("Creating user tracker ...\r\n");
	nite::UserTracker uTracker;
	status = uTracker.create();
	if (!HandleStatus(status)) return 1;

	printf("Creating hand tracker ...\r\n");
	nite::HandTracker hTracker;
	status = hTracker.create();
	if (!HandleStatus(status)) return 1;
	printf("Searching for Wave, Hand Raise and"
		" Click gestures ...\r\n");
	hTracker.startGestureDetection(nite::GESTURE_HAND_RAISE);

	printf("Reading data from hand/user trackers ...\r\n");

	while(!_kbhit())
	{
		nite::HandTrackerFrameRef handFrame;
		status = hTracker.readFrame(&handFrame);
		if (!HandleStatus(status) ||
			!handFrame.isValid()) return 1;
		nite::UserTrackerFrameRef userFrame;
		status = uTracker.readFrame(&userFrame);
		if (!HandleStatus(status) ||
			!userFrame.isValid()) return 1;
		nite::UserMap usersMap = userFrame.getUserMap();
		const nite::Array<nite::GestureData>& gestures =
			handFrame.getGestures();
		for (int i = 0; i < gestures.getSize(); ++i){
			if (gestures[i].isComplete()){
				nite::HandId handId;
				status = hTracker.startHandTracking(
					gestures[i].getCurrentPosition(), &handId);
			}
		}
		const nite::Array<nite::HandData>& hands = 
			handFrame.getHands();
		for (int i = 0; i < hands.getSize(); ++i){
			if (hands[i].isTracking()){
				float posX, posY;
				status = 
					hTracker.convertHandCoordinatesToDepth(
					hands[i].getPosition().x,
					hands[i].getPosition().y,
					hands[i].getPosition().z,
					&posX, &posY);
				if (status == nite::STATUS_OK)
				{
					nite::UserId* userId =
						(nite::UserId*)(
							(char*)usersMap.getPixels() + 
							((int)posY * usersMap.getStride())
						) +	(int)posX;

					printf("User %d: Hand #%d @%g,%g,%g \r\n",
						*userId, hands[i].getId(),
						hands[i].getPosition().x,
						hands[i].getPosition().y,
						hands[i].getPosition().z);
				}
			}
		}
		handFrame.release();
		userFrame.release();
	}
	
	hTracker.destroy();
	uTracker.destroy();
	nite::NiTE::shutdown();
	return 0;
}

