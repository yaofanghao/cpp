* 学习时间：
  * 2023.03.15-
* 更新日期：
  * 2023.03.30

## 参考资料
* **CSAPP**
* Linux是怎样工作的-武内觉 √
* 操作系统导论 √
* 嵌入式软件开发笔试面试指南
* linux/unix系统编程手册
* http://www.cyc2018.xyz/
* 【史上最强最细腻的linux嵌入式C语言学习教程【李慧芹老师】】 https://www.bilibili.com/video/BV18p4y167Md/?share_source=copy_web&vd_source=85816208bdca2a40c310bef0b0d541b4
* 【黑马程序员-Linux网络编程】 https://www.bilibili.com/video/BV1iJ411S7UA/?share_source=copy_web&vd_source=85816208bdca2a40c310bef0b0d541b4
* 【[过期] 2020 南京大学 “操作系统：设计与实现” (蒋炎岩)】 https://www.bilibili.com/video/BV1N741177F5/?share_source=copy_web&vd_source=85816208bdca2a40c310bef0b0d541b4
* 【彻底搞懂 进程&线程、进程池&线程池】 https://www.bilibili.com/video/BV1V84y1Y77s/?share_source=copy_web&vd_source=85816208bdca2a40c310bef0b0d541b4
* 【[原创] 每个程序员都应该知道的内存知识 (带你走读Ulrich Drepper的经典论文)】 https://www.bilibili.com/video/BV1Xy4y1b7SK/?share_source=copy_web&vd_source=85816208bdca2a40c310bef0b0d541b4

## Linux 基本概念
* root用户：#
* 一般用户：$

* vi / vim
  * / 自上而下查找
  * ？ 自下而上查找
  * dgg 删除当前行以上所有内容

* rm
  * -i 逐一询问删除
  * -f 不询问强制删除
  * -r 将目录中全部删除

* z 压缩
* x 解压缩

## 文件
* 用户权限
  * 111 **rwx** 可读可写可执行

* ldd
  * 查看程序依赖的库

* libc
  * Linux中常用的C标准库
  * ldd /bin/echo 查看C标准库信息

* **readelf**
  * https://www.man7.org/linux/man-pages/man1/readelf.1.html
  * 查看ELF格式可执行文件的信息
  * -h 查看起始地址
  * -S 查看代码段与数据段在文件中的偏移量、大小和起始地址

## 进程
* CPU**内核模式**和用户模式
  * 只有处于内核模式才允许访问设备
  * 进程： 用户模式---[发起系统调用]内核模式--[从系统调用恢复运行]用户模式

* **系统调用** system call
* 进程依赖于内核的处理时，必须通过系统调用向内核发起请求
* 系统调用的种类如下：
  * 进程控制（创建和删除）
  * 内存管理（分配和释放）
  * 进程间通信
  * 网络管理
  * 文件系统操作
  * 文件操作（访问设备）

* **strace** 监控进程和内核交互的情况
  * https://strace.io/
  * strace -o hello.log ./hello
  * -T  查看系统调用消耗时间（微秒级）

* **sar** 获取进程在用户模式与内核模式下运行时间的比例
  * http://c.biancheng.net/view/6212.html

* **fork()**
  * 创建子进程
  * fork()函数给父进程和子进程返回不同的值
* **execve()**
  * 启动另一个程序
  * 并非新增一个进程，而是替换了当前进程
  * fork and execve
  * 常用的新建进程的方式

* 逻辑CPU
* 调度器
  * 多个进程轮流使用逻辑CPU
  * 时间片
* 上下文切换
  * 切换进程

***ps ax**
  * 列举当前正在运行的所有进程
  * STAT 表示进程状态
  * 进程状态
    * 初始态 就绪态 运行态 挂起态 终止态

* 吞吐量与延迟
  * 所有逻辑CPU都不处于空闲状态后，不管继续增加多少进程，吞吐量都不再变化
  * 进程数量增加，延迟边长
* 负载均衡
  * 调度器为各个进程分配均等的CPU时间

* **nice()**
  * 设定进程优先级
  * -19最高，20最低
  * nice -n 程序运行时指定优先级

## 内存管理
***free**
  * 查看内存总量和已消耗内存量
  * OOM
    * out of memory 表示内存不足
    * OOM killer 强制终止进程以释放内存

* **虚拟内存**
  * 解决了内存碎片化问题
  * 虚拟地址（VA）---> 内存管理单元（MMU） ---> [映射到]物理地址（PA）
* 页表
* 多级页表
  
* mmap()
  * CSAPP-p585
  * https://blog.csdn.net/dlutbrucezhang/article/details/9080173
  * 内存映射函数

* **malloc()**
  * 底层调用了mmap()

* Swap
  * 换出与换入 --又称为分页
  * 系统长期内存不足，会导致不断交换，陷入系统抖动状态

## 存储
* 层次结构（容量从大到小，访问速度从慢到快）
  * CSAPP-p421
  * 外部存储器--内存--高速缓存SRAM--寄存器

* **高速缓存**
  * 为了抹平内存与寄存器的性能差距
  * 添加标记，检查脏位

* 多级缓存
  * L1、L2、L3

* 访问局部性
  * 时间局部性
  * 空间局部性

* 页表缓冲
  * 也称为转译后备缓冲区 TLB
* 页面缓存
  * 为了抹平外部存储器与内存的性能差距
  * 脏页的标记
  
* 超线程
