#include "stdio.h"
#include <iostream> 
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp> 
using namespace cv;
using namespace std;

// ############## �����״ ##############

// ������������
void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours; // �����������������
	vector<Vec4i> hierarchy; // ������ʾ���ĸ�������int��������

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // ��������
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2); // ��������

	vector<vector<Point>> conPoly(contours.size()); // ������ɶ���αƽ��õ�������������
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl; // ͳ�Ƹ������������
		string objectType; // �����������͵��ַ���

		if (area > 1000) // ɸѡ�����������1000
		{
			float peri = arcLength(contours[i], true);
			
			// approxPolyDP��������ָ���㼯���ж���αƽ�
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl; // ��ӡ�������ƽ��õ��Ķ���α���
			boundRect[i] = boundingRect(conPoly[i]); // 

			int objCor = (int)conPoly[i].size(); // �����Ľǵ����

			if (objCor == 3) { objectType = "Tri"; } // ������
			else if (objCor == 4)
			{
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height; // �����߱�
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; } // ������
				else { objectType = "Rect"; } // ����
			}
			else if (objCor > 4) { objectType = "Circle"; } // Բ

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

	// Ԥ����
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	// ���ò�����������
	getContours(imgDil, img);

	imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

    waitKey(0);
}