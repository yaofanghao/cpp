#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ��ȡͼƬ����ʾ
//int main(){
//    string path = "resources/test.png";
//    Mat img = imread(path);
//    imshow("image", img);
//    waitKey(0);
//}

// ��ȡ��Ƶ����ʾ
//int main() {
//
//    string path = "resources/test_video.mp4";
//    VideoCapture cap(path);
//    Mat img;
//
//    while (true) {
//        cap.read(img);
//        imshow("image", img);
//        waitKey(10); // ��֡��ȡͼƬ�ٶ�1ms
//    } 
//}

// ��ȡ��������ͷ����ʾ
int main() {

    VideoCapture cap(0); // ����ж������ͷ��������1,2...
    Mat img;

    while (true) {
        cap.read(img);
        imshow("image", img);
        waitKey(10); // ��֡��ȡͼƬ�ٶ�1ms
    }
}