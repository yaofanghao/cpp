#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// 图像处理基本知识-3 绘制形状和文字
int main() {
    Mat img(512, 512, CV_8UC3, Scalar(255,255,255)); // 创建指定颜色的一块图像
 
    circle(img, Point(256, 256), 100, Scalar(0, 0, 0), 10); // 在img上画圆
    rectangle(img, Point(130, 256), Point(382, 286), Scalar(0, 0, 255),3); // 在img上画矩形
    line(img, Point(160, 296), Point(382, 296), Scalar(255, 0, 255), 2); // 在img上画线
    putText(img, "this is a test", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 0, 0), 1); // 在img上写字

    imshow("image", img);
    waitKey(0);
}
