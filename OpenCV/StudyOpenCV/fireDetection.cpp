#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <iostream>
#include <opencv2/highgui/highgui_c.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "easylogging++.h"

#define _CRT_SECURE_NO_WARNINGS 1

INITIALIZE_EASYLOGGINGPP

using namespace el;
using namespace std;
using namespace cv;


// string video_path = "1.jpg";
int hl = 0, hh = 50, sl = 100, sh = 255, vl = 200, vh = 255; // hsv阈值范围
int kernal_size = 5; // 开运算核尺寸
double conturs_ratio = 0.00001; // 轮廓参数设置
double round_low = 0.2; 
int cntlen_low = 100; 

Mat hsv_to_mask(Mat img, int hl, int hh, int sl, int sh, int vl, int vh);
Mat imgopen(Mat mask, int kernal_size);

static void help(char* progName){
	cout << endl
		 << "Usage:" << endl
		 << progName << " [video_path -- default day.mp4] [save_path -- default day_out.mp4] " << endl << endl;
}

int main(int argc, char** argv)
{
	
	help(argv[0]);

	// 配置日志信息
	// https://github.com/amrayn/easyloggingpp
	//time_t t = time(0);
	//std::stringstream ss;
	//ss << std::put_time(std::localtime(&t), "%F %X");
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	//defaultConf.setGlobally(
	//	el::ConfigurationType::Filename, ss.str());
	el::Loggers::reconfigureLogger("default", defaultConf);	
	el::Logger* defaultLogger = el::Loggers::getLogger("default");

	// 以下几句有问题，未解决
	//el::Configurations conf("myconfiguration_file");
	//el::Loggers::reconfigureLogger("default", conf);
	//el::Loggers::reconfigureAllLoggers(conf);

	LOG(INFO) << "My First Easylog!";

	if (argc<=2){
		cout<<"please enter the save_path"<<endl;
		return -1;
	}

	// VideoCapture capture(video_path);
    	
	// frame = imread(video_path);
	// frame = imread( argv[1], 1 );
	VideoCapture capture(argv[1]);
	VideoWriter writer;

	while (1)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;
		//namedWindow("Control", CV_WINDOW_AUTOSIZE);
	
		// hsv阈值分割
		//Mat mask, hsv = hsv_to_mask(frame, hl, hh, sl, sh, vl, vh);
		Mat img1, hsv, mask;
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(frame, img1, kernel);
		cvtColor(img1, hsv, CV_BGR2HSV);
		Scalar lower(hl, sl, vl);
		Scalar upper(hh, sh, vh);
		inRange(hsv, lower, upper, mask);
		//imshow("contours", mask);

		// 开运算
		mask = imgopen(mask, kernal_size);
		//imshow("contours", mask);
		
		// 融合

		// 轮廓提取
		vector<vector<Point>>contours;
		vector<Vec4i>hierarchy;
		findContours(mask, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
		drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);

		int image_area = frame.rows * frame.cols;
		for (int i = 0; i < contours.size(); i++)
		{
			double area = contourArea(contours[i]);
			double length = arcLength(contours[i], true);
			double roundIndex = 4 * 3.1415926 * area / (length*length + 0.00001);

			if ((area > conturs_ratio*image_area) && (roundIndex > round_low) && (length > cntlen_low))
			{
				Rect rect = boundingRect(contours[i]);
				rectangle(frame, rect, (255, 0, 0), 5);

				LOG(INFO) << "Find fire.";
				string text = "Warning!";
				cv::Point origin;
				origin.x = frame.cols / 2 ;
				origin.y = frame.rows / 2 ;
				putText(frame, text, origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);
				cout << "-------------" << endl;
				cout << "area:" << area << endl;
				cout << "length:" << length << endl;
				cout << "roundIndex:" << roundIndex << endl;
			}
			else {
				LOG(INFO) << "No fire.";
			}
		}

		cv::imshow("result", frame);

		int codec = VideoWriter::fourcc('m', 'p', '4', 'v');
		double fps = 25.0;
		Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
		string save_path = argv[2];
		writer.open(save_path, codec, fps, size, true);
		
		if (!writer.isOpened()){
			cout << "failed to open the video" << endl;
			return -1;
		}

		if (!capture.read(frame)){
			cout << "detection done!" << endl;
			break;
		}
		
		// writer.write(frame);
		writer << frame;

		char c = waitKey(50);
		if (c == 27) break;
	}
	
	capture.release();
	writer.release();

	return 0;
}

// 这个函数有问题，暂时不用
Mat hsv_to_mask(Mat img, int hl, int hh, int sl, int sh, int vl, int vh) 
{
	Mat mask, img1, hsv;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(img, img1, kernel);
	cvtColor(img1, hsv, CV_BGR2HSV);
	Scalar lower(hl, sl, vl);
	Scalar upper(hh, sh, vh);
	inRange(hsv, lower, upper, mask);
	return mask, hsv;
}

Mat imgopen(Mat mask, int kernal_size) 
{
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}