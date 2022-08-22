## 代码解析
## yolo_detection_demo.cc

部分参考自：
https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/yolo_detection_demo

https://april.eecs.umich.edu/software/apriltag.html

https://github.com/AprilRobotics/apriltag

* 482 main函数
->
* 487 日志easylogging初始化
->
* 498 摄像头cap初始化
->
* 513 串口serial初始化
    * /dev/ttyS2 115200波特率，8数据位，无奇偶校验位，1停止位
->
* 523 模型model初始化
    * 参考：https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo
->
* 541 argv[1]用户输入debug或run
    * debug：
        FUNCT2和FUNCT3的参数设置为1，根据标定结果计算并修改./parameter.txt下的参数信息
    * run:
         stod: string 转化为double
->
* 562 开始运行程序
    * 根据read_buffer[6]执行不同任务：
        * B0 预测，调用process函数，在其中又调用了preprocess函数
            参考：https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo
        * B1 测距，调用runFunctionB1Distance函数，在其中又调用了apriltag_measurement函数
        * B2 Apriltag Hoist check 标定模式，调用runFunctionB2Hoist函数，在其中又调用了apriltag_measurement函数
->

## 其他细节说明
* 78 double distanceMeasureParameter = 61.0470795077, hoistCheckParameter, carDistanceConvertPara 几个转换参数的设置
* 90 apriltag_measurement函数，传入图片和tagSize，输出vector<float> apriltagResult
* 260 创建了两个vector: vectorpalletIDPack 和 carIDPack ，存放 class_id
* 339 创建了两个bool: palletBool 和 carBool ，在不同的四种情况时，Predict_Result的值不同
* 425 创建了bool: noApriltag ，判定是否发现了标签
* 433 真实距离的计算 imageRealDistance = imageSize * ::carDistanceConvertPara


## 7.18 疑问 - 已解决
* 516 write_buffer 怎么取的，write_buffer 和 read_buffer 为什么是13位
  * 甲方设备提供

## 7.18 疑问 - 未解决
* 524 parameter.txt在哪，没有的话是不是现在都选择debug模式，而不是run模式
  * 7.18 待补充
* 570 这里设置的时间 runtimes = (read_buffer[7] << 8) + read_buffer[8] 是什么意思
* 