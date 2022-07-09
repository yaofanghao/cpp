#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
int main(){
    Mat img = imread("1.jpg");
    imshow("output",img);
    waitKey(0);
    return 0;
}