## 
* 2023.5.29-
* Qt Creator 10.0.1
* Qt 6.5.1 
* MSVC 2019, x86_64
* MinGW 11.20.64

* C++基础知识、类、面向对象、STL
* https://doc.qt.io/qt-6/
* https://www.qt.io/zh-cn/
	* https://download.qt.io/official_releases/online_installers/
* http://qtdoc.cutebook.net/qtdoc/index.html
* https://github.com/feiyangqingyun/QWidgetDemo/tree/master
* Qt 5.9 C++开发指南》2021 https://www.bilibili.com/video/BV1AX4y1w7Nt
* https://www.youtube.com/watch?v=_82WD79eCD4&list=PLHtXVCtcbbo2cc-E1ExCtp7j51vELXI9c


## 
* F1 直接进入帮助文档
* Ctrl+R 运行
* Ctrl+B ui界面修改后重新编译
* F4 快速切换h和cpp文件 
* Alt+Enter 自动把h中的函数添加到对应cpp中

## test

* Go to Slots 设置信号槽
* **connect() 函数**
  *  connect(scrollBar, SIGNAL(xxx), label,  SLOT(xxx));

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
 



