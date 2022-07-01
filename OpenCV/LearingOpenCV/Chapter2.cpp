#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// 图像处理基本知识-1
int main(){
    string path = "resources/test.png";
    Mat img = imread(path);
    Mat imgGray,imgBlur,imgCanny, imgDil;

    cvtColor(img, imgGray, COLOR_BGR2GRAY); // 转换为灰度
    GaussianBlur(img, imgBlur, Size(3,3), 5,0); // 高斯滤波
    Canny(imgBlur, imgCanny, 50,150); // Canny边缘检测

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); // 结构元素
    dilate(imgCanny, imgDil, kernel); // 膨胀。。。。腐蚀同理，erode

    imshow("image", img);
    imshow("imageGray", imgGray);
    imshow("imageBlur", imgBlur);
    imshow("imageCanny", imgCanny);
    imshow("imageDiltaion", imgDil);
    waitKey(0);
}
