// 2022.7.30 ��ѵ����ɵ�Haar����������������
// �ٷ����沿���ʾ���� https://github.com/opencv/opencv/blob/17234f82d025e3bbfbf611089637e5aa2038e7b8/samples/cpp/tutorial_code/objectDetection/objectDetection.cpp

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat srcImage = imread("1.jpg");
	Mat grayImage;


	// ���ؼ��������� ������������
	string path = "cascade.xml";
	CascadeClassifier fire_cascade(path);
	if (!fire_cascade.load(path))
	{
		printf("could not load data...\n");
		return -1;
	}

	bool a = fire_cascade.load(path);
	printf("a=%d\n",a);

	Size dsize = Size(800, 800);
	resize(srcImage, srcImage, dsize, 0, 0);

	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);	
	equalizeHist(grayImage, grayImage);


	//imshow("test", grayImage);
	//waitKey(0);

	printf("1");

	// �������
	std::vector<Rect> fire;
	


	// �������е�����һ����޷������� 2022.7.31
	//fire_cascade.detectMultiScale(grayImage, fire, 1.1, 8, 0, Size(30, 30));
	fire_cascade.detectMultiScale(srcImage, fire);
	

	printf("2");
	
	for (size_t i = 0; i < fire.size(); i++)
	{
		rectangle(srcImage, fire[i], Scalar(0, 0, 255), 2, 8, 0);
	}

	
	imshow("cascade_result", srcImage);

	printf("3");

	waitKey(0);
	destroyAllWindows();
	return 0;
}
