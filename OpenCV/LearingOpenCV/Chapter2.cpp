#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ͼ�������֪ʶ-1
int main(){
    string path = "resources/test.png";
    Mat img = imread(path);
    Mat imgGray,imgBlur,imgCanny, imgDil;

    cvtColor(img, imgGray, COLOR_BGR2GRAY); // ת��Ϊ�Ҷ�
    GaussianBlur(img, imgBlur, Size(3,3), 5,0); // ��˹�˲�
    Canny(imgBlur, imgCanny, 50,150); // Canny��Ե���

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); // �ṹԪ��
    dilate(imgCanny, imgDil, kernel); // ���͡���������ʴͬ��erode

    imshow("image", img);
    imshow("imageGray", imgGray);
    imshow("imageBlur", imgBlur);
    imshow("imageCanny", imgCanny);
    imshow("imageDiltaion", imgDil);
    waitKey(0);
}
