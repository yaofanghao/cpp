## 代码解析
## yolo_detection_demo.cc

* 482 main函数
->
* 487 日志easylogging初始化
->
* 498 摄像头cap初始化
->
* 513 串口serial初始化
    * 57600波特率，8数据位，无奇偶校验位，1停止位
    serialPort("/dev/ttyACM0", 13000)
->
* 523 模型model初始化
    * 参考：https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo
->
* 541 选择debug或run模式
    * debug：
        FUNCT2和FUNCT3的参数设置为1，根据标定结果计算并修改./parameter.txt下的参数信息
    * run:
         stod(parameterTable[2])；没看懂
->
* 562 开始运行程序
    * 根据read_buffer[6]执行不同任务：
        * B0 预测，调用process函数，在其中又调用了preprocess函数
            参考：https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo
        * B1 测距，调用runFunctionB1Distance函数，在其中又调用了apriltag_measurement函数
        * B2 Hoist check，调用runFunctionB2Hoist函数

->