// https://docs.opencv.org/4.x/db/da5/tutorial_how_to_scan_images.html
// https://github.com/opencv/opencv/blob/4.x/samples/cpp/tutorial_code/core/how_to_scan_images/how_to_scan_images.cpp
// 调用方法 how_to_scan_images imageName.jpg intValueToReduce [G]

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

static void help()
{
    cout
        << "\n--------------------------------------------------------------------------" << endl
        << "This program shows how to scan image objects in OpenCV (cv::Mat). As use case"
        << " we take an input image and divide the native color palette (255) with the " << endl
        << "input. Shows C operator[] method, iterators and at function for on-the-fly item address calculation." << endl
        << "Usage:" << endl
        << "./how_to_scan_images <imageNameToUse> <divideWith> [G]" << endl
        << "if you add a G parameter the image is processed in gray scale" << endl
        << "--------------------------------------------------------------------------" << endl
        << endl;
}

Mat& ScanImageAndReduceC(Mat& I, const uchar* table);
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* table);
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* table);

int main(int argc, char* argv[])
{
    help();
    if (argc < 3)
    {
        cout << "Not enough parameters" << endl;
        return -1;
    }

    Mat I, J;
    if (argc == 4 && !strcmp(argv[3], "G"))
        I = imread(argv[1], IMREAD_GRAYSCALE);
    else
        I = imread(argv[1], IMREAD_COLOR);

    if (I.empty())
    {
        cout << "The image" << argv[1] << " could not be loaded." << endl;
        return -1;
    }

    //! [dividewith]
    int divideWith = 0; // convert our input string to number - C++ style
    stringstream s;
    s << argv[2];
    s >> divideWith;
    if (!s || !divideWith)
    {
        cout << "Invalid number entered for dividing. " << endl;
        return -1;
    }

    uchar table[256];
    for (int i = 0; i < 256; ++i)
        table[i] = (uchar)(divideWith * (i / divideWith));
    //! [dividewith]

    const int times = 100;
    double t;

    t = (double)getTickCount(); // getTickCount测量CPU的tick数，getTickFrequency测量CPU每秒的tick数

    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        J = ScanImageAndReduceC(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();  // 计算出时间，单位为秒
    t /= times;

    cout << "Time of reducing with the C operator [] (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        J = ScanImageAndReduceIterator(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the iterator (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        ScanImageAndReduceRandomAccess(clone_i, table);
    }

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the on-the-fly address generation - at function (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;

    //! [table-init]
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = table[i];
    //! [table-init]

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
        //! [table-use]
        LUT(I, lookUpTable, J);
    //! [table-use]

    t = 1000 * ((double)getTickCount() - t) / getTickFrequency();
    t /= times;

    cout << "Time of reducing with the LUT function (averaged for "
        << times << " runs): " << t << " milliseconds." << endl;
    return 0;
}

//! [scan-c] 经典的 C 风格 operator[]（指针）访问
Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())  // I.isContinuous 检查矩阵是否连续
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i, j;
    uchar* p;
    for (i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);
        for (j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}
//! [scan-c]

//! [scan-iterator] 迭代器（安全）方法
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    const int channels = I.channels();
    switch (channels)
    {
    case 1:
    {
        MatIterator_<uchar> it, end;
        for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
            *it = table[*it];
        break;
    }
    case 3:
    {
        MatIterator_<Vec3b> it, end;
        for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
        {
            (*it)[0] = table[(*it)[0]];
            (*it)[1] = table[(*it)[1]];
            (*it)[2] = table[(*it)[2]];
        }
    }
    }

    return I;
}
//! [scan-iterator]

//! [scan-random] 带参考返回的即时地址计算
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    const int channels = I.channels();
    switch (channels)
    {
    case 1:
    {
        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j)
                I.at<uchar>(i, j) = table[I.at<uchar>(i, j)];
        break;
    }
    case 3:
    {
        Mat_<Vec3b> _I = I;

        for (int i = 0; i < I.rows; ++i)
            for (int j = 0; j < I.cols; ++j)
            {
                _I(i, j)[0] = table[_I(i, j)[0]];
                _I(i, j)[1] = table[_I(i, j)[1]];
                _I(i, j)[2] = table[_I(i, j)[2]];
            }
        I = _I;
        break;
    }
    }

    return I;
}
//! [scan-random]

