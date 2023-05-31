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
using namespace cv;
using namespace std;

// 11.1-新版--晚上火焰
//int hl = 0, hh = 50, sl = 0, sh = 80, vl = 250, vh = 255; // hsv阈值范围
//int kernal_size = 3; // 开运算核尺寸
//double conturs_ratio = 0; // 轮廓参数设置
//double round_low = 0.2;
//int cntlen_low = 10;

// 原版--白天天台火焰
int hl = 0, hh = 50, sl = 100, sh = 255, vl = 200, vh = 255; // hsv阈值范围
int kernal_size = 5; // 开运算核尺寸
double conturs_ratio = 0.000005; // 轮廓参数设置
double round_low = 0.2;
int cntlen_low = 100;

Mat imgopen(Mat mask, int kernal_size);

static void help(char* progName) {
	cout << endl
		<< "Usage:" << endl
		<< progName << " [video_path --default day.mp4] [save_path --default out.mp4]" << endl;
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

	LOG(INFO) << "Start fire detect!";

	//if (argc <= 2) {
	//	cout << "please enter the video_path and save_path" << endl;
	//	return -1;
	//}

	VideoCapture capture((argc > 1) ? argv[1] : "day.mp4");

	//VideoCapture capture;
	//capture.open(0); // 读取摄像头

	VideoWriter writer;

	int codec = VideoWriter::fourcc('m', 'p', '4', 'v');
	double fps = 25.0;
	Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
	string save_path = ((argc > 2) ? argv[2] : "out.mp4");
	writer.open(save_path, codec, fps, size, true);

	while (1)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;

		//flag += 1;
		//cout << flag << endl;

		//namedWindow("Control", CV_WINDOW_AUTOSIZE);

		// 对输入图frame进行缩放，提高速度
		Size dsize = Size(800, 450);
		resize(frame, frame, dsize, 0, 0, INTER_AREA);		

		// hsv阈值分割
		Mat img1, hsv, mask;
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(frame, img1, kernel);
		cvtColor(img1, hsv, CV_BGR2HSV);
		Scalar lower(hl, sl, vl);
		Scalar upper(hh, sh, vh);
		inRange(hsv, lower, upper, mask);
		imshow("show_hsv", mask);

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
			double roundIndex = 4 * 3.1415926 * area / (length * length + 0.00001);

			if ((area > conturs_ratio * image_area) && (roundIndex > round_low) && (length > cntlen_low))
			{
				Rect rect = boundingRect(contours[i]);
				rectangle(frame, rect, (255, 0, 0), 5);

				LOG(INFO) << "Find fire.";
				string text = "Warning!";
				cv::Point origin;
				origin.x = frame.cols / 2;
				origin.y = frame.rows / 2;
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

		writer.write(frame);
		//writer << frame;

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

	capture.release();
	//writer.release();

	return 0;
}

Mat imgopen(Mat mask, int kernal_size)
{
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}