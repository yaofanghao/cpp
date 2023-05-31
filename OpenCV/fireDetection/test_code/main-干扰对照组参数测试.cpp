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
long long flag = 1000000;  // 抽帧处理参数
double fps = 25.0;
int CapWidth = 1280;
int CapHeight = 960;
int ellipse_low = 5; // There should be at least 5 points to fit the ellipse

int area_low = 2000; // 判定面积的最小阈值 qiqiu-1000 daizi-1000 deng-? dadeng-2000 
int kernal_size = 1; 
double contours_ratio = 0; 
double round_low = 0;
int cntlen_low = 0;

std::string video_name = "101.mp4";
std::string csv_name = "10_cut.csv";
int hl = 15, hh = 80, sl = 0, sh = 100, vl = 250, vh = 255;

// 11.27 不同类别的干扰对照组的参数设置
//1、袋子
//std::string video_name = "daizi.mp4";
//std::string csv_name = "daizi.csv";
//int hl = 20, hh = 40, sl = 70, sh = 150, vl = 120, vh = 200; 

//2、灯
//std::string video_name = "deng.mp4";
//std::string csv_name = "deng.csv";
//int hl = 20, hh = 50, sl = 0, sh = 20, vl = 250, vh = 255;

//3、气球
//std::string video_name = "qiqiu.mp4";
//std::string csv_name = "qiqiu.csv";
//int hl = 20, hh = 40, sl = 50, sh = 160, vl = 130, vh = 210;

//4、大灯
//std::string video_name = "dadeng.mp4";
//std::string csv_name = "dadeng.csv";
//int hl = 0, hh = 50, sl = 0, sh = 50, vl = 250, vh = 255;

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

// main processing program for image. &oFile -- save path for csv
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
	//cv::drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);
	vector<vector<Point>>hull(contours.size());	
	
	int image_area = frame.rows * frame.cols;
	for (size_t i = 0; i < contours.size(); i++)
	{
		convexHull(contours[i], hull[i]);  	// caculate convexhull
		
		double area = contourArea(contours[i]);
		double length = arcLength(contours[i], true);
		double roundIndex = 4 * 3.1415926 * area / (length * length + 0.00001);

		if ((area > area_low) && (roundIndex > round_low) 
			&& (length > cntlen_low) && (contours[i].size() > ellipse_low)){		
			Rect rect = boundingRect(contours[i]);
			//rectangle(frame, rect, (255, 0, 0), 5);
			
			RotatedRect box = fitEllipse(contours[i]);
			double ellipseA = box.size.height;
			double ellipseB = box.size.width;
			// double eccIndex = sqrt(abs(pow(ellipseA, 2) - pow(ellipseB, 2))) / ellipseA;  // 偏心度	
			double eccIndex = (abs(ellipseA - ellipseB)) / ellipseA;  // 偏心度	

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

	// draw convexhull
	for (size_t i = 0; i < contours.size(); i++)
	{
		//drawContours(mask, contours, (int)i, Scalar(0, 0, 255));
		drawContours(frame, hull, (int)i, Scalar(255, 0, 0), 5);
	}

	cv::namedWindow("result", WINDOW_NORMAL);
	cv::imshow("result", frame);
}

int main(int argc, char** argv)
{
	// log setting: write to myeasylog.log
	// https://github.com/amrayn/easyloggingpp
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	el::Loggers::reconfigureLogger("default", defaultConf);
	el::Logger* defaultLogger = el::Loggers::getLogger("default");

	// ofstream setting: write data to excel
	ofstream oFile;
	oFile.open(csv_name, ios::out | ios::trunc);
	oFile << "-area:" << "," << "-length:" << ","
		<< "-roundIndex:" << "," << "-eccIndex:" << ","
		<< "-entropy:" << endl;

	LOG(INFO) << "Start fire detect!";
	LOG(INFO) << "Detect result save to detect_result.csv";
	LOG(INFO) << "Detect per " << flag;

	// video detection		
	VideoCapture capture(video_name);
	//VideoWriter writer;
	//int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	//int fps = capture.get(CAP_PROP_FRAME_COUNT);
	//Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
	//string save_path = "out.avi";
	//writer.open(save_path, codec, fps, size, true);
	Size dsize = Size(800, 450); // resize image for processing faster

	int frame_num = 0;  // caculate number of frame
	while (1) {
		frame_num += 1;
		if (frame_num % flag == 0) {
			Mat frame;
			capture >> frame;
			if (frame.empty())
				break;

			//cout << "detect No." << frame_num << " frame" << endl;
			resize(frame, frame, dsize, 0, 0, INTER_AREA);
			processing(frame, oFile);

			//writer.write(frame);
			//if (!writer.isOpened()) {
			//	cerr << "failed to open the video" << endl;
			//	return -1;
			//}
			if (!capture.read(frame)) {
				cout << "detection done!" << endl;
				break;
			}
			int c = waitKey(50);
			if (c == 27) break;
		}
	}
	//writer.release();
	oFile.close();
	return 0;
}