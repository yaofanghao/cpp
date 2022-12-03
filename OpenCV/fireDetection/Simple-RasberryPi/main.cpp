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
#include "WzSerialPort.h"

#define _CRT_SECURE_NO_WARNINGS 1
INITIALIZE_EASYLOGGINGPP
using namespace el;
using namespace cv;
using namespace std;

// general settings
long long flag = 5000000;  // 抽帧处理参数
int receive_preiod = 1; //  每间隔recieve_preiod*flag 接收一次串口的数据
double fps = 25.0;
int CapWidth = 1280;
int CapHeight = 960;
int ellipse_low = 5; // There should be at least 5 points to fit the ellipse
std::vector<double> receive_num;  // 存放从32接收到数据的容器
std::vector<double> processing_result; // 存放每帧图片图片后的特征值（圆形度、偏心率、熵）的容器

// 11.19-day fire
int hl = 0, hh = 200, sl = 0, sh = 200, vl = 250, vh = 255; 
int kernal_size = 1; 
double contours_ratio = 0; 
double round_low = 0.001;
int cntlen_low = 20;

// 11.1-night fire
//int hl = 0, hh = 50, sl = 0, sh = 80, vl = 250, vh = 255; // range of hsv
//int kernal_size = 3; // open kernal size
//double contours_ratio = 0; // ratio = contours / area
//double round_low = 0.2; // round of coutours
//int cntlen_low = 10; // length of coutours

static void help(char* progName) {
	cout << "Usage:" << endl
		 << progName << "[mode - c / v / i ]" << "[save_path -- default out.mp4]" << endl;
}

Mat imgopen(Mat mask, int kernal_size){
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}

// caculate entropy for a gray image
//https://github.com/arnaudgelas/OpenCVExamples/blob/master/cvMat/Statistics/Entropy/Entropy.cpp
cv::Scalar Entropy(cv::Mat image){
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

std::vector<double> receiveDemo() {
	WzSerialPort w;
	if (w.open("/dev/ttyS0", 115200, 0, 8, 1)){
		// w.send("helloworld ", 10);
		std::cout << "connect to STM32... wait for serial open" << std::endl;

		char buf[1024];   // buf存放接收到的数据
		std::vector<double> receive_num; // 将接收到的四个数据存放至此，格式为double
		while (true){
			memset(buf, 0, 1024);
			w.receive(buf, 1024);
			// cout << buf;
			
			char delims[] = " ";
			char* result = NULL;
			char* ptr;
			double ret;
			result = strtok(buf, delims);	// 收到的字符串按空格作为割
			int i = 0;
			while (result != NULL) {
				// printf("result is \"%s\"\n", result);
				ret = strtod(result, &ptr);
				if (typeid(ret) == typeid(double)) {
					//cout << "receive a double number: " << ret << endl;
					receive_num.push_back(ret);
					i++;
				}
				result = strtok(NULL, delims);

				if (i == 4) {
					// 读完四个数关闭串口，后续可以优化					
					cout << "success received, close serial!" << endl;
					w.close();
					return receive_num;				
				}
			}
		}
	}
	else {
		cout << "open serial port failed...";
	}
	w.close();
}

// main processing program for image
// return processing_result vector
std::vector<double> processing(Mat frame){
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
		if ((area > contours_ratio * image_area) && (roundIndex > round_low) 
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
	if(!roundIndex_result.empty()&& !eccIndex_result.empty() && !entropy_result.empty())
	{
		double sum_area = accumulate(begin(area_result), end(area_result), 0.0);
		mean_area = sum_area / area_result.size(); 
		double sum_length = accumulate(begin(length_result), end(length_result), 0.0);
		mean_length = sum_length / length_result.size();
		double sum_roundIndex = accumulate(begin(roundIndex_result), end(roundIndex_result), 0.0); 
		mean_roundIndex = sum_roundIndex / roundIndex_result.size(); // 求单张图中圆形度的均值，以下类似
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
	oFile.open("detect_result.csv", ios::out | ios::trunc);
	oFile << "-1:" << "," << "-2:" << ","  
		<< "-3:" << "," << "-4:" << ","  
		<< "-area:" << "," << "-length:" << ","
		<< "-roundIndex:" << "," << "-eccIndex:" << ","
		<< "-entropy:" << endl;

	LOG(INFO) << "Start fire detect!";
	LOG(INFO) << "Detect result save to detect_result.csv";
	LOG(INFO) << "Detect per " << flag ;
	char answer = 0;
	cout << "please enter the detect mode [c -camera / v -video / i -image]" << endl;
	cin >> answer;
	switch (answer)
	{
	// camera detection
	case 'c':{
		VideoCapture capture;
		capture.open(0); // choose camera index -0/1
		capture.set(CAP_PROP_FRAME_WIDTH, CapWidth);
		capture.set(CAP_PROP_FRAME_HEIGHT, CapHeight);
		//double fps = capture.get(CAP_PROP_FRAME_COUNT);
		if (!capture.isOpened()){
			cerr << "camera not open!" << endl;
			return -1;
		}
		LOG(INFO) << "width:" << int(capture.get(CAP_PROP_FRAME_WIDTH));
		LOG(INFO) << "height:" << int(capture.get(CAP_PROP_FRAME_HEIGHT));
		VideoWriter writer;
		int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
		Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
		string save_path = "out.avi";
		writer.open(save_path, codec, fps, size, true);

		int frame_num = 0;  // caculate number of frame
		int a =0;			
		while (1){	
			frame_num++;	
			if (frame_num % flag == 0){
				Mat frame;
				capture >> frame;
				if (frame.empty())
					break;					
				
				// image process
				clock_t t1,t2,t3;
				t1 = clock();
				cout << "image processing... total time1: " <<  1.0*t1/CLOCKS_PER_SEC << " s" << endl;				
				std::vector<double> processing_result = processing(frame);
				a++;

				// goto open serial port and receive data from STM32
				if (frame_num % (receive_preiod * flag) == 0) {
					receive_num = receiveDemo();
					t2 = clock();					
					cout << "image processing total frame: " << a << endl;
					cout << "receive data from STM32: ";
					for (auto i : receive_num) {
						cout << i << " ";
					}
					cout << endl;
					cout << "mean area, length, roundIndex, eccIndex, entropy is: ";
					for (auto i : processing_result) {
						cout << i << " ";
					}
					cout << endl;
					cout << "total time2: " <<  1.0*t2/CLOCKS_PER_SEC << " s" << endl;
					//write data to excel
					oFile << receive_num[0] << "," << receive_num[1] << ","
					<< receive_num[2] << "," << receive_num[3] << ","
					<< processing_result[0] << "," << processing_result[1] << ","
					<< processing_result[2] << "," << processing_result[3] << ","
					<< processing_result[4] << endl;	
					cout << "success write to excel" << endl;				
					cout << "-----------------------------------------" << endl;
				}

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
		}
		writer.release();
		return 0;
	}

	// video detection		
	case 'v':{
		VideoCapture capture("day.mp4"); // day.mp4 as example
		LOG(INFO) << "fps:" << fps;
		LOG(INFO) << "width:" << int(capture.get(CAP_PROP_FRAME_WIDTH));
		LOG(INFO) << "height:" << int(capture.get(CAP_PROP_FRAME_HEIGHT));
		VideoWriter writer;
		int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
		Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
		string save_path = "out001.avi";
		writer.open(save_path, codec, fps, size, true);
		// Size dsize = Size(800, 450); // resize image for processing faster
		
		int frame_num = 0;  // caculate number of frame
		int a = 0;	
		while (1){	
			frame_num++;	
			if (frame_num % flag == 0){
				Mat frame;
				capture >> frame;
				if (frame.empty())
					break;					
				
				// image process
				clock_t t1,t2,t3;
				t1 = clock();
				cout << "image processing... total time1: " <<  1.0*t1/CLOCKS_PER_SEC << " s" << endl;				
				std::vector<double> processing_result = processing(frame);
				a++;

				// goto open serial port and receive data from STM32
				if (frame_num % (receive_preiod * flag) == 0) {
					receive_num = receiveDemo();
					t2 = clock();					
					cout << "image processing total frame: " << a << endl;
					cout << "receive data from STM32: ";
					for (auto i : receive_num) {
						cout << i << " ";
					}
					cout << endl;
					cout << "mean area, length, roundIndex, eccIndex, entropy is: ";
					for (auto i : processing_result) {
						cout << i << " ";
					}
					cout << endl;
					cout << "total time2: " <<  1.0*t2/CLOCKS_PER_SEC << " s" << endl;
					//write data to excel
					oFile << receive_num[0] << "," << receive_num[1] << ","
					<< receive_num[2] << "," << receive_num[3] << ","
					<< processing_result[0] << "," << processing_result[1] << ","
					<< processing_result[2] << "," << processing_result[3] << ","
					<< processing_result[4] << endl;	
					cout << "success write to excel" << endl;				
					cout << "-----------------------------------------" << endl;
				}


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
		}
		writer.release();
		return 0;
	}

	// image detection
	case 'i':{
		Mat img = cv::imread("1.jpg");
		processing(img);
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
