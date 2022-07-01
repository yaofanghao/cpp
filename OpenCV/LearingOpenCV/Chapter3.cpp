#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ͼ�������֪ʶ-2
int main() {
    string path = "resources/test.png";
    Mat img = imread(path);
    Mat imgResize,imgCrop;

    cout << img.size << endl;
 
    //resize(img, imgResize, Size(200, 200)); // ����ͼƬ�ߴ�
    resize(img, imgResize, Size(), 0.8,0.8);

    Rect roi(100, 100, 300, 250); // ��ȡ����Ȥ����ROI
    imgCrop = img(roi);

    imshow("image", img);
    imshow("imageResize", imgResize);
    imshow("imageCroppo", imgCrop);

    waitKey(0);
}
