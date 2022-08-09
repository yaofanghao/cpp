## 学习进度
* 2022.8.4- 起
* 更新进度：2022.8.8

----------

## 参考资料
- 8.4起 测试代码均放在此处
- **将深度和彩色数据转换为OpenCV读取的格式并显示**
- **例如 const cv::Mat mImageDepth(frameDepth.getHeight(), frameDepth.getWidth(), CV_16UC1, (void*)frameDepth.getData());**

- test.cpp
	- 8.4 测试 能否转成OpenCV格式进行基本的图像处理
	- 理论上没有问题，但是在我的电脑分辨率640x480时候卡死，无法运行；改为320x240后正常
	- 参考自 https://kheresy.wordpress.com/2013/01/09/%e7%94%a8-opencv-%e7%95%ab%e5%87%ba-openni-2-%e7%9a%84%e6%b7%b1%e5%ba%a6%e3%80%81%e5%bd%a9%e8%89%b2%e5%bd%b1%e5%83%8f/

- 8_8.cpp
	- 可以用OpenCV格式读取
	- 鼠标点击获取深度

- 8_8_1.cpp 简陋版手部检测
	- 检测手部信息 需要包含handDetection.h
		- 初步效果，有待完善

- 8_9.cpp


	- 边缘检测、阈值分割、特征检测等基本处理
	- 级联分类器面部识别