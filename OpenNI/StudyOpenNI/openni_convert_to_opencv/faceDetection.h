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

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
CascadeClassifier hand_cascade;

std::vector<Point2f>  detectAndDisplay(Mat frame)
{
    // 8.9 修改
    const char* face_cascade_name = "E:/MyGithub/Cpp/OpenNI/StudyOpenNI/openni_convert_to_opencv/xml/haarcascade_frontalface_alt.xml";
    const char* eyes_cascade_name = "E:/MyGithub/Cpp/OpenNI/StudyOpenNI/openni_convert_to_opencv/xml/haarcascade_eye_tree_eyeglasses.xml";
    //cout << face_cascade.load(face_cascade_name) << endl;
    if (!face_cascade.load(face_cascade_name))
    {
        cout << "--(!)Error loading face cascade\n";
        exit(0);
    };
    if (!eyes_cascade.load(eyes_cascade_name))
    {
        cout << "--(!)Error loading eyes cascade\n";
        exit(0);
    };
    face_cascade.load(face_cascade_name);
    eyes_cascade.load(eyes_cascade_name);

    //----------------------
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // 基于xml模型进行人脸检测
    std::vector<Rect> faces;
    face_cascade.detectMultiScale(frame_gray, faces);

    std::vector<Point2f>facePoint; // 创建存放中心点坐标对的vector

    for (size_t i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
        ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);

        cout << "Find face!" << endl;
        //cout << center << endl;
        //cout << center.x << endl;
        //cout << center.y << endl;
        facePoint.push_back(Point2f(center.x, center.y));

        Mat faceROI = frame_gray(faces[i]);

        //-- In each face, detect eyes
        std::vector<Rect> eyes;
        eyes_cascade.detectMultiScale(faceROI, eyes);

        for (size_t j = 0; j < eyes.size(); j++)
        {
            Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
            int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
            circle(frame, eye_center, radius, Scalar(255, 0, 0), 4);
        }
    }

    //imshow("Capture - Face detection", frame); //这条注释掉，去main函数里面显示图像

    //for (int n = 0; n < facePoint.size(); n++)
    //{
    //    cout << facePoint[n].x << "---" << facePoint[n].y << endl;
    //    cout << "-----" << endl;
    //}

    if (waitKey(10) == 27) // esc
    {
        exit(0);
    }
    //-------------------

    return facePoint;
}

std::vector<Point2f>  detectAndDisplayHand(Mat frame)
{
    // 8.17 修改
    const char* hand_cascade_name = "E:/MyGithub/Cpp/OpenNI/StudyOpenNI/openni_convert_to_opencv/xml/harr_fist.xml";
    // cout << hand_cascade.load(hand_cascade_name) << endl;
    if (!hand_cascade.load(hand_cascade_name))
    {
        cout << "--(!)Error loading hand cascade\n";
        exit(0);
    };

    face_cascade.load(hand_cascade_name);

    //----------------------
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // 基于xml模型进行人脸检测
    std::vector<Rect> hand;
    face_cascade.detectMultiScale(frame_gray, hand);

    std::vector<Point2f>handPoint; // 创建存放中心点坐标对的vector

    for (size_t i = 0; i < hand.size(); i++)
    {
        Point center(hand[i].x + hand[i].width / 2, hand[i].y + hand[i].height / 2);
        //ellipse(frame, center, Size(hand[i].width / 2, hand[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);
        rectangle(frame, 
            Point(hand[i].x, hand[i].y), 
            Point(hand[i].x + hand[i].width, hand[i].y + hand[i].height),
            Scalar(255, 0, 255), 1, 4);

        cout << "Find hand!" << endl;
        //cout << center << endl;
        //cout << center.x << endl;
        //cout << center.y << endl;
        handPoint.push_back(Point2f(center.x, center.y));

        //Mat handROI = frame_gray(faces[i]);

    }

    if (waitKey(10) == 27) // esc
    {
        exit(0);
    }

    return handPoint;
}