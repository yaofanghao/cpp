// 2022.7.30 用训练完成的Haar级联分类器检测火焰

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat srcImage = imread("1.jpg");
	Mat grayImage;
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	// 加载级联分类器 创建火焰检测类
	string path = "cascade.xml";
	CascadeClassifier fire_cascade;
	if (!fire_cascade.load(path))
	{
		printf("could not load data...\n");
		return -1;
	}

	// 直方图均衡化
	equalizeHist(grayImage, grayImage);

	// 级联检测
	vector<Rect> fire;
	fire_cascade.detectMultiScale(grayImage, fire, 1.1, 2, 0, Size(3, 3));
	for (size_t i = 0; i < fire.size(); i++)
	{
		rectangle(srcImage, fire[i], Scalar(0, 0, 255), 2, 8, 0);
	}
	Size dsize = Size(800, 800);
	resize(srcImage, srcImage, dsize,0,0);
	imshow("cascade_result", srcImage);

	waitKey(0);
	return 0;
}
