#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv){
    Mat mat = (Mat_<uchar>(3,3) <<
        1,1,3,
        4,5,6,
        7,8,9);
    cout << "mat=\n" << mat << endl;

    double thresh = 5;
    double maxval = 100;
    Mat binary, binary_inv;
    
    threshold(mat, binary, thresh, maxval, THRESH_BINARY); // 二值化操作，大于5为100，小于5为0
    threshold(mat, binary_inv, thresh, maxval, THRESH_BINARY_INV); // 反向二值化操作，小于5为100，大于5为0
    cout << "binary=\n" << binary << endl;
    cout << "binary_inv=\n" << binary_inv << endl;

    Mat trunc, tozero, tozero_inv;
    threshold(mat, trunc, thresh, maxval, THRESH_TRUNC); // 截断操作，大于5为5，小于5保持不变
    threshold(mat, tozero, thresh, maxval, THRESH_TOZERO); // 截断操作，大于5不变，小于5为0
    cout << "trunc=\n" << trunc << endl;  
    cout << "tozero=\n" << tozero << endl;  

    return 0;
}