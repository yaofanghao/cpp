## 学习进度
* 2022.8.4- 起
* 更新进度：2022.8.11

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
		// ---------读取图像某点深度的两种方法，以中心点为例：        
		// 方法1 访问该处元素值
		int middleIndex = (mDepthFrame.getHeight() + 1) * mDepthFrame.getWidth() / 2;                  
		// 方法2 指针偏移至该处
		DepthPixel* centerPixel =
		    (DepthPixel*)((char*)mDepthFrame.getData() +
		    (mDepthFrame.getHeight() * mDepthFrame.getStrideInBytes() / 2)) + 
		    (mDepthFrame.getWidth() / 2);
		// 两种方法对比输出，结果相等
		cout << "method1: depth is " << pDepth[middleIndex] << endl;
		cout << "method2: depth is " << *centerPixel << endl;
		cout << "-----------" << endl;

		float wX, wY, wZ;
		status = CoordinateConverter::convertDepthToWorld(
		    mDepthStream,
		    (float)(mDepthFrame.getWidth() / 2),
		    (float)(mDepthFrame.getHeight() / 2),
		    (float)(*centerPixel),
		    &wX, &wY, &wZ);
		if (!HandleStatus(status)) return 1;
		printf("Center pixel's at distance is %gmm "
		    "located at %gmmx%gmm\r\n",
		    wZ, wX, wY);

		// 读取鼠标点击处坐标、深度值
        // 采用上述方法2的原理实现
        DepthPixel* buttonPixel =
            (DepthPixel*)((char*)mDepthFrame.getData() +
            (p.y * mDepthFrame.getStrideInBytes())) +
            p.x ;

        int dX2, dY2, dZ2;
        dX2 = p.x;
        dY2 = p.y;
        dZ2 = *buttonPixel;
        float wX2, wY2, wZ2;
        status = CoordinateConverter::convertDepthToWorld(
            mDepthStream,
            dX2, dY2, dZ2,
            &wX2, &wY2, &wZ2);
        if (!HandleStatus(status)) return 1;
        cout << "pixel is at " << dX2 << "," << dY2 << "," << dZ2 << endl;
        cout << "located at " << wX2 << "," << wY2 << endl; // 目前暂不清楚x y具体表示的所在位置
        cout << "distance is " << wZ2 << "mm" << endl;

- 8_8_1.cpp handDetection.h
	- 简陋版 检测手部信息
		- 初步效果，有待完善

- 8_9.cpp faceDetection.h
	- 基于Haar特征级联分类器的人脸检测
	- 调用了faceDetection.h中的detectAndDisplay()函数
	- （已解决该问题）：无法读取人脸检测xml
		- 解决办法，xml目录写在头文件faceDetection.h而不是主函数中，且xml必须为完整路径
	- 读取脸部中心处深度
	- 目前不知道深度值是否准确？

	- 边缘检测、阈值分割、特征检测等基本处理

- FLANN.cpp
	- 特征匹配算法 FLANN 示例
- FLANN_my_test.cpp
	- 我的图片 FLANN 匹配示例

- MatchTemplate.cpp
	- 对opencv六种模板匹配方式进行对比
	- 比较理想，实际复杂情况时，旋转、缩放等变换就完全无法使用

- 8_17.cpp faceDetection.h
	- 基于Haar特征级联分类器的手部检测
	- 调用了faceDetection.h中的detectAndDisplayHand()函数



