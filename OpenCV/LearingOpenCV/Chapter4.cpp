#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ͼ�������֪ʶ-3 ������״������
int main() {
    Mat img(512, 512, CV_8UC3, Scalar(255,255,255)); // ����ָ����ɫ��һ��ͼ��
 
    circle(img, Point(256, 256), 100, Scalar(0, 0, 0), 10); // ��img�ϻ�Բ
    rectangle(img, Point(130, 256), Point(382, 286), Scalar(0, 0, 255),3); // ��img�ϻ�����
    line(img, Point(160, 296), Point(382, 296), Scalar(255, 0, 255), 2); // ��img�ϻ���
    putText(img, "this is a test", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 0, 0), 1); // ��img��д��

    imshow("image", img);
    waitKey(0);
}
