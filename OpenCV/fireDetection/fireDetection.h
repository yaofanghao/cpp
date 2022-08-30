#pragma once
// https://github.com/opencv/opencv/blob/4.x/samples/cpp/tutorial_code/objectDetection/objectDetection.cpp
// 人脸识别级联分类器，参考opencv例程改动

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

CascadeClassifier fire_cascade;

std::vector<Point2f>  detectAndDisplay(Mat frame)
{
    // 8.19 修改
    const char* fire_cascade_name = "E:/MyGithub/Cpp/OpenCV/fireDetection/cascade.xml";
    cout << fire_cascade.load(fire_cascade_name) << endl;
    if (!fire_cascade.load(fire_cascade_name))
    {
        cout << "--(!)Error loading cascade xml \n";
        exit(0);
    };

    //fire_cascade.load(hand_cascade_name);

    //----------------------
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    std::vector<Rect> fire;
    double scaleFactor;
    int minNeighbors, flags;
    Size minSize=Size(200,200);
    fire_cascade.detectMultiScale(frame_gray, fire,
        scaleFactor=1.2, minNeighbors=5,
        flags=0, minSize);

    std::vector<Point2f>firePoint; // 创建存放中心点坐标对的vector，用作返回值

    for (size_t i = 0; i < fire.size(); i++)
    {
        Point center(fire[i].x + fire[i].width / 2, fire[i].y + fire[i].height / 2);
        ellipse(frame, center, Size(fire[i].width / 2, fire[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);
        //rectangle(frame, 
        //    Point(fire[i].x, fire[i].y), 
        //    Point(fire[i].x + fire[i].width, fire[i].y + fire[i].height),
        //    Scalar(255, 0, 255), 1, 4);

        cout << fire[i].width << endl;
        cout << fire[i].height << endl;

        cout << "Find fire!" << endl;
        firePoint.push_back(Point2f(center.x, center.y));
    }

    return firePoint;
}