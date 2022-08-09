// https://github.com/Denly/hands_detection_opencv/blob/master/opencv_hands/main.cpp

/*
 *	CS440 Spring 2016
 *	Project 1
 *	--------------
 *	Huai Chun Shih 					(Sitting in) BU-ID:U28471189
 *
 *	#1.An overall description
 *	This poject detects hands and how many fingers there.
 *
 *	step1.Find contours by skin color first, and than select contours that has big area.
 *	step2.Find convex and defects by the function: convexityDefects(contours[i], hullsI[i], defects[i])
 *	step3.Select the defects having proper depths to put rectangle.
 *	step4.Indicates the unmber of fingers by valid_defects_number +1.
 *
 *	#2.How the graphics respond to different hand shapes and/or gestures
 *	it shows the text and a rectangle to indicate the hands on screen.
 *
 *	#3.Interesting and fun aspects of the graphics display
 *	All of them are fun.
 *	It is hard to distinguish hands, faces and white-yellow background.
 *	When hands contacts a face, it is hard to distinguish too.
 *	I may need one times to improve it.
 *	--------------
 */

 //#include "stdafx.h"
 //opencv libraries
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//C++ standard libraries
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

//function declarations

/**
    Function that returns the maximum of 3 integers
    @param a first integer
    @param b second integer
    @param c third integer
 */
int myMax(int a, int b, int c);

/**
    Function that returns the minimum of 3 integers
    @param a first integer
    @param b second integer
    @param c third integer
 */
int myMin(int a, int b, int c);

/**
    Function that detects whether a pixel belongs to the skin based on RGB values
    @param src The source color image
    @param dst The destination grayscale image where skin pixels are colored white and the rest are colored black
 */
void mySkinDetect(Mat& src, Mat& dst);

void myContourDetect(Mat& src, Mat& dst);

void myFindConvexDefects(Mat& src, Mat& dst, vector<vector<Point>>& contours, vector<vector<Point>>& hull, vector<vector<int>>& hullsI);


//int main()
//{
//
//    //----------------
//    //a) Reading a stream of images from a webcamera, and displaying the video
//    //----------------
//    // For more information on reading and writing video: http://docs.opencv.org/modules/highgui/doc/reading_and_writing_images_and_video.html
//    // open the video camera no. 0
//    VideoCapture cap(0);
//
//    // if not successful, exit program
//    if (!cap.isOpened())
//    {
//        cout << "Cannot open the video cam" << endl;
//        return -1;
//    }
//
//    //create a window called "MyVideo"
//    namedWindow("MySkinDetect", WINDOW_AUTOSIZE);
//    namedWindow("MyContour", WINDOW_AUTOSIZE);
//
//
//    while (1)
//    {
//        // read a new frame from video
//        Mat frame;
//        bool bSuccess = cap.read(frame);
//        //show the frame in "MyVideo" window
//        //imshow("MyVideo", frame);
//
//        //if not successful, break loop
//        if (!bSuccess)
//        {
//            cout << "Cannot read a frame from video stream" << endl;
//            break;
//        }
//
//        //Blurs image to get less noise in the image
//        blur(frame, frame, cv::Size(3, 3));
//
//        // destination frame
//        Mat frameDest;
//        frameDest = Mat::zeros(frame.rows, frame.cols, CV_8UC3); //Returns a zero array of same size as src mat.
//
//        //	Skin color detection
//        mySkinDetect(frame, frameDest);
//        imshow("MySkinDetect", frameDest);
//
//        // Convex Hull implementation
//        Mat drawing;
//        myContourDetect(frameDest, drawing);
//
//        //Show in window
//        imshow("MyContour", drawing);
//
//
//        if (waitKey(1) == 27)
//        {
//            cout << "esc key is pressed by user" << endl;
//            break;
//        }
//
//    }
//    cap.release();
//    return 0;
//}


//Function that returns the maximum of 3 integers
int myMax(int a, int b, int c) {
    return max(max(a, b), c);
}

//Function that returns the minimum of 3 integers
int myMin(int a, int b, int c) {
    return min(min(a, b), c);
}

//Function that detects whether a pixel belongs to the skin based on RGB values
void mySkinDetect(Mat& src, Mat& dst) {
    dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            Vec3b intensity = src.at<Vec3b>(i, j);
            int B = intensity[0];
            int G = intensity[1];
            int R = intensity[2];
            if (((R > 95 && B > 20 && G > 40) &&
                (myMax(R, G, B) - myMin(R, G, B) > 15) &&
                (abs(R - G) > 15) &&
                (R > G) &&
                (R > B))) {
                dst.at<uchar>(i, j) = 255;
            }
            else {
                dst.at<uchar>(i, j) = 0;
            }
        }
    }

}

//Find the contours in the foreground
void myContourDetect(Mat& src, Mat& dst) {
    Mat src_copy = src.clone();
    Mat threshold_output;
    vector<vector<Point> > contours;
    vector<vector<Point> > bigContours;
    vector<Vec4i> hierarchy;

    // Find contours
    threshold(src, threshold_output, 200, 255, THRESH_BINARY);
    findContours(threshold_output, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));

    // Find the bigConvex for each contour
    for (int i = 0; i < contours.size(); i++) {
        if (contourArea(contours[i]) > 15000) {
            bigContours.push_back(contours[i]);
        }
    }
    // Find the convex hull object for each bigConvex
    vector<vector<Point> >hull(bigContours.size());
    vector<vector<int> > hullsI(bigContours.size()); // Indices to contour points
    for (int i = 0; i < bigContours.size(); i++) {
        convexHull(Mat(bigContours[i]), hull[i], false);
        convexHull(Mat(bigContours[i]), hullsI[i], false);
    }

    // Draw bigContours + hull results
    RNG rng;
    Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
    for (int i = 0; i < bigContours.size(); i++)
    {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(drawing, bigContours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
        drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
    }

    myFindConvexDefects(drawing, drawing, bigContours, hull, hullsI);

    dst = drawing.clone();
    bigContours.clear();
    contours.clear();
    hull.clear();
    hullsI.clear();
}

//Find Convex Defect
void myFindConvexDefects(Mat& src, Mat& dst, vector<vector<Point>>& contours, vector<vector<Point>>& hull, vector<vector<int>>& hullsI) {

    vector<vector<Vec4i>> defects(contours.size());

    for (int i = 0; i < contours.size(); i++)
    {
        convexityDefects(contours[i], hullsI[i], defects[i]);
    }


    /// Draw convexityDefects
    for (int i = 0; i < contours.size(); ++i)
    {
        int validDefectCounter = 0;
        for (const Vec4i& v : defects[i])
        {
            float depth = v[3] / 256; // distance between the farthest point and the convex hull
            if (depth > 80) //  filter defects by depth, e.g more than 10
            {
                validDefectCounter++;
                int startidx = v[0]; Point ptStart(contours[i][startidx]);// point of the contour where the defect begins(finger point)
                int endidx = v[1]; Point ptEnd(contours[i][endidx]);// point of the contour where the defect ends(finger point)
                int faridx = v[2]; Point ptFar(contours[i][faridx]);// the farthest from the convex hull point within the defect

                line(src, ptStart, ptEnd, Scalar(0, 255, 0), 1);
                line(src, ptStart, ptFar, Scalar(0, 255, 0), 1);
                line(src, ptEnd, ptFar, Scalar(0, 255, 0), 1);
                circle(src, ptFar, 4, Scalar(0, 255, 0), 2);
                circle(src, ptStart, 4, Scalar(0, 0, 255), 2);
                circle(src, ptEnd, 4, Scalar(0, 0, 255), 2);


            }
        }


        //Indicate valid Defect
        if (validDefectCounter > 0 && validDefectCounter <= 4) {
            //draw rectangle for the biggest contour
            RotatedRect rect = minAreaRect(Mat(contours[i]));
            Point2f rect_points[4]; rect.points(rect_points);
            for (int j = 0; j < 4; j++)
                line(src, rect_points[j], rect_points[(j + 1) % 4], Scalar(255, 0, 0), 1, 8);
            //show text
            std::string s = std::to_string(validDefectCounter + 1);
            putText(src, s + "fingers", rect_points[2], cv::FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 255, 255));
        }


    }
}

