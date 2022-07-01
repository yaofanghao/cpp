#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// 读取图片并显示
//int main(){
//    string path = "resources/test.png";
//    Mat img = imread(path);
//    imshow("image", img);
//    waitKey(0);
//}

// 读取视频并显示
//int main() {
//
//    string path = "resources/test_video.mp4";
//    VideoCapture cap(path);
//    Mat img;
//
//    while (true) {
//        cap.read(img);
//        imshow("image", img);
//        waitKey(10); // 按帧读取图片速度1ms
//    } 
//}

// 读取电脑摄像头并显示
int main() {

    VideoCapture cap(0); // 如果有多个摄像头可以输入1,2...
    Mat img;

    while (true) {
        cap.read(img);
        imshow("image", img);
        waitKey(10); // 按帧读取图片速度1ms
    }
}