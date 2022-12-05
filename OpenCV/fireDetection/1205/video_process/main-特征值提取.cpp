#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <iostream>
#include <opencv2/highgui/highgui_c.h>
#include <string.h>
#include <numeric>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <ctime>
#include "easylogging++.h"
//#include "WzSerialPort.h"

#define _CRT_SECURE_NO_WARNINGS 1
INITIALIZE_EASYLOGGINGPP
using namespace el;
using namespace cv;
using namespace std;

// general settings
std::string video_name = "205.mp4";
std::string csv_name = "205.csv";
int area_low = 300;
int hl = 0, hh = 80, sl = 0, sh = 80, vl = 250, vh = 255;

//long long flag = 5000000;  // 抽帧处理参数
int receive_preiod = 1; //  每间隔recieve_preiod*flag 
int ellipse_low = 5; // There should be at least 5 points to fit the ellipse
double fps = 25.0;
std::vector<double> processing_result; // 存放每帧图片图片后的特征值（圆形度、偏心率、熵）的容器

int kernal_size = 1;
double round_low = 0;
int cntlen_low = 0;

static void help(char* progName) {
	cout << "Usage:" << endl
		<< progName << "[mode - c / v / i ]" << "[save_path -- default out.mp4]" << endl;
}

Mat imgopen(Mat mask, int kernal_size) {
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}

// caculate entropy for a gray image
//https://github.com/arnaudgelas/OpenCVExamples/blob/master/cvMat/Statistics/Entropy/Entropy.cpp
cv::Scalar Entropy(cv::Mat image) {
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
	for (int i = 0; i < histSize; i++) {
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

	for (int i = 0; i < histSize; i++) {
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
// return processing_result vector
std::vector<double> processing(Mat frame) {
	Mat img1, hsv, mask;
	std::vector<double> processing_result;  // 存放每帧图片图片后的特征值（圆形度、偏心率、熵）的容器
	std::vector<double> area_result;
	std::vector<double> length_result;
	std::vector<double> roundIndex_result;
	std::vector<double> eccIndex_result;
	std::vector<double> entropy_result;
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
			&& (length > cntlen_low) && (contours[i].size() > ellipse_low)) {
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

			area_result.push_back(area);
			length_result.push_back(length);
			roundIndex_result.push_back(roundIndex);
			eccIndex_result.push_back(eccIndex);
			entropy_result.push_back(ent.val[0]);
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

	// calculate average of roundindex, eccindex, entropy
	double mean_area = 0.0;
	double mean_length = 0.0;
	double mean_roundIndex = 0.0;
	double mean_eccIndex = 0.0;
	double mean_entropy = 0.0;
	if (!area_result.empty()) { mean_area = 0.0; }
	if (!length_result.empty()) { mean_length = 0.0; }
	if (!roundIndex_result.empty()) { mean_roundIndex = 0.0; }
	if (!eccIndex_result.empty()) { mean_eccIndex = 0.0; }
	if (!entropy_result.empty()) { mean_entropy = 0.0; }
	if (!roundIndex_result.empty() && !eccIndex_result.empty() && !entropy_result.empty())
	{
		double sum_area = accumulate(begin(area_result), end(area_result), 0.0);
		mean_area = sum_area / area_result.size();
		double sum_length = accumulate(begin(length_result), end(length_result), 0.0);
		mean_length = sum_length / length_result.size();
		double sum_roundIndex = accumulate(begin(roundIndex_result), end(roundIndex_result), 0.0);
		mean_roundIndex = sum_roundIndex / roundIndex_result.size();
		double sum_eccIndex = accumulate(begin(eccIndex_result), end(eccIndex_result), 0.0);
		mean_eccIndex = sum_eccIndex / eccIndex_result.size();
		double sum_entropy = accumulate(begin(entropy_result), end(entropy_result), 0.0);
		mean_entropy = sum_entropy / entropy_result.size();
	}
	processing_result.push_back(mean_area);
	processing_result.push_back(mean_length);
	processing_result.push_back(mean_roundIndex);
	processing_result.push_back(mean_eccIndex);
	processing_result.push_back(mean_entropy);
	//LOG(INFO) << "mean-area:" << mean_area 
	//<< "-length:" << mean_length << "-roundIndex:" << mean_roundIndex 
	//<< "-eccIndex:" << mean_eccIndex << "-entropy:" << mean_entropy;	
	cv::namedWindow("result", WINDOW_NORMAL);
	cv::imshow("result", frame);
	return processing_result;
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
	oFile.open(csv_name, ios::out | ios::trunc);
	oFile << "-area:" << "," << "-length:" << ","
		<< "-roundIndex:" << "," << "-eccIndex:" << ","
		<< "-entropy:" << endl;

	LOG(INFO) << "Start fire detect!";

	// camera detection
	VideoCapture capture(video_name);
	//double fps = capture.get(CAP_PROP_FRAME_COUNT);
	if (!capture.isOpened()) {
		cerr << "camera not open!" << endl;
		return -1;
	}
	int frame_num = 0;  // caculate number of frame
	while (1)
	{
		frame_num++;

		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;

		// (frame_num % (receive_preiod * flag) == 0)
		std::vector<double> processing_result = processing(frame);
		cout << "mean area, length, roundIndex, eccIndex, entropy is: ";
		for (auto i : processing_result) {
			cout << i << " ";
		}

		oFile << processing_result[0] << "," << processing_result[1] << ","
			<< processing_result[2] << "," << processing_result[3] << ","
			<< processing_result[4] << endl;

		cout << "success write to excel" << endl;
		cout << "-----------------------------------------" << endl;
		if (!capture.read(frame)) {
			cout << "detection done!" << endl;
			break;
		}
		int c = waitKey(50);
		if (c == 27) break;

	}
	oFile.close();
	return 0;
}
