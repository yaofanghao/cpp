// 2023.07.04 简化版 
// 摄像头实时火焰检测

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

#define _CRT_SECURE_NO_WARNINGS 1

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

Mat imgopen(Mat mask, int kernal_size)
{
	Mat element, maskDst;
	element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
	morphologyEx(mask, maskDst, MORPH_OPEN, element);
	return maskDst;
}

static void help(char* progName) {
	cout << endl
		<< "Usage:" << endl
		<< progName << " [save_path --default out.mp4] " << endl;
}

int main(int argc, char** argv)
{
	help(argv[0]);

	//if (argc <= 1) {
	//	cout << "please enter the save_path" << endl;
	//	return -1;
	//}

	VideoCapture capture;
	capture.open(1); // 读取摄像头
	VideoWriter writer;

	while (1)
	{
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;

		// hsv阈值分割
		Mat img1, hsv, mask;
		Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
		dilate(frame, img1, kernel);
		cvtColor(img1, hsv, CV_BGR2HSV);
		Scalar lower(hl, sl, vl);
		Scalar upper(hh, sh, vh);
		inRange(hsv, lower, upper, mask);		

		// 开运算
		mask = imgopen(mask, kernal_size);
		imshow("show_hsv", mask);

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

				cout << "Find fire.";
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
				//cout << "No fire.";
			}
		}
		cv::imshow("result", frame);

		if (!capture.read(frame)) {
			cout << "detection done!" << endl;
			break;
		}

		int c = waitKey(50);
		if (c == 27) break;
	}
	capture.release();

	return 0;
}

