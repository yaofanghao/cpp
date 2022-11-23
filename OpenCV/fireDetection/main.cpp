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

// general settings
double fps = 25.0;
int CapWidth = 1280;
int CapHeight = 960;
int ellipse_low = 5; // There should be at least 5 points to fit the ellipse

// 11.1-night fire
//int hl = 0, hh = 50, sl = 0, sh = 80, vl = 250, vh = 255; // range of hsv
//int kernal_size = 3; // open kernal size
//double contours_ratio = 0; // ratio = contours / area
//double round_low = 0.2; // round of coutours
//int cntlen_low = 10; // length of coutours

// 11.19-day fire
int hl = 0, hh = 200, sl = 0, sh = 200, vl = 250, vh = 255; 
int kernal_size = 5; 
double contours_ratio = 0; 
double round_low = 0.1;
int cntlen_low = 20;

static void help(char* progName) {
	cout << "Usage:" << endl
		 << progName << "[mode - c / v / i ]" << "[save_path -- default out.mp4]" << endl;
}

Mat imgopen(Mat mask, int kernal_size)
{
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}

// caculate entropy for a gray image
//https://github.com/arnaudgelas/OpenCVExamples/blob/master/cvMat/Statistics/Entropy/Entropy.cpp
cv::Scalar Entropy(cv::Mat image)
{
	std::vector<cv::Mat> channels;
	cv::split(image, channels);
	int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true;
	bool accumulate = false;
	cv::Mat hist0, hist1, hist2;
	cv::calcHist(&channels[0], 1, 0, cv::Mat(), hist0, 1, &histSize, &histRange, uniform, accumulate);
	cv::calcHist(&channels[1], 1, 0, cv::Mat(), hist1, 1, &histSize, &histRange, uniform, accumulate);
	cv::calcHist(&channels[2], 1, 0, cv::Mat(), hist2, 1, &histSize, &histRange, uniform, accumulate);

	//frequency
	float f0 = 0, f1 = 0, f2 = 0;
	for (int i = 0; i < histSize; i++){
		f0 += hist0.at<float>(i);
		f1 += hist1.at<float>(i);
		f2 += hist2.at<float>(i);	
	}

	//entropy
	cv::Scalar e;
	e.val[0] = 0;
	e.val[1] = 0;
	e.val[2] = 0;
	// e0=0, e1=0, e2=0;
	float p0, p1, p2;

	for (int i = 0; i < histSize; i++){
		p0 = abs(hist0.at<float>(i)) / f0;
		p1 = abs(hist1.at<float>(i)) / f1;
		p2 = abs(hist2.at<float>(i)) / f2;
		if (p0 != 0)
			e.val[0] += -p0 * log10(p0);
		if (p1 != 0)
			e.val[1] += -p1 * log10(p1);
		if (p2 != 0)
			e.val[2] += -p2 * log10(p2);
	}
	return e;
}

// main processing program for image
void processing(Mat frame, ofstream &oFile)
{
	Mat img1, hsv, mask;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	
	//entropy -2022.11.23
	cv::Scalar ent = Entropy(frame);

	dilate(frame, img1, kernel);
	cv::cvtColor(img1, hsv, CV_BGR2HSV);
	Scalar lower(hl, sl, vl);
	Scalar upper(hh, sh, vh);
	cv::inRange(hsv, lower, upper, mask);
	mask = imgopen(mask, kernal_size);
	//cv::namedWindow("show_hsv", WINDOW_NORMAL);
	//cv::imshow("show_hsv", mask);

	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	cv::findContours(mask, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
	// cv::drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);
	int image_area = frame.rows * frame.cols;
	for (int i = 0; i < contours.size(); i++)
	{
		double area = contourArea(contours[i]);
		double length = arcLength(contours[i], true);
		double roundIndex = 4 * 3.1415926 * area / (length * length + 0.00001);

		if ((area > contours_ratio * image_area) && (roundIndex > round_low) 
			&& (length > cntlen_low) && (contours[i].size() > ellipse_low)){		
			Rect rect = boundingRect(contours[i]);
			rectangle(frame, rect, (255, 0, 0), 5);
			
			RotatedRect box = fitEllipse(contours[i]);
			double ellipseA = box.size.height;
			double ellipseB = box.size.width;
			double eccIndex = sqrt(abs(pow(ellipseA, 2) - pow(ellipseB, 2))) / 2;  // 偏心度	
			
			string text = "Warning!";
			cv::Point origin;
			origin.x = frame.cols / 2;
			origin.y = frame.rows / 2;
			putText(frame, text, origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);
			//putText(frame, std::to_string(ent.val[0]), origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 1);
			
			//write data to excel
			oFile << area << "," << length << "," << roundIndex << "," 
				<< eccIndex << "," << ent.val[0] << endl;
			LOG(INFO) << "Find fire." << "-area:" << area 
				<< "-length:" << length << "-roundIndex:" << roundIndex 
				<< "-eccIndex:" << eccIndex << "-entropy:" << ent.val[0];
		}
		//else {
		//	LOG(INFO) << "No fire.";
		//}
	}
	cv::namedWindow("result", WINDOW_NORMAL);
	cv::imshow("result", frame);
}

int main(int argc, char** argv)
{
	help(argv[0]);

	// log setting: write to myeasylog.log
	// https://github.com/amrayn/easyloggingpp
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	el::Loggers::reconfigureLogger("default", defaultConf);
	el::Logger* defaultLogger = el::Loggers::getLogger("default");

	// ofstream setting: write data to excel
	ofstream oFile;
	oFile.open("detect_result.csv", ios::out | ios::trunc);
	oFile << "-area:" << "," << "-length:" << ","
		<< "-roundIndex:" << "," << "-eccIndex:" << ","
		<< "-entropy:" << endl;

	LOG(INFO) << "Start fire detect!";
	LOG(INFO) << "Detect result save to detect_result.csv";
	char answer = 0;
	cout << "please enter the detect mode [c -camera / v -video / i -image]" << endl;
	cin >> answer;
	switch (answer)
	{
	// camera detection
	case 'c':{
		VideoCapture capture;
		capture.open(0); // choose camera index - 1 for usb camera
		capture.set(CAP_PROP_FRAME_WIDTH, CapWidth);
		capture.set(CAP_PROP_FRAME_HEIGHT, CapHeight);
		if (!capture.isOpened()){
			cerr << "camera not open!" << endl;
			return -1;
		}
		LOG(INFO) << "fps:" << fps;
		LOG(INFO) << "width:" << int(capture.get(CAP_PROP_FRAME_WIDTH));
		LOG(INFO) << "height:" << int(capture.get(CAP_PROP_FRAME_HEIGHT));
		VideoWriter writer;
		int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
		Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
		string save_path = "out.avi";
		writer.open(save_path, codec, fps, size, true);

		while (1){
			Mat frame;
			capture >> frame;
			if (frame.empty())
				break;

			processing(frame, oFile);

			writer.write(frame);
			if (!writer.isOpened()){
				cerr << "failed to open the video" << endl;
				return -1;
			}
			if (!capture.read(frame)){
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
	case 'v':{
		VideoCapture capture("day.mp4"); // day.mp4 as example
		VideoWriter writer;
		int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
		Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
		string save_path = "out.avi";
		writer.open(save_path, codec, fps, size, true);
		Size dsize = Size(800, 450); // resize image for processing faster
		while (1)
		{
			Mat frame;
			capture >> frame;
			if (frame.empty())
				break;
			resize(frame, frame, dsize, 0, 0, INTER_AREA);
			processing(frame, oFile);
			writer.write(frame);
			if (!writer.isOpened()){
				cout << "failed to open the video" << endl;
				return -1;
			}
			if (!capture.read(frame)){
				cout << "detection done!" << endl;
				break;
			}
			int c = waitKey(50);
			if (c == 27) break;
		}
		writer.release();
		return 0;
	}

	// image detection
	case 'i':{
		Mat img = cv::imread("1.jpg");
		processing(img, oFile);
		//cv:imwrite("result.jpg", img);

		int x;
		cout << "enter 1 to exit:" ;
		cin >> x;
		if (x == 1){
			cout << "detection done!" << endl;
			return 0;
		}
	}

	// more functions : cascade classification -- see details in fireCascade.cpp
	case 'e':{
		cerr << "Using opencv-cascade detection method. Not finished yet." << endl;
		return -1;
	}

	default:{
		cerr << "please enter the correct mode [c / v / i]" << endl;
		return -1;
	}	
	
	}
	oFile.close();
	return 0;
}