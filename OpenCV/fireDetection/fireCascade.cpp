// 2022.7.30 用训练完成的Haar级联分类器检测火焰
// 官方的面部检测示例： https://github.com/opencv/opencv/blob/17234f82d025e3bbfbf611089637e5aa2038e7b8/samples/cpp/tutorial_code/objectDetection/objectDetection.cpp

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

#include "fireDetection.h"

using namespace std;
using namespace cv;

/** @function main */
int main(int argc, const char** argv)
{
    //string path = "E:/MyGithub/Cpp/OpenCV/fireDetection/cascade.xml";
    ////-- 1. Load the cascades
    //bool a = fire_cascade.load(path);
    //printf("a=%d\n", a);
    //if (!fire_cascade.load(path))
    //{
    //    cout << "--(!)Error loading cascade\n";
    //    return -1;
    //};

    while (true)
    {
        Mat srcImage = imread("1.jpg");
        Size dsize = Size(800, 800);
        resize(srcImage, srcImage, dsize, 0, 0);

        printf("1");

        vector<Point2f> myfirePoint;
        myfirePoint = detectAndDisplay(srcImage);
        for (int n = 0; n < myfirePoint.size(); n++)  // 读取出火焰中心点坐标 
        {
            cout << myfirePoint[n].x << "---" << myfirePoint[n].y << endl;
            //cout << int(myFacePoint[n].x) << "---" << int(myFacePoint[n].y) << endl;
            circle(srcImage, myfirePoint[n], 5, Scalar(0, 0, 255), 2); // 给中心点画圆
            putText(srcImage, "warning!", myfirePoint[n], FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 255));
            cv::imshow("Hand Center", srcImage);
        }

        printf("2");

        if (waitKey(10) == 27)
        {
            break;
        }
    }

    return 0;
}