## 进度
学习时间：2022.6.5 - 2022.7.16
更新时间：2022.7.16

## 参考资料 
* OpenCV官方文档
  https://docs.opencv.org/4.x/d9/df8/tutorial_root.html

* 官方示例代码
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
* **1_1_Mat_TheBasicImageContainer.cpp**
  * **Mat 对象的使用，create，clone，copyTo ...**
* **1_2_HowtoScanImages.cpp**
  * **访问像素的方法：C 风格 operator[]（指针），迭代器，带参考返回的即时地址计算**
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
* **2_3_SmoothingImages.cpp**
  * **图像平滑 blur() GaussianBlur() medianBlur() bilateralFilter()**
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
* **2_9_BasicThresholdingOperations.cpp**
  * **基本阈值操作 cv::threshold**
* 2_10_ThresholdingOperationsUsing_inRange.cpp
  * inRange函数阈值操作
* -------**Transformations**
* **2_11_LinearFilters.cpp**
  * **线性滤波器**
* 2_12_AddingBorders.cpp
  * 添加边界
* 2_13_Sobel.cpp
  * Sobel边缘检测
* 2_14_Laplace.cpp
  * 拉普拉斯算子
* **2_15_Canny.cpp**
  * **Canny边缘检测**
* 2_16_HoughLine.cpp
  * 霍夫变换-线
* 2_17_HoughCircle.cpp
  * 霍夫变换-圆
* **2_18_Remapping.cpp**
  * **重映射**
* 2_19_Affine.cpp
  * 仿射变换
* -------**Histograms** 
* **2_20_HistogramEqualization.cpp**
  * **直方图均衡化**
* 2_21_HistogramCalculation.cpp
  * 直方图计算 cv::calcHist 
* 2_22_HistogramComparison.cpp
  * 直方图比较 cv::compareHist 相关性、卡方、交集、Bhattacharyya距离
* 2_23_BackProjection.cpp
  * 反投影
* 2_24_TemplateMatching.cpp
  * 模板匹配
* -------**Contours**
* **2_25_FindingContours.cpp**
* 2_26_ConvexHull.cpp
  * 凸包
* 2_27_BoundingBoxesAndCircles.cpp
  * 绘制边界框和圆形框
* 2_28_BoundingRotatedBoxesAndEllipses.cpp
* 2_29_ImageMomnts.cpp
* 2_30_PointPolygon.cpp
  * 绘制多边形
* -------**Others**
* **2_31_DistanceTransformAndWatershedAlgorithm.cpp**
  * **距离变换和分水岭算法进行图像分割**
* 2_32_OutOfFocusDeblur.cpp
  * 失焦去模糊滤镜
* 2_33_MotionDeblur.cpp
  * 运动去模糊滤镜
* 2_34_GradientStructureTensor.cpp
  * 梯度结构张量的各向异性图像分割
* 2_35_PeriodicNoiseRemoving.cpp
  * 周期性去噪滤波器

**3、Application utils(highgui, imgcodecs, videoio modules)**
* https://docs.opencv.org/4.x/de/d3d/tutorial_table_of_content_app.html
* 3_1_Trackbar.cpp
  * 添加进度条
* 3_2 略
* 3_3_VideoInputAndSimilarityMeasurement.cpp
  * 读取视频并测量相似度
* **3_4_CreatVideo.cpp**
  * **创建视频**
* 3_5 Kinect 略
* 3_6 Orbbec Astra 3D 略
* 3_7 Senz3D 略

**4、Camera calibration and 3D reconstruction (calib3d module)**
* https://docs.opencv.org/4.x/d6/d55/tutorial_table_of_content_calib3d.html
* 相机标定和3D重建 略
* 需要使用再查阅

**5、2D Features framework (feature2d module)**
* https://docs.opencv.org/4.x/d9/d97/tutorial_table_of_content_features2d.html
* **5_1_Harris.cpp**
  * **Harris 角点检测**
* 5_2_ShiTomasi.cpp
  * ShiTomasi 角点检测
* 5_3_CustomCorner.cpp
  * 自定义角点检测器
* 5_4_Subpixels.cpp
  * 子像素角点检测
* **5_5_FeatureDetection.cpp**
  * **特征检测 surf算子**
* 5_6_FeatureDescription.cpp
  * 特征匹配 surf算子
* 5_7_FLANN.cpp
* **5_8_Features2DHomography.cpp**
  * **cv::findHomography cv::perspectiveTransform**
* 5_9_PlanarObjects.cpp
  * 平面物体的检测
* 5_10_AKAZE.cpp
  * AKAZE局部特征匹配
* 5_11_AKAZEandORBplanar.cpp
  * AKAZE和ORB平面物体追踪
* 5_12_BasicHomography.cpp
  * 用代码解释基本的homography操作

**6、Deep Neural Networks (dnn module)**
* https://docs.opencv.org/4.x/d2/d58/tutorial_table_of_content_dnn.html
* Tensorflow PyTorch 等框架与 OpenCV 的结合
* **YOLO DNNs**
* **OCR** 
* **Face Detection**
* 其他若干深度学习应用

**7、Graph API (gapi module)**
* https://docs.opencv.org/4.x/d3/d7a/tutorial_gapi_anisotropic_segmentation.html
* 各向异性图像分割

**8、Other tutorials (ml, objdetect, photo, stitching, video)**
* https://docs.opencv.org/4.x/d3/dd5/tutorial_table_of_content_other.html
* 8_1_HDR.cpp
  * 高动态范围处理照片
* 8_2 High Level Stitching 略
* **8_3_BackgroundSubtraction.cpp**
  * **背景提取技术**
* **8_4_1Meanshift.cpp**
* **8_4_2Camshift.cpp**
  * **Meanshift 和 Camshift 跟踪算法**
* 8_5 Optical Flow 光流 略
* **8_6_CascadeClassifier.cpp**
  * **级联分类器 Haar级联检测**
* 8_7_CascadeClassifierTraining.cpp
  * 级联分类器训练
* **8_8_SVM.cpp**
  * **支持向量机简单示例**
* 8_9_SWMforNonLinear.cpp
  * 对非线性的支持向量机方法
* 8_10_PCA.cpp

**9、OpenCV iOS**
* 略

**10、GPU-Accelerated Computer Vision (cuda module)**
* 略


---
**B站学习资料**
**1、小刘老赖 从零实现opencv-c++**
* https://space.bilibili.com/509929183/
* Threshold 文件夹 图像处理的阈值操作 https://www.bilibili.com/video/BV1y54y1X7wz?share_source=copy_web