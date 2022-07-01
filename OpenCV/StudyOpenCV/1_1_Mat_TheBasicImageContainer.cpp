// https://docs.opencv.org/4.x/d6/d6d/tutorial_mat_the_basic_image_container.html

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	 // ---------------
	 // cv::Mat::Mat���캯��
	 // ��ʽ���� Mat ����
	 Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	 cout << "M = " << endl << " " << M << endl << endl;
	 // ��ʽ��CV_[ÿ���λ��][�з��Ż��޷���][����ǰ׺]C[ͨ����]
	 Mat m1 = Mat(4, 2, CV_64FC(1));     //����һ��4��2�У���4 ��2����double���;��� CV_64FCĩβ��1��ʾͨ����
	 Mat m2 = Mat(Size(4, 2), CV_64FC(1));  //����д��Ҳ���ԣ�ͬ����Ч��
	 Mat m3 = (Mat_<int>(4, 2) << 1, 2, 3, 4, 5, 6, 7, 8);  //���ٹ���С�͵�ͨ������int���ͣ�����ʼ����

	 // ---------------
	 // cv::Mat::create����
	 // ����Mat�ĳ�Ա����create����2ͨ������
	 Mat m4;
	 m4.create(4, 4, CV_8UC(2)); 
	 cout << "m4(numpy) = " << endl << " " << m4 << endl << format(m4, Formatter::FMT_NUMPY) << endl << endl;

	 // MATLAB ��ʽ��ʼ������cv::Mat::zeros��cv::Mat::ones��cv::Mat::eye
	 Mat E = Mat::eye(4, 4, CV_64F);
	 cout << "E = " << endl << " " << E << endl << endl;
	 Mat O = Mat::ones(2, 2, CV_32F);
	 cout << "O = " << endl << " " << O << endl << endl;
	 Mat Z = Mat::zeros(3, 3, CV_8UC1);
	 cout << "Z = " << endl << " " << Z << endl << endl;

	 // ����С�;��󣬿���ʹ�ö��ŷָ��ĳ�ʼ��������ʼ�������б�
	 Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	 cout << "C = " << endl << " " << C << endl << endl;

	 C = (Mat_<double>({ 0, -1, 0, -1, 5, -1, 0, -1, 0 })).reshape(3);
	 cout << "C = " << endl << " " << C << endl << endl;

	 // ---------------
	 // Ϊ���е�Mat�����cv::Mat::clone��cv::Mat::copyTo����һ���±�ͷ
	 Mat RowClone = C.row(1).clone();
	 cout << "RowClone = " << endl << " " << RowClone << endl << endl;

	 // ---------------
	 // ���������ʽ
	 Point2f P(5, 1); // 2D��
	 cout << "Point (2D) = " << P << endl << endl;

	 Point3f P3f(2, 6, 7); // 3D��
	 cout << "Point (3D) = " << P3f << endl << endl;

	 vector<float> v; // ����-����1
	 v.push_back((float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
	 cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

	 vector<Point2f> vPoints(20);// ����-����2
	 for (size_t i = 0; i < vPoints.size(); ++i)
		 vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
	 cout << "A vector of 2D Points = " << vPoints << endl << endl;
	 	 
	 return 0;
}
