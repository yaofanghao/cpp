#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ������ɫ��ȡɫ
Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

int main(){
    string path = "resources/shapes.png";
    Mat img = imread(path);
    cvtColor(img, imgHSV, COLOR_BGR2HSV); // ת����HSV�ռ�

    namedWindow("Trackbars"); // �������Ե���hsvֵ��trackbar
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);

    while (true) {
        Scalar lower(hmin, smin, vmin); 
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask); // ��ȡmaskd

        imshow("image", img);
        imshow("imageHSV", imgHSV);
        imshow("mask", mask);
        waitKey(1);
    }
}