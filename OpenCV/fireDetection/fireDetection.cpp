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

#include "fireDetection.h"

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

static void help(char* progName) {
	//cout << endl
	//	<< "Usage:" << endl;
		//<< " [video_path --default day.mp4] [save_path --default out.mp4] " << endl << endl;
}

int main(int argc, char** argv)
{
	help(argv[0]);

	// 配置日志信息
	// https://github.com/amrayn/easyloggingpp
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	el::Loggers::reconfigureLogger("default", defaultConf);
	el::Logger* defaultLogger = el::Loggers::getLogger("default");

	LOG(INFO) << "Check video_path and save_path.";

	//if (argc <= 2) {
	//	cout << "Fail to start. Please enter the video_path and save_path!" << endl;
	//	return -1;
	//}

	// VideoCapture capture(video_path);
	// frame = imread(video_path);
	// frame = imread( argv[1], 1 );

	VideoCapture capture((argc > 1) ? argv[1] : "day.mp4");
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

		// 火焰检测示例          
		LOG(INFO) << "Detect start!";
		LOG(INFO) << "Enter esc to exit.";

		vector<Point2f> myfirePoint;
		myfirePoint = detectAndDisplay(frame);

		for (int n = 0; n < myfirePoint.size(); n++)
		{
			//cout << myfirePoint[n].x << "---" << myfirePoint[n].y << endl;
			//cout << int(myfirePoint[n].x) << "---" << int(myfirePoint[n].y) << endl;

			LOG(INFO) << "Find fire! At " << myfirePoint;

			// 已在头文件中给识别目标画圆，在这里不需要再画
			putText(frame, "warning!", myfirePoint[n], FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255));

		}
		cv::namedWindow("Fire Center", cv::WINDOW_NORMAL);
		cv::imshow("Fire Center", frame);

		if (!writer.isOpened()) {
			cout << "failed to open the video" << endl;
			return -1;
		}
		if (!capture.read(frame)) {
			cout << "detection done!" << endl;
			break;
		}

		writer << frame;

		char c = waitKey(50);
		if (c == 27) break;
	}
	capture.release();
	writer.release();

	return 0;
}


