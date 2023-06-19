<!--
 * @Author: yao fanghao
 * @Date: 2023-05-08 17:56:32
 * @LastEditTime: 2023-06-16 10:07:47
 * @LastEditors: yao fanghao
-->

# 项目概述

* 2021.10 ~ 2022.10
* 系统用于穿梭车的视觉障碍物检测及距离识别
* 穿梭车通过摄像头采集到视频信息对轨道上的障碍物、与障碍物的距离等行走情况进行判断
  
## 工作内容

* 识别障碍物与距离检测算法
* 工控机图像处理模块与LabVIEW上位机调试软件
* 撰写测试方案与测试报告
  
* heavy car
  * read_buffer
    * 0xb0 预测
      * 日志打印时间
      * Predict_Result 的编码
      * 显示检测图片
    * 0xb1 测距 runFunctionB1Distance
      * 根据fun2TagSize 计算真实距离 imageRealDistance
      * 日志打印distanceResult
    * 0xb2 标定 runFunctionB2Hoist
      * 根据fun2TagSize 计算真实距离 heightCheckResult
      * 日志打印checkResult

* light car
  * read_buffer
    * 0x01 识别条形码
    * 0x02 process模块 -> 模型预测
    * 0x03 显示图片
    * 0x04 process并保存图片

## 说明

* hoistCheckParameter
  * 提升机
* write_buffer由对方提供，特定的13位，用于串口通信

## 开发环境和依赖

* RK3399 (armv8)
* gcc 8.3.0
* gdb 8.2.1
* CMake 3.16.3
* OpenMP ???
* OpenCV 4.5.1
* Paddle-Lite 的 C++ API
* easylogging++
* CppLinuxSerial
* AprilTag
* zbar

## Acknowledgement

* Paddle-Lite
  <https://github.com/PaddlePaddle/Paddle-Lite>
* C++推理流程
  <https://paddle-lite.readthedocs.io/zh/develop/user_guides/cpp_demo.html>
* 目标检测C++API demo示例  
  <https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo>

* 模型部署
  <https://paddlelite.paddlepaddle.org.cn/quick_start/tutorial.html>
* 转换为nb模型
  模型导出-转换为inference模型

  ```
  paddlex --export_inference --model_dir=./output/yolov3_darknet53_coco/best_model/ --save_dir=./inference_model
  ```  

  模型优化-转换为nb格式的模型

  ```
  paddle_lite_opt --model_dir=./inference_model/inference_model --optimize_out=yolov3_darknet53_opt --optimize_out_type=naive_buffer --valid_target=arm
  ```

  <https://www.cnblogs.com/bredzeng/p/15850278.html>

* Paddle-Lite交叉编译
  <https://paddlepaddle.github.io/Paddle-Lite/v2.2.0/source_compile>
  <https://paddle-lite.readthedocs.io/zh/latest/source_compile/linux_x86_compile_arm_linux.html>

* opt模型转换工具
  <https://paddlepaddle.github.io/Paddle-Lite/v2.2.0/model_optimize_tool/>

* AprilTag 标定
  <https://april.eecs.umich.edu/software/apriltag.html>
  <https://github.com/AprilRobotics/apriltag>
  <https://blog.csdn.net/han784851198/article/details/90261197>

* easylogging 日志小模块
  <https://github.com/easylogging>
  <https://blog.csdn.net/woshichenweixian/article/details/77018452>

* CppLinuxSerial
  <https://github.com/gbmhunter/CppLinuxSerial>

* zbar 条形码识别
  <https://www.ccoderun.ca/programming/doxygen/zbar/index.html>
  <https://github.com/ZBar/ZBar/tree/master/examples>

* scp文件传输

## 补充学习-3D视觉

旷视的仓储物流方案
<https://megvii.com/products/hardware/ASRS>

奥比中光
<http://www.orbbec.com.cn/>
<https://shop142544700.taobao.com/?spm=2013.1.0.0.25e23414uOzbC1>

RealSense
<https://www.intel.cn/content/www/cn/zh/architecture-and-technology/realsense-overview.html>

奥比中光Astra+ 0.6-8m
<http://www.orbbec.com.cn/index/Product/info.html?cate=38&id=9>

奥比中光Astra Mini S 0.4-2m
<http://www.orbbec.com.cn/index/Product/info.html?cate=38&id=13>

Xtion PRO
<https://www.asus.com/supportonly/Xtion%20PRO/HelpDesk/>
<https://s.taobao.com/search?q=xtion+pro&imgfile=&js=1&stats_click=search_radio_all%3A1&initiative_id=staobaoz_20220719&ie=utf8>

Zivid
<https://www.zivid.com/zh/zivid-one-plus>

ZED
<https://www.stereolabs.com/zed-2/>
<https://www.stereolabs.com/developers/release/>

## 3D目标检测

综述
<https://github.com/taozh2017/RGBD-SODsurvey>
<https://zhuanlan.zhihu.com/p/34887948>

参考研究
<https://github.com/CMU-Perceptual-Computing-Lab/openpose>
<https://www.youtube.com/watch?v=f-Ibri14KMY>
<https://paperswithcode.com/task/rgb-d-salient-object-detection>
<https://github.com/QianChen98/RD3D>
<https://rgbd-dataset.cs.washington.edu/dataset.html>

opencv模板匹配示例
<https://pyimagesearch.com/2021/03/22/opencv-template-matching-cv2-matchtemplate/>

需要学习的有关内容：
opencv-feature2d
<https://docs.opencv.org/4.x/d9/d97/tutorial_table_of_content_features2d.html>

关键词：SIFT FAST SURF ORB FLANN ……

MMPose

角点检测
特征提取
模板匹配
读取深度相机的3D坐标
基于RGBD的显著性检测、特征检测

## OpenNI

参考书：**openni cookbook**

<https://structure.io/openni> （各种环境的SDK下载）
<https://github.com/structureio/OpenNI2>
<https://robots.uc3m.es/installation-guides/install-openni-nite.html>
<https://blog.csdn.net/weixin_44211644/article/details/126002688?spm=1001.2014.3001.5501> （linux x86版）
？（linux arm版）
<https://documentation.help/OpenNI-2.0/getting_started.html> （win版和vs配置）

openni2的API说明文档：
<https://documentation.help/OpenNI-2.0/index.html>
<https://s3.amazonaws.com/com.occipital.openni/OpenNI_Programmers_Guide.pdf>
<https://developer.orbbec.com.cn/technical_library/OpenNI2/html/md__d_1_16_xE3_x80_x81_xE5_x9F_xBA_xE7_xA1_x80_s_d_k__open_n_i2_s_d_k_doc-new__open_n_i2_83-_s_d_k__doc_zh_0300__code_samples.html>

奥比中光的SDK（不适用于Xtion）
<https://orbbec3d.com/index/download.html>

OpenCV对深度相机的处理
<https://docs.opencv.org/4.5.5/d2/d3a/group__rgbd.html>
<https://docs.opencv.org/4.6.0/d7/d6f/tutorial_kinect_openni.html>
<https://github.com/opencv/opencv/blob/3.4/samples/cpp/videocapture_openni.cpp>

其他参考资料
<https://github.com/AmmarkoV/RGBDAcquisition>
<https://github.com/leaveitout/asus_xtion_intrinsic_calibration>  用于校准

**虚拟机上，cmake能编译通过，但找不到摄像头；  
已解决
这个问题很难排查，参考github上，按该方法添加软链接libudev.so.0 成功解决，可以通过openni2打开摄像头： <https://github.com/structureio/OpenNI2/issues/88>**

## 相机标定

<https://docs.opencv.org/4.6.0/d4/d94/tutorial_camera_calibration.html>
<https://docs.opencv.org/4.6.0/dc/d43/tutorial_camera_calibration_square_chess.html>
<https://docs.opencv.org/4.6.0/d7/d21/tutorial_interactive_calibration.html>

<https://github.com/oreillymedia/Learning-OpenCV-3_examples/blob/master/example_18-01.cpp>

brown大学的标定代码
<http://mesh.brown.edu/calibration/>

该方法目前存在问题：
<https://github.com/carlren/OpenNICalibTool>
