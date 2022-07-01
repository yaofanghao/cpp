#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// 扭曲图片
float w = 250, h = 350;
Mat matrix, imgWarp;

int main(){
    string path = "resources/cards.jpg";
    Mat img = imread(path);

    Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} }; 
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

    matrix = getPerspectiveTransform(src, dst); // 标定图像变换的矩阵
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    for (int i = 0; i < 4; i++) {
        circle(img, src[i], 10, Scalar(0, 0, 255), FILLED); // 在角点上画圆点
    }

    imshow("image", img);
    imshow("imageWrap", imgWarp);
    waitKey(0);
}