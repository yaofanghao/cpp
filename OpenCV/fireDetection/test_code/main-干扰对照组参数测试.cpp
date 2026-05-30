#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <iostream>
#include <opencv2/highgui/highgui_c.h>
#include "easylogging++.h"

#define _CRT_SECURE_NO_WARNINGS 1
INITIALIZE_EASYLOGGINGPP
using namespace el;
using namespace cv;
using namespace std;

// ===================== 参数配置 =====================
long long flag = 1000000;   // 抽帧处理参数
double fps = 25.0;
int CapWidth = 1280;
int CapHeight = 960;
int ellipse_low = 5;        // 拟合椭圆所需最少点数

int area_low = 2000;        // 判定面积的最小阈值
int kernal_size = 1;
double contours_ratio = 0;
double round_low = 0;
int cntlen_low = 0;

// 当前测试的视频和参数（默认：10号视频）
std::string video_name = "101.mp4";
std::string csv_name = "10_cut.csv";
int hl = 15, hh = 80, sl = 0, sh = 100, vl = 250, vh = 255;

Mat imgopen(Mat mask, int kernal_size)
{
    Mat element, maskDst;
    element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
    morphologyEx(mask, maskDst, MORPH_OPEN, element);
    return maskDst;
}

cv::Scalar Entropy(cv::Mat image)
{
    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    bool uniform = true;
    bool accumulate = false;
    cv::Mat hist0, hist1, hist2;
    cv::calcHist(&channels[0], 1, 0, cv::Mat(), hist0, 1, &histSize, &histRange, uniform, accumulate);
    cv::calcHist(&channels[1], 1, 0, cv::Mat(), hist1, 1, &histSize, &histRange, uniform, accumulate);
    cv::calcHist(&channels[2], 1, 0, cv::Mat(), hist2, 1, &histSize, &histRange, uniform, accumulate);

    float f0 = 0, f1 = 0, f2 = 0;
    for (int i = 0; i < histSize; i++) {
        f0 += hist0.at<float>(i);
        f1 += hist1.at<float>(i);
        f2 += hist2.at<float>(i);
    }

    cv::Scalar e;
    e.val[0] = 0; e.val[1] = 0; e.val[2] = 0;
    float p0, p1, p2;
    for (int i = 0; i < histSize; i++) {
        p0 = abs(hist0.at<float>(i)) / f0;
        p1 = abs(hist1.at<float>(i)) / f1;
        p2 = abs(hist2.at<float>(i)) / f2;
        if (p0 != 0) e.val[0] += -p0 * log10(p0);
        if (p1 != 0) e.val[1] += -p1 * log10(p1);
        if (p2 != 0) e.val[2] += -p2 * log10(p2);
    }
    return e;
}

void processing(Mat frame, ofstream &oFile)
{
    Mat img1, hsv, mask;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    cv::Scalar ent = Entropy(frame);
    dilate(frame, img1, kernel);
    cv::cvtColor(img1, hsv, CV_BGR2HSV);
    Scalar lower(hl, sl, vl);
    Scalar upper(hh, sh, vh);
    cv::inRange(hsv, lower, upper, mask);
    mask = imgopen(mask, kernal_size);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    cv::findContours(mask, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> hull(contours.size());

    int image_area = frame.rows * frame.cols;
    for (size_t i = 0; i < contours.size(); i++) {
        convexHull(contours[i], hull[i]);
        double area = contourArea(contours[i]);
        double length = arcLength(contours[i], true);
        double roundIndex = 4 * 3.1415926 * area / (length * length + 0.00001);

        if ((area > area_low) && (roundIndex > round_low)
            && (length > cntlen_low) && (contours[i].size() > ellipse_low)) {
            RotatedRect box = fitEllipse(contours[i]);
            double ellipseA = box.size.height;
            double ellipseB = box.size.width;
            double eccIndex = (abs(ellipseA - ellipseB)) / ellipseA;

            string text = "Warning!";
            cv::Point origin;
            origin.x = frame.cols / 2;
            origin.y = frame.rows / 2;
            putText(frame, text, origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);

            oFile << area << "," << length << "," << roundIndex << ","
                << eccIndex << "," << ent.val[0] << endl;
            LOG(INFO) << "Find fire." << "-area:" << area
                << "-length:" << length << "-roundIndex:" << roundIndex
                << "-eccIndex:" << eccIndex << "-entropy:" << ent.val[0];
        }
    }

    for (size_t i = 0; i < contours.size(); i++) {
        drawContours(frame, hull, (int)i, Scalar(255, 0, 0), 5);
    }

    cv::namedWindow("result", WINDOW_NORMAL);
    cv::imshow("result", frame);
}

int main(int argc, char** argv)
{
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    el::Loggers::reconfigureLogger("default", defaultConf);
    el::Logger* defaultLogger = el::Loggers::getLogger("default");

    ofstream oFile;
    oFile.open(csv_name, ios::out | ios::trunc);
    oFile << "-area:" << "," << "-length:" << ","
        << "-roundIndex:" << "," << "-eccIndex:" << ","
        << "-entropy:" << endl;

    LOG(INFO) << "Start fire detect!";
    LOG(INFO) << "Detect result save to " << csv_name;
    LOG(INFO) << "Detect per " << flag;

    VideoCapture capture(video_name);
    Size dsize = Size(800, 450);

    int frame_num = 0;
    while (1) {
        frame_num += 1;
        if (frame_num % flag == 0) {
            Mat frame;
            capture >> frame;
            if (frame.empty()) break;

            resize(frame, frame, dsize, 0, 0, INTER_AREA);
            processing(frame, oFile);

            if (!capture.read(frame)) {
                cout << "detection done!" << endl;
                break;
            }
            int c = waitKey(50);
            if (c == 27) break;
        }
    }
    oFile.close();
    return 0;
}
