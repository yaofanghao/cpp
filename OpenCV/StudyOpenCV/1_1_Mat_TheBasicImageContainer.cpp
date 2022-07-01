// https://docs.opencv.org/4.x/d6/d6d/tutorial_mat_the_basic_image_container.html

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	 // ---------------
	 // cv::Mat::Mat构造函数
	 // 显式创建 Mat 对象
	 Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	 cout << "M = " << endl << " " << M << endl << endl;
	 // 格式：CV_[每项的位数][有符号或无符号][类型前缀]C[通道号]
	 Mat m1 = Mat(4, 2, CV_64FC(1));     //构造一个4列2行（宽4 高2）的double类型矩阵 CV_64FC末尾的1表示通道数
	 Mat m2 = Mat(Size(4, 2), CV_64FC(1));  //这种写法也可以，同样的效果
	 Mat m3 = (Mat_<int>(4, 2) << 1, 2, 3, 4, 5, 6, 7, 8);  //快速构造小型单通道矩阵（int类型）并初始化。

	 // ---------------
	 // cv::Mat::create函数
	 // 调用Mat的成员函数create构造2通道矩阵
	 Mat m4;
	 m4.create(4, 4, CV_8UC(2)); 
	 cout << "m4(numpy) = " << endl << " " << m4 << endl << format(m4, Formatter::FMT_NUMPY) << endl << endl;

	 // MATLAB 样式初始化程序：cv::Mat::zeros、cv::Mat::ones、cv::Mat::eye
	 Mat E = Mat::eye(4, 4, CV_64F);
	 cout << "E = " << endl << " " << E << endl << endl;
	 Mat O = Mat::ones(2, 2, CV_32F);
	 cout << "O = " << endl << " " << O << endl << endl;
	 Mat Z = Mat::zeros(3, 3, CV_8UC1);
	 cout << "Z = " << endl << " " << Z << endl << endl;

	 // 对于小型矩阵，可以使用逗号分隔的初始化程序或初始化程序列表
	 Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	 cout << "C = " << endl << " " << C << endl << endl;

	 C = (Mat_<double>({ 0, -1, 0, -1, 5, -1, 0, -1, 0 })).reshape(3);
	 cout << "C = " << endl << " " << C << endl << endl;

	 // ---------------
	 // 为现有的Mat对象和cv::Mat::clone或cv::Mat::copyTo创建一个新标头
	 Mat RowClone = C.row(1).clone();
	 cout << "RowClone = " << endl << " " << RowClone << endl << endl;

	 // ---------------
	 // 常见输出形式
	 Point2f P(5, 1); // 2D点
	 cout << "Point (2D) = " << P << endl << endl;

	 Point3f P3f(2, 6, 7); // 3D点
	 cout << "Point (3D) = " << P3f << endl << endl;

	 vector<float> v; // 向量-方法1
	 v.push_back((float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
	 cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

	 vector<Point2f> vPoints(20);// 向量-方法2
	 for (size_t i = 0; i < vPoints.size(); ++i)
		 vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
	 cout << "A vector of 2D Points = " << vPoints << endl << endl;
	 	 
	 return 0;
}
