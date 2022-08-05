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


struct hTrackerNewFrameListener :
	public nite::HandTracker::Listener
{
    void onNewFrame(nite::HandTracker& hTracker)
    {
		nite::Status status = nite::STATUS_OK;
		nite::HandTrackerFrameRef newFrame;
		status = hTracker.readFrame(&newFrame);
		if (!HandleStatus(status) ||
			!newFrame.isValid()) return;
		system("cls");
		const nite::Array<nite::GestureData>& gestures =
			newFrame.getGestures();
		for (int i = 0; i < gestures.getSize(); ++i){
			if (gestures[i].isComplete()){
				nite::HandId handId;
				status = hTracker.startHandTracking(
					gestures[i].getCurrentPosition(), &handId);
			}
		}
		const nite::Array<nite::HandData>& hands =
			newFrame.getHands();
		for (int i = 0; i < hands.getSize(); ++i){
			if (hands[i].isTracking()){
				printf("Tracking Hand #%d @ %g,%g,%g \r\n",
					hands[i].getId(),
					hands[i].getPosition().x,
					hands[i].getPosition().y,
					hands[i].getPosition().z);
			}
		}
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	nite::Status status = nite::STATUS_OK;
	printf("\r\n---------------------- Init NiTE --------------------------\r\n");
	status = nite::NiTE::initialize();
	if (!HandleStatus(status)) return 1;

	printf("Creating hand tracker ...\r\n");
	nite::HandTracker hTracker;
	status = hTracker.create();
	if (!HandleStatus(status)) return 1;
	hTrackerNewFrameListener listener;
	hTracker.addListener(&listener);

	hTracker.startGestureDetection(nite::GESTURE_CLICK);
	printf("Reading data from hand tracker ...\r\n");

	ReadLastCharOfLine();
	
	nite::NiTE::shutdown();
	openni::OpenNI::shutdown();
	return 0;
}

