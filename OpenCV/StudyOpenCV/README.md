## 参考资料 OpenCV官方文档
https://docs.opencv.org/4.x/d9/df8/tutorial_root.html

按照顺序实现官方文档代码，更新中

更新时间：2022.7.1
进度：1_7

## Win 安装 OpenCV
https://docs.opencv.org/4.x/d3/d52/tutorial_windows_install.html

## Linux 安装 OpenCV
https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html

## VS 配置 OpenCV
https://docs.opencv.org/4.x/dd/d6e/tutorial_windows_visual_studio_opencv.html

## 代码说明
* 0_GettingStratedwithImages.cpp
  * https://docs.opencv.org/4.x/db/deb/tutorial_display_image.html
  * 读取图片

**1、The Core Functionality (core module)**
* https://docs.opencv.org/4.x/de/d7a/tutorial_table_of_content_core.html
* 1_1_Mat_TheBasicImageContainer.cpp
  * Mat 对象的使用，create，clone，copyTo ...
* 1_2_HowtoScanImages.cpp
  * 访问像素的方法：C 风格 operator[]（指针），迭代器，带参考返回的即时地址计算
* 1_3_MaskOperations.cpp
  * 图像掩膜，自带函数 filter2D
* 1_4_OperationsWithImages.cpp
  * 读取，可视化图片
* 1_5_AddingBlendingImages.cpp
  * alpha 和 beta 变换对图片做加法
* 1_6_ChangingContrastAndBrightness.cpp
  * 调整对比度和亮度
* 1_7_DiscreteFourierTransform.cpp
  * 离散傅里叶变换

**2、Image Processing (imgproc module) - image processing functions**

