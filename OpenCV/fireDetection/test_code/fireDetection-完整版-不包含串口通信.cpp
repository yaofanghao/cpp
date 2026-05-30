#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/videoio.hpp>
#include <iostream>
#include <vector>
#include <numeric>
#include <ctime>
#include "easylogging++.h"

#define _CRT_SECURE_NO_WARNINGS 1
INITIALIZE_EASYLOGGINGPP
using namespace el;
using namespace cv;
using namespace std;

// ===================== 参数配置 =====================
long long flag = 5000000;   // 抽帧处理参数（每 flag 帧处理一次）
int ellipse_low = 5;        // 拟合椭圆所需最少点数
double fps = 25.0;

int hl = 0, hh = 50, sl = 0, sh = 80, vl = 250, vh = 255;
int kernal_size = 1;
double contours_ratio = 0;
double round_low = 0;
int cntlen_low = 0;

Mat imgopen(Mat mask, int kernal_size)
{
    Mat element = getStructuringElement(MORPH_RECT, Size(kernal_size, kernal_size));
    Mat maskDst;
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

    cv::Scalar e(0, 0, 0);
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

std::vector<double> processing(Mat frame)
{
    Mat img1, hsv, mask;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

    cv::Scalar ent = Entropy(frame);
    dilate(frame, img1, kernel);
    cv::cvtColor(img1, hsv, CV_BGR2HSV);
    cv::inRange(hsv, Scalar(hl, sl, vl), Scalar(hh, sh, vh), mask);
    mask = imgopen(mask, kernal_size);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    cv::findContours(mask, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> hull(contours.size());

    std::vector<double> area_result, length_result, roundIndex_result, eccIndex_result, entropy_result;
    int image_area = frame.rows * frame.cols;

    for (size_t i = 0; i < contours.size(); i++) {
        convexHull(contours[i], hull[i]);
        double area = contourArea(contours[i]);
        double length = arcLength(contours[i], true);
        double roundIndex = 4 * CV_PI * area / (length * length + 0.00001);

        if ((area > contours_ratio * image_area) && (roundIndex > round_low)
            && (length > cntlen_low) && (contours[i].size() > ellipse_low)) {
            RotatedRect box = fitEllipse(contours[i]);
            double ellipseA = box.size.height;
            double ellipseB = box.size.width;
            double eccIndex = (abs(ellipseA - ellipseB)) / ellipseA;

            putText(frame, "Warning!",
                    Point(frame.cols / 2, frame.rows / 2),
                    FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);

            area_result.push_back(area);
            length_result.push_back(length);
            roundIndex_result.push_back(roundIndex);
            eccIndex_result.push_back(eccIndex);
            entropy_result.push_back(ent.val[0]);
        }
    }

    for (size_t i = 0; i < contours.size(); i++) {
        drawContours(frame, hull, (int)i, Scalar(255, 0, 0), 5);
    }

    std::vector<double> processing_result(5, 0.0);
    if (!area_result.empty()) {
        processing_result[0] = accumulate(area_result.begin(), area_result.end(), 0.0) / area_result.size();
        processing_result[1] = accumulate(length_result.begin(), length_result.end(), 0.0) / length_result.size();
        processing_result[2] = accumulate(roundIndex_result.begin(), roundIndex_result.end(), 0.0) / roundIndex_result.size();
        processing_result[3] = accumulate(eccIndex_result.begin(), eccIndex_result.end(), 0.0) / eccIndex_result.size();
        processing_result[4] = accumulate(entropy_result.begin(), entropy_result.end(), 0.0) / entropy_result.size();
    }

    cv::namedWindow("result", WINDOW_NORMAL);
    cv::imshow("result", frame);
    return processing_result;
}

int main(int argc, char** argv)
{
    cout << "Usage: " << argv[0] << " [mode - c / v / i] [save_path -- default out.avi]" << endl;

    el::Configurations defaultConf;
    defaultConf.setToDefault();
    el::Loggers::reconfigureLogger("default", defaultConf);

    ofstream oFile;
    oFile.open("detect_result.csv", ios::out | ios::trunc);
    oFile << "-area:,-length:,-roundIndex:,-eccIndex:,-entropy:" << endl;

    LOG(INFO) << "Start fire detect! Result save to detect_result.csv, detect per " << flag;

    VideoCapture capture;
    capture.open(0);
    capture.set(CAP_PROP_FRAME_WIDTH, 1280);
    capture.set(CAP_PROP_FRAME_HEIGHT, 960);
    if (!capture.isOpened()) {
        cerr << "camera not open!" << endl;
        return -1;
    }
    LOG(INFO) << "width:" << int(capture.get(CAP_PROP_FRAME_WIDTH));
    LOG(INFO) << "height:" << int(capture.get(CAP_PROP_FRAME_HEIGHT));

    VideoWriter writer;
    int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
    Size size = Size(int(capture.get(CAP_PROP_FRAME_WIDTH)), int(capture.get(CAP_PROP_FRAME_HEIGHT)));
    writer.open("out.avi", codec, fps, size, true);

    int frame_num = 0;
    while (1) {
        frame_num++;
        if (frame_num % flag == 0) {
            Mat frame;
            capture >> frame;
            if (frame.empty()) break;

            clock_t t1 = clock();
            cout << "image processing... time: " << 1.0 * t1 / CLOCKS_PER_SEC << " s" << endl;

            std::vector<double> processing_result = processing(frame);
            cout << "mean area, length, roundIndex, eccIndex, entropy: ";
            for (auto i : processing_result) cout << i << " ";
            cout << endl;

            oFile << processing_result[0] << "," << processing_result[1] << ","
                  << processing_result[2] << "," << processing_result[3] << ","
                  << processing_result[4] << endl;
            cout << "success write to excel" << endl;
            cout << "-----------------------------------------" << endl;

            writer.write(frame);
            if (!capture.read(frame)) {
                cout << "detection done!" << endl;
                break;
            }
            int c = waitKey(50);
            if (c == 27) break;
        }
    }
    writer.release();
    oFile.close();
    return 0;
}
