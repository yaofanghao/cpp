// 2023.07.03
// ˫Ŀ����ͷhbv-1780-2 s2.0 ��ʾ������������ͷ����

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/video.hpp>

using namespace cv;
using namespace std;

// ͼ������
class pre {
private:
	Mat Pic_All;                
	Mat Pic_Left;               
	Mat Pic_Right;             
public:
	pre() {}
	void devide(Mat img);   
	Mat Pic_Left_return();		
	Mat Pic_Right_return();   
	void show();           
	void Pic_Left_process();
	void Pic_Right_process();
	~pre() {}
}Pre_process;

void pre::devide(Mat img) {
	Pic_All = img.clone();
	Pic_Left = img(Rect(Point(0, 0), Point(img.cols / 2, img.rows))).clone();
	Pic_Right = img(Rect(Point(img.cols / 2, 0), Point(img.cols, img.rows))).clone();
}

Mat pre::Pic_Left_return() {
	return Pic_Left;
}

Mat pre::Pic_Right_return() {
	return Pic_Right;
}

// �������ͷ����
// ʾ������Ե���
void pre::Pic_Left_process() {
	cv::Mat edges;
	double threshold1 = 100; 
	double threshold2 = 200; 
	int apertureSize = 3;
	cv::cvtColor(Pic_Left, Pic_Left, cv::COLOR_BGR2GRAY);
	cv::Canny(Pic_Left, Pic_Left, threshold1, threshold2, apertureSize);
	cv::imshow("Edges", Pic_Left);
}

// ������Ҿ�ͷ����
// ʾ����ͼ���ֵ��
void pre::Pic_Right_process() {
	cv::Mat binary_image;
	int threshold_value = 128; 
	int max_value = 255; 	
	cv::cvtColor(Pic_Right, binary_image, cv::COLOR_BGR2GRAY); 
	cv::threshold(binary_image, Pic_Right, threshold_value, max_value, cv::THRESH_BINARY);
	cv::imshow("Binary Image", Pic_Right);
}

// ��ʾ��/��/�ܵľ�ͷͼ��
void pre::show() {
	imshow("Left", Pic_Left);
	imshow("Right", Pic_Right);
	//imshow("All", Pic_All);
}


int main() {
	// ��ʼ����
	VideoCapture cap(1);
	Mat frame;
	cap.set(CAP_PROP_FRAME_WIDTH, 1280);    
	cap.set(CAP_PROP_FRAME_HEIGHT, 360);    
	cap.set(CAP_PROP_FPS, 30);             

	while (1) {
		// ����ÿһ֡ͼ��frame
		cap >> frame;
		Pre_process.devide(frame);
		
		// -----------------------------
		// �����ʾԭͼ�񣬾Ͱ��ⲿ�ֵĴ��붼ע�͵�		
        // ����ͼ�����ں��� Pic_Left_process() �� Pic_Right_process() �б�д���룬ʵ����Ҫ�Ĺ���
		Pre_process.Pic_Left_process();
		Pre_process.Pic_Right_process();

		// -----------------------------

		Pre_process.show();

		if (cv::waitKey(1) == 'q') break;
	}

	cap.release();
	return 0;
}

