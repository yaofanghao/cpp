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

class MouseController :
	public nite::HandTracker::Listener
{
private:
	float startPosX, startPosY;
	int curX, curY;
	nite::HandId handId;
	RECT desktopRect;
public:
	MouseController(){
		startPosX = startPosY = -1;
		POINT curPos;
		if (GetCursorPos(&curPos)) {
			curX = curPos.x;
			curY = curPos.y;
		}else{
			curX = curY = 0;
		}
		handId = -1;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktopRect);
	}
    void onNewFrame(nite::HandTracker& hTracker)
    {
		nite::Status status = nite::STATUS_OK;
		nite::HandTrackerFrameRef newFrame;
		status = hTracker.readFrame(&newFrame);
		if (!HandleStatus(status) ||
			!newFrame.isValid()) return;
		const nite::Array<nite::GestureData>& gestures =
			newFrame.getGestures();
		for (int i = 0; i < gestures.getSize(); ++i){
			if (gestures[i].isComplete()){
				if (gestures[i].getType() == nite::GESTURE_CLICK){
					INPUT Input = {0};
					Input.type = INPUT_MOUSE;
					Input.mi.dwFlags =
						MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
					SendInput(1, &Input, sizeof(INPUT));
				}else{
					nite::HandId handId;
					status = hTracker.startHandTracking(
						gestures[i].getCurrentPosition(), &handId);
				}
			}
		}
		const nite::Array<nite::HandData>& hands =
			newFrame.getHands();
		for (int i = hands.getSize() -1 ; i >= 0 ; --i){
			if (hands[i].isTracking()){
				if (hands[i].isNew() ||
					handId != hands[i].getId()){
					status = 
						hTracker.convertHandCoordinatesToDepth(
						hands[i].getPosition().x,
						hands[i].getPosition().y,
						hands[i].getPosition().z,
						&startPosX, &startPosY);
					handId = hands[i].getId();
					if (status != nite::STATUS_OK){
						startPosX = startPosY = -1;
					}
				}else if (startPosX >= 0 && startPosY >= 0){
					float posX, posY;
					status = 
						hTracker.convertHandCoordinatesToDepth(
						hands[i].getPosition().x,
						hands[i].getPosition().y,
						hands[i].getPosition().z,
						&posX, &posY);
					if (status == nite::STATUS_OK){
						if (abs(int(posX - startPosX)) > 10)
							curX += ((posX - startPosX) - 10) / 3;
						if (abs(int(posY - startPosY)) > 10)
							curY += ((posY - startPosY) - 10) / 3;
						curX = min(curX, desktopRect.right);
						curX = max(curX, desktopRect.left);
						curY = min(curY, desktopRect.bottom);
						curY = max(curY, desktopRect.top);
						SetCursorPos(curX, curY);
					}
				}
				break;
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
	MouseController* listener = new MouseController();
	hTracker.addListener(listener);

	hTracker.startGestureDetection(nite::GESTURE_HAND_RAISE);
	hTracker.startGestureDetection(nite::GESTURE_CLICK);
	printf("Reading data from hand tracker ...\r\n");

	ReadLastCharOfLine();
	
	nite::NiTE::shutdown();
	openni::OpenNI::shutdown();
	return 0;
}

