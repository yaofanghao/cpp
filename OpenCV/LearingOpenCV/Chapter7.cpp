#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ############## 检测形状 ##############

// 查找轮廓函数
void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours; // 声明组成轮廓的向量
	vector<Vec4i> hierarchy; // 声明表示有四个整数（int）的向量

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // 查找轮廓
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2); // 绘制轮廓

	vector<vector<Point>> conPoly(contours.size()); // 声明组成多边形逼近得到的轮廓的向量
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl; // 统计各个轮廓的面积
		string objectType; // 声明轮廓类型的字符串

		if (area > 1000) // 筛选轮廓面积大于1000
		{
			float peri = arcLength(contours[i], true);
			
			// approxPolyDP函数：对指定点集进行多边形逼近
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl; // 打印各轮廓逼近得到的多边形边数
			boundRect[i] = boundingRect(conPoly[i]); // 

			int objCor = (int)conPoly[i].size(); // 轮廓的角点个数

			if (objCor == 3) { objectType = "Tri"; } // 三角形
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height; // 计算宽高比
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; } // 正方形
				else { objectType = "Rect"; } // 矩形
			}
			else if (objCor > 4) { objectType = "Circle"; } // 圆

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y-5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
		}
	}

}

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

int main() {
    string path = "resources/shapes.png";
    Mat img = imread(path);

	// 预处理
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	// 调用查找轮廓函数
	getContours(imgDil, img);

	imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

    waitKey(0);
}