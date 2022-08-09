#pragma once
// https://github.com/opencv/opencv/blob/4.x/samples/cpp/tutorial_code/objectDetection/objectDetection.cpp
// ����ʶ�������������ο�opencv���̸Ķ�

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

//void detectAndDisplay(Mat frame);

/** Global variables */
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

/** @function main */
//int main(int argc, const char** argv)
//{
//    CommandLineParser parser(argc, argv,
//        "{help h||}"
//        "{face_cascade|data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
//        "{eyes_cascade|data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
//        "{camera|0|Camera device number.}");
//
//    parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
//        "You can use Haar or LBP features.\n\n");
//    parser.printMessage();
//
//    String face_cascade_name = samples::findFile(parser.get<String>("face_cascade"));
//    String eyes_cascade_name = samples::findFile(parser.get<String>("eyes_cascade"));
//
//    //-- 1. Load the cascades
//    if (!face_cascade.load(face_cascade_name))
//    {
//        cout << "--(!)Error loading face cascade\n";
//        return -1;
//    };
//    if (!eyes_cascade.load(eyes_cascade_name))
//    {
//        cout << "--(!)Error loading eyes cascade\n";
//        return -1;
//    };
//
//    int camera_device = parser.get<int>("camera");
//    VideoCapture capture;
//    //-- 2. Read the video stream
//    capture.open(camera_device);
//    if (!capture.isOpened())
//    {
//        cout << "--(!)Error opening video capture\n";
//        return -1;
//    }
//
//    Mat frame;
//    while (capture.read(frame))
//    {
//        if (frame.empty())
//        {
//            cout << "--(!) No captured frame -- Break!\n";
//            break;
//        }
//
//        //-- 3. Apply the classifier to the frame
//        detectAndDisplay(frame);
//
//        if (waitKey(10) == 27)
//        {
//            break; // escape
//        }
//    }
//    return 0;
//}

/** @function detectAndDisplay */
std::vector<Point2f>  detectAndDisplay(Mat frame)
{
    // 8.9 �޸�
    const char* face_cascade_name = "E:/OpenCV/opencv-4.5.5/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
    const char* eyes_cascade_name = "E:/OpenCV/opencv-4.5.5/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
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

    // ����xmlģ�ͽ����������
    std::vector<Rect> faces;
    face_cascade.detectMultiScale(frame_gray, faces);

    std::vector<Point2f>facePoint; // ����������ĵ�����Ե�vector

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

    //imshow("Capture - Face detection", frame); //����ע�͵���ȥmain����������ʾͼ��

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