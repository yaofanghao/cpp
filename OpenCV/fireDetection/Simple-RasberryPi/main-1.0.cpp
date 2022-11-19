#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <iostream>
#include <opencv2/highgui/highgui_c.h>
#include "easylogging++.h"

#define _CRT_SECURE_NO_WARNINGS 1
INITIALIZE_EASYLOGGINGPP
using namespace el;
using namespace cv;
using namespace std;

// settings
double fps = 25.0;
int CapWidth = 1280;
int CapHeight = 960;

// 11.1-night fire
int hl = 0, hh = 50, sl = 0, sh = 80, vl = 250, vh = 255; // range of hsv
int kernal_size = 3; // open kernal size
double contours_ratio = 0.001; // ratio = contours / area
double round_low = 0.2; // round of coutours
int cntlen_low = 10; // length of coutours

// 7.1-day fire
//int hl = 0, hh = 50, sl = 100, sh = 255, vl = 200, vh = 255; 
//int kernal_size = 5; 
//double conturs_ratio = 0.000005; 
//double round_low = 0.2;
//int cntlen_low = 100;

Mat imgopen(Mat mask, int kernal_size);
void processing(Mat frame);

static void help(char* progName) {
	cout << endl
		<< "Usage:" << endl
		<< progName << "[mode - c / v ]" << "[save_path -- default out.mp4]" << endl;
}

int main(int argc, char** argv) 
{
	help(argv[0]);

	// log setting
 	// https://github.com/amrayn/easyloggingpp
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	el::Loggers::reconfigureLogger("default", defaultConf);
	el::Logger* defaultLogger = el::Loggers::getLogger("default");

	//if (argc < 2) {
	//	cout << "please enter mode" 
	//		<< " [mode -- c / v]" 			
	//		<< endl;
	//	return -1;
	//}

	char answer = 0;
	cout << "please enter the detect mode [c -camera / v -video]" << endl;
	cin >> answer;
	switch (answer) 
	{
		//LOG(INFO) << "Start fire detect!";		
		// camera detection
		case 'c':
		{
			VideoCapture capture;
			capture.open(0); // choose camera index - 1 for usb camera
			capture.set(CAP_PROP_FRAME_WIDTH, CapWidth);
			capture.set(CAP_PROP_FRAME_HEIGHT, CapHeight);			
			if (!capture.isOpened()) {
				cerr << "camera not open!" << endl;
				return -1;
			}			
			cout << "fps:" << fps << endl;
			cout << "width:" << int(capture.get(CAP_PROP_FRAME_WIDTH)) << endl;
			cout << "height:" << int(capture.get(CAP_PROP_FRAME_HEIGHT)) << endl;			
			VideoWriter writer;			
			int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
			Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
			string save_path = "out.avi";
			writer.open(save_path, codec, fps, size, true);	

			while (1)
			{
				Mat frame;
				capture >> frame;
				if (frame.empty())
					break;

				processing(frame);

				writer.write(frame);
				if (!writer.isOpened()) {
					cerr << "failed to open the video" << endl;
					return -1;
				}
				if (!capture.read(frame)) {
					cout << "detection done!" << endl;
					break;
				}
				int c = waitKey(50);
				if (c == 27) break;
			}
			writer.release();
			return 0;
		}
		
		// video detection		
		case 'v':
		{
			VideoCapture capture("day.mp4"); // day.mp4 as example
			VideoWriter writer;
			int codec = VideoWriter::fourcc('m', 'p', '4', 'v');
			Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
			string save_path = ("out.avi");
			writer.open(save_path, codec, fps, size, true);
			Size dsize = Size(800, 450); // resize image for processing faster
			while (1)
			{
				Mat frame;
				capture >> frame;
				if (frame.empty())
					break;

				resize(frame, frame, dsize, 0, 0, INTER_AREA);			
				processing(frame);

				writer.write(frame);
				if (!writer.isOpened()) {
					cout << "failed to open the video" << endl;
					return -1;
				}
				if (!capture.read(frame)) {
					cout << "detection done!" << endl;
					break;
				}
				int c = waitKey(50);
				if (c == 27) break;
			}
			writer.release();
			return 0;
		}
		
		// more functions : cascade classification -- see in fireCascade.cpp
		case 'e':{
			cerr << "Using opencv-cascade detection method. Not finished yet." << endl;
			return -1;
		}
		default:{
			cerr << "please enter the correct mode [c / v]" << endl;
			return -1;
		}
	}
	return 0;
}

Mat imgopen(Mat mask, int kernal_size)
{
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}

void processing(Mat frame)
{
	Mat img1, hsv, mask;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(frame, img1, kernel);
	cv::cvtColor(img1, hsv, CV_BGR2HSV);
	Scalar lower(hl, sl, vl);
	Scalar upper(hh, sh, vh);
	cv::inRange(hsv, lower, upper, mask);

	mask = imgopen(mask, kernal_size);
	cv::namedWindow("show_hsv", WINDOW_NORMAL);
	cv::imshow("show_hsv", mask);
	
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	cv::findContours(mask, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
	cv::drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);
	int image_area = frame.rows * frame.cols;
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		double length = arcLength(contours[i], true);
		double roundIndex = 4 * 3.1415926 * area / (length * length + 0.00001);
		if ((area > contours_ratio * image_area) && (roundIndex > round_low) && (length > cntlen_low))
		{
			Rect rect = boundingRect(contours[i]);
			rectangle(frame, rect, (255, 0, 0), 5);
			string text = "Warning!";
			cv::Point origin;
			origin.x = frame.cols / 2;
			origin.y = frame.rows / 2;
			putText(frame, text, origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);			
			LOG(INFO) << "Find fire." << "-area:" << area << "-length:" << length << "-roundIndex:" << roundIndex;	
		}
		//else {
		//	LOG(INFO) << "No fire.";
		//}
	}
	cv::namedWindow("result", WINDOW_NORMAL);
	cv::imshow("result", frame);
}
	
