<!--
 * @Author: yao fanghao
 * @Date: 2023-06-02 15:49:15
 * @LastEditTime: 2023-06-02 16:02:17
 * @LastEditors: yao fanghao
-->
# My_Qt6_demo

* 参考资料：
  * Qt6 C++开发指南 王维波
  
* **已学习的demo代码更新至git，作为标记**

## countcode

* 统计文件夹内代码行数等信息

## test

* Go to Slots 设置信号槽
* **connect() 函数**
  * connect(scrollBar, SIGNAL(xxx), label,  SLOT(xxx));

* qDebug()打印输出

* 底层都是源自QWidget
* 新建Qt Designer Form Class，继承QWidget

* 引入/继承QObject类的优点：可以自定义信号和槽

* :: 静态成员
* virtual void ... 虚函数

* toString()

* 时间库 QTime QTimer

* QPixmap 承载、配置图片的容器
* QLabel

## tcp_demo

* QTcpServer 服务器端口监听
* QTcpSocket 套接字类，实现消息的封装，读取或写入
* cmd下： ntestat -ano 查看端口信息
* listen() 开启指定端口
* incomingConnection() 套接字。cmd下用telnet测试
* 监听套接字的readyRead信号来处理消息
* read() 读取socket

## tcp_client
