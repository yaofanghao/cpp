## 进度
学习时间：2022.6.5 起 - 
更新时间：2022.7.10

* 官方文档 2_23
* b站up 小刘老赖 

## 参考资料 
OpenCV官方文档
https://docs.opencv.org/4.x/d9/df8/tutorial_root.html

官方示例代码
https://docs.opencv.org/4.x/examples.html

按照顺序实现官方文档代码，更新中

* Win 安装 OpenCV
https://docs.opencv.org/4.x/d3/d52/tutorial_windows_install.html

* Linux 安装 OpenCV
https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html

* VS 配置 OpenCV
https://docs.opencv.org/4.x/dd/d6e/tutorial_windows_visual_studio_opencv.html

* VScode 配置 OpenCV
https://github.com/microsoft/vscode-cmake-tools
https://www.bilibili.com/video/BV1gu411X7BP?share_source=copy_web
http://t.csdn.cn/bFXcX

---
## 代码说明
**0_GettingStratedwithImages.cpp**
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

**2、Image Processing (imgproc module)**
* https://docs.opencv.org/4.x/d7/da8/tutorial_table_of_content_imgproc.html

* -------**Basic**
* 2_1_BasicDrawing.cpp
  * 基本绘图功能
* 2_3_SmoothingImages.cpp
  * 图像平滑 blur() GaussianBlur() medianBlur() bilateralFilter()
* 2_4_ErodingDilating.cpp
  * 腐蚀和膨胀
* 2_5_MoreMorphologyTransformations.cpp
  * 形态学操作 Opening, Closing, Morphological Gradient, Top Hat, Black Hat 
* 2_6_HitOrMss.cpp
  * 击中或击不中变换
* 2_7_ExtractHorizontalAndVerticalLines.cpp
  * 提取水平和垂直特征
* 2_8_ImagePyramids.cpp
  * 图像金字塔 pyrUp pyrDown
* 2_9_BasicThresholdingOperations.cpp
  * 基本阈值操作 cv::threshold
* 2_10_ThresholdingOperationsUsing_inRange.cpp
  * inRange函数阈值操作
* -------**Transformations**
* 2_11_LinearFilters.cpp
  * 线性滤波器
* 2_12_AddingBorders.cpp
  * 添加边界
* 2_13_Sobel.cpp
  * Sobel边缘检测
* 2_14_Laplace.cpp
  * 拉普拉斯算子
* 2_15_Canny.cpp
  * Canny边缘检测
* 2_16_HoughLine.cpp
  * 霍夫变换-线
* 2_17_HoughCircle.cpp
  * 霍夫变换-圆
* 2_18_Remapping.cpp
  * 重映射
* 2_19_Affine.cpp
  * 仿射变换
* -------**Histograms** 
* 2_20_HistogramEqualization.cpp
  * 直方图均衡化
* 2_21_HistogramCalculation.cpp
  * 直方图计算 cv::calcHist 
* 2_22_HistogramComparison.cpp
  * 直方图比较 cv::compareHist 相关性、卡方、交集、Bhattacharyya距离
* 2_23_BackProjection.cpp
  * 反投影
* 2_24_TemplateMatching.cpp
  * 模板匹配
* -------**Contours**
* 2_25_ 

---
**B站学习资料**
**1、小刘老赖 从零实现opencv-c++**
* https://space.bilibili.com/509929183/
* Threshold 文件夹 图像处理的阈值操作 https://www.bilibili.com/video/BV1y54y1X7wz?share_source=copy_web