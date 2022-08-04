// 测试cmake时的opencv配置情况

#include <opencv2/opencv.hpp>
int main(void)
{
	std::cout << cv::getBuildInformation() << std::endl;
}
