## 学习进度
* 2022.8.4- 起
* 更新进度：2022.8.9

----------

## 参考资料
- 8.4起 测试代码均放在此处
- **将深度和彩色数据转换为OpenCV读取的格式并显示**
- **例如 const cv::Mat mImageDepth(frameDepth.getHeight(), frameDepth.getWidth(), CV_16UC1, (void*)frameDepth.getData());**

- test.cpp
	- 8.4 测试 能否转成OpenCV格式进行基本的图像处理
	- 理论上没有问题，但是在我的电脑分辨率640x480时候卡死，无法运行；改为600x450后正常
	- 参考自 https://kheresy.wordpress.com/2013/01/09/%e7%94%a8-opencv-%e7%95%ab%e5%87%ba-openni-2-%e7%9a%84%e6%b7%b1%e5%ba%a6%e3%80%81%e5%bd%a9%e8%89%b2%e5%bd%b1%e5%83%8f/

- 8_8.cpp
	- 可以用OpenCV格式读取,显示深度图和rgb图
	- 可以鼠标点击获取深度
		//// ---------读取图像某点深度的两种方法，以中心点为例：        
		//// 方法1 访问该处元素值
		//int middleIndex = (mDepthFrame.getHeight() + 1) * mDepthFrame.getWidth() / 2;                  
		//// 方法2 指针偏移至该处
		//DepthPixel* centerPixel =
		//    (DepthPixel*)((char*)mDepthFrame.getData() +
		//    (mDepthFrame.getHeight() * mDepthFrame.getStrideInBytes() / 2)) + 
		//    (mDepthFrame.getWidth() / 2);
		//// 两种方法对比输出，结果相等
		//cout << "method1: depth is " << pDepth[middleIndex] << endl;
		//cout << "method2: depth is " << *centerPixel << endl;
		//cout << "-----------" << endl;

		// //float wX, wY, wZ;
		//status = CoordinateConverter::convertDepthToWorld(
		//    mDepthStream,
		//    (float)(mDepthFrame.getWidth() / 2),
		//    (float)(mDepthFrame.getHeight() / 2),
		//    (float)(*centerPixel),
		//    &wX, &wY, &wZ);
		//if (!HandleStatus(status)) return 1;
		//printf("Center pixel's at distance is %gmm "
		//    "located at %gmmx%gmm\r\n",
		//    wZ, wX, wY);

- 8_8_1.cpp handDetection.h
	- 简陋版 检测手部信息
		- 初步效果，有待完善

- 8_9.cpp faceDetection.h
	- 基于Haar特征级联分类器的人脸检测
	- （已解决该问题）：无法读取人脸检测xml
		- 解决办法，xml目录写在faceDetection.h而不是主函数中，且xml必须为完整路径
	- 读取脸部中心处深度
	- 目前不知道深度值是否准确？


	- 边缘检测、阈值分割、特征检测等基本处理