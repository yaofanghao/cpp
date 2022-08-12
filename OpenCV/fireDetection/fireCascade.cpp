// 2022.7.30 用训练完成的Haar级联分类器检测火焰
// 官方的面部检测示例： https://github.com/opencv/opencv/blob/17234f82d025e3bbfbf611089637e5aa2038e7b8/samples/cpp/tutorial_code/objectDetection/objectDetection.cpp

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/** Function Headers */
void detectAndDisplay(Mat frame);

/** Global variables */
//CascadeClassifier face_cascade;
//CascadeClassifier eyes_cascade;
CascadeClassifier fire_cascade;

/** @function main */
int main(int argc, const char** argv)
{
    //CommandLineParser parser(argc, argv,
    //    "{help h||}"
    //    "{face_cascade|data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
    //    "{eyes_cascade|data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
    //    "{camera|0|Camera device number.}");

    //parser.about("\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
    //    "You can use Haar or LBP features.\n\n");
    //parser.printMessage();

    string path = "E:/MyGithub/Cpp/OpenCV/fireDetection/cascade.xml";

    //String face_cascade_name = samples::findFile(parser.get<String>("face_cascade"));
    //String eyes_cascade_name = samples::findFile(parser.get<String>("eyes_cascade"));

    //-- 1. Load the cascades
    bool a = fire_cascade.load(path);
    printf("a=%d\n", a);
    if (!fire_cascade.load(path))
    {
        cout << "--(!)Error loading cascade\n";
        return -1;
    };


    //int camera_device = parser.get<int>("camera");
    //VideoCapture capture;
    //-- 2. Read the video stream
    //capture.open(camera_device);
    //if (!capture.isOpened())
    //{
    //    cout << "--(!)Error opening video capture\n";
    //    return -1;
    //}

    //Mat frame;
    //while (capture.read(frame))
    //{
    //    if (frame.empty())
    //    {
    //        cout << "--(!) No captured frame -- Break!\n";
    //        break;
    //    }

    //    //-- 3. Apply the classifier to the frame
    //    detectAndDisplay(frame);

    //    if (waitKey(10) == 27)
    //    {
    //        break; // escape
    //    }
    //}

    while (true)
    {
        Mat srcImage = imread("1.jpg");
        Mat grayImage;
        Size dsize = Size(800, 800);
        resize(srcImage, srcImage, dsize, 0, 0);

        printf("1");

        detectAndDisplay(srcImage);

        printf("2");

        if (waitKey(10) == 27)
        {
            break;
        }
    }


    return 0;
}

/** @function detectAndDisplay */
void detectAndDisplay(Mat frame)
{
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    //-- Detect faces
    std::vector<Rect> faces;
    fire_cascade.detectMultiScale(frame_gray, faces);

    for (size_t i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
        ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);

        Mat faceROI = frame_gray(faces[i]);

        printf("%d", i);
    }

    imshow("Capture - Face detection", frame);
}