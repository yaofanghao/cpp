## 代码解析
## yolo_detection_demo.cc
测试示例：
* ./yolo_detection_demo ../models/SegFastscnn/modelFastscnn.nb ../images/test.jpg ./result.png

部分参考自：
https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo

zabr官方源码
https://www.ccoderun.ca/programming/doxygen/zbar/index.html
https://github.com/ZBar/ZBar/tree/master/examples

* 181 main函数
->
* 186 日志easylogging初始化
->
* 195 条形码摄像头 cap_barcode 初始化
->
* 214 条形码初始化 ImageScanner scanner ， 来自zbar
* 221 检测摄像头 cap_detect 初始化
* 248 模型 model 初始化
    * 参考：https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo
->
* 258 串口serial初始化
    * /dev/ttyS2 115200波特率，8数据位，无奇偶校验位，1停止位
->
* 272 开始运行程序
    * 根据read_buffer[5]执行不同任务：
      * 286 0x01 调用 barcode_identify
      * 292 0x02 调用 process
      * 298 0x03 显示图片
      * 309 0x04 调用 process ，处理后保存


## 其他细节说明
* 94 process函数
  * 参考资料：https://github.com/PaddlePaddle/Paddle-Lite-Demo/tree/master/PaddleLite-armlinux-demo/object_detection_demo
* 152 barcode_identify函数
  * 参考资料：https://github.com/ZBar/ZBar/tree/master/examples
  * 其中关键是 symbol->get_type_name() symbol->get_data()
* 159 Y800 一种视频格式， Image image 来自zbar
* 162 Image::SymbolIterator 
  * 参考资料：https://www.ccoderun.ca/programming/doxygen/zbar/classzbar_1_1Image_1_1SymbolIterator.html
  * https://github.com/ZBar/ZBar/tree/master/examples
* 170 setw 设置字节宽度
* 202 atoi 将str转换成int


## 7.18 疑问 - 已解决

## 7.18 疑问 - 未解决
