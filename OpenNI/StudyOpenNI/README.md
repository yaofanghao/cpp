## OpenNI2 学习记录
* 2022.7.27- 起
* 更新进度：2022.8.2

----------

## 参考资料
* 参考书 **openni cookbook**
* https://structure.io/openni 各种环境的SDK下载
* https://github.com/structureio/OpenNI2 
* https://robots.uc3m.es/installation-guides/install-openni-nite.html linux版安装
* https://blog.csdn.net/weixin_44211644/article/details/126002688 linux环境搭建
* https://blog.csdn.net/weixin_44211644/article/details/126049773 linux版的cmake配置
* https://documentation.help/OpenNI-2.0/getting_started.html win版安装和vs配置
* https://blog.csdn.net/weixin_44211644/article/details/126055226 win版安装和vs配置

openni2的API说明文档：
* https://documentation.help/OpenNI-2.0/index.html
* https://s3.amazonaws.com/com.occipital.openni/OpenNI_Programmers_Guide.pdf
* https://developer.orbbec.com.cn/technical_library/OpenNI2/html/md__d_1_16_xE3_x80_x81_xE5_x9F_xBA_xE7_xA1_x80_s_d_k__open_n_i2_s_d_k_doc-new__open_n_i2_83-_s_d_k__doc_zh_0300__code_samples.html

奥比中光的SDK（不适用于Xtion）
* https://orbbec3d.com/index/download.html

OpenCV对深度相机的处理
* https://docs.opencv.org/4.6.0/d7/d6f/tutorial_kinect_openni.html 
* https://github.com/opencv/opencv/blob/3.4/samples/cpp/videocapture_openni.cpp
* https://docs.opencv.org/4.x/d2/d3a/group__rgbd.html

通过OpenNI2获取数据并转至OpenCV格式及点云生成
* https://blog.csdn.net/u014610460/article/details/80135843

其他参考资料
* https://github.com/AmmarkoV/RGBDAcquisition
* https://github.com/leaveitout/asus_xtion_intrinsic_calibration  用于校准 

Primesense 传感器并将校准文件写入 InfiniTAM 格式的工具
* https://github.com/carlren/OpenNICalibTool

----------

## 学习记录
* 以下列出的均已经在win环境运行成功

* open_default_camera.cpp
	- opencv 打开笔记本默认摄像头

* opennitest.cpp 
	- 测试openni环境是否搭建正常，能否打开摄像头

* test_device.cpp
	- 读取设备列表，包含设备id、制造商、usb、uri等信息

* getDataStream.cpp
	- 读取深度和彩色rgb信息流

* SimpleRead 文件夹
	- SimpleRead.cpp 读取深度信息，单位mm

* openni_convert_to_opencv 文件夹
	- openni_convert_to_opencv2.cpp 
		- 将深度和彩色数据转换为OpenCV读取的格式并显示
		- 例如 const cv::Mat mImageDepth(frameDepth.getHeight(), frameDepth.getWidth(), CV_16UC1, (void*)frameDepth.getData());
		- 问题：程序运行卡死，画面静止不动

* openni_cookbook_code 文件夹
  * 来源-- https://www.packtpub.com/support/code-downloads

  * chapter2
	- 1_Basics 入门介绍
		- OpenNI::getVersion() 读取OpenNI版本 
		- status = OpenNI::initialize(); 确认OpenNI状态 
		- **bool HandleStatus(Status status) 判断OpenNI状态是否正常的函数**
    		- Status 是枚举类型，默认为0，即STATUS_OK
	- 2_ListOfDevices 读取设备列表
		- Array<openni::DeviceInfo> listOfDevices;
		- OpenNI::enumerateDevices(&listOfDevices);
		- DeviceInfo 类 
    		- 包含设备id、制造商、usb、uri等信息
	- 3_InitVideoStream **创建视频流**
		- Device 类
			- device.hasSensor(SensorTypre) 检查是否支持该设备读取深度信息
				- **其中SensorTypre是枚举类型，可以填写- - SENSOR_COLOR\SENSOR_DEPTH\SENSOR_IR，读取rgb、深度、ir三种信息**
		- VideoStream 类
			- sensor.create(device, SensorTypre) 创建视频流
		- VideoMode 类
			- 设置帧数、分辨率、深度格式精度等信息
			- sensor.setVideoMode(depthVM)
			- sensor.start() 创建连接
	- 3_2_VideoModes
		- 显示设备可能支持的VideoMode 分辨率、帧数等信息，并选择其中一种
	- 4_SelectDevice 选择指定设备（不重要，略）
	- 5_ListenToOpenNIEvents **监视设备连接和断开事件** （7.31 没怎么看懂）
		- struct OurOpenNIEventMonitorer 定义事件监视结构体
	- 6_OpenFileAsDevice **读取现有的ONI格式数据**，而不是通过摄像头
		- Deivce 类
			- device.open(addressOfFile) 打开oni文件

  * chapter3 Using Low-level Data
	- VideoFrameRef 类 OpenNI2.x版本中，只需这个类就可以读取传感器数据
	- **VideoFrameRef::getData() 返回这一帧图像第一个像素的未定义数据类型指针void***
	- **openni::VideoFrameRef::getStrideInBytes()  返回图像每一行的bytes数**
	- ![重点关注](openni_cookbook_code/chapter3/videoFrame.png "VideoFrame类原理")
	- 需要配置 OpenGL 或 freeglut等 易于迁移到其他平台
	- 1_Color&IR  **读取颜色和IR红外光信息**
		- esc退出，C/c设置为color模式，I/i设置为IR模式

