// 只录视频，不作任何处理，查看速度
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <iostream>
#include <string.h>
#include <opencv2/highgui/highgui_c.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

double fps = 25.0;
int CapWidth = 800;
int CapHeight = 600;


int main(int argc, char** argv)
{
	// camera detection
	VideoCapture capture;
	capture.open(0); // choose camera index -0/1
	capture.set(CAP_PROP_FRAME_WIDTH, CapWidth);
	capture.set(CAP_PROP_FRAME_HEIGHT, CapHeight);
	//double fps = capture.get(CAP_PROP_FRAME_COUNT);
	cout << "width: " << int(capture.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "height: " << int(capture.get(CAP_PROP_FRAME_HEIGHT)) << endl;

	if (!capture.isOpened()){
		cerr << "camera not open!" << endl;
		return -1;
	}
	
	VideoWriter writer;
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
	string save_path = "out001.avi";
	writer.open(save_path, codec, fps, size, true);
		
	while (1){
		Mat frame;
		capture >> frame;
		if (frame.empty())
			break;		

		// image process			
		cv::namedWindow("origin", WINDOW_NORMAL);
		cv::imshow("origin", frame);

		writer.write(frame);
		if (!writer.isOpened()) {
			cerr << "failed to open the video" << endl;
			return -1;
		}
		// if (!capture.read(frame)) {
		// 	cout << "detection done!" << endl;
		// 	break;
		// }
		int c = waitKey(50);
		if (c == 27) break;
	}

	cout << "stop read video" << endl;

	writer.release();
	return 0;
}
