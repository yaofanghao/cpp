<!--
 * @Author: yao fanghao
 * @Date: 2023-04-14 22:13:52
 * @LastEditTime: 2023-04-23 11:41:47
 * @LastEditors: yao fanghao
-->

# 参考资料

* **<https://learn.microsoft.com/en-us/cpp/?view=msvc-170>**
* **<https://google.github.io/styleguide/cppguide.html>**
* **C++Primer**
* 嵌入式软件开发笔试面试指南
* linux/unix系统编程手册
* **APUE**
* 剑指offer √
* C专家编程 √
* **STL源码剖析**
* 现代C++语言核心特性解析
* 王道-数据结构
* 【史上最强最细腻的linux嵌入式C语言学习教程【李慧芹老师】】 <https://www.bilibili.com/video/BV18p4y167Md>
* 【《C++ Primer 第五版》】 <https://www.bilibili.com/video/BV1z64y1U7hs>
* 【黑马程序员-Linux网络编程】 <https://www.bilibili.com/video/BV1iJ411S7UA>
* 【彻底搞懂 进程&线程、进程池&线程池】 <https://www.bilibili.com/video/BV1V84y1Y77s>

# C / C++ 基本概念

* 字符串默认每个占用1字节，末尾还要加上\0

* 左值和右值
  * 左值lvalue 指向内存位置，可以被修改
  * 右值rvalue 指向存储在内存的数值
* 短路求值

* 位运算
  * 把操作数第n位置1，其他不变 num = num | 1<<n;
  * 把操作数第n为清零，其他不变 num = num &~ (1<<n);

* **const**
  * 不可改变值
  * 约束某些内容不可更改
* const float pi = 3.14
  * 指定常量，同时指定了类别
* **指针常量和常量指针**
  * const int *p
  * int const *p
  * int *const p

* static
  * 默认初始化为0
  * 只用一块空间
  * 只能在本文件中使用
  * 可以在函数调用间保持局部变量值
  * 可以定义静态成员和静态成员函数
* 变量作用范围
  * 内部屏蔽外部
* extern
  * 扩大了作用范围
  * 可以用于另一个文件中声明全局变量或函数
* extern const
  * 在另一文件中引用const常量
* extern"C"
  * 使编译器对这部分按照C语言进行编译

* struct 和 union
  * struct 按最大成员的size或其size的整数倍对齐
  * union有数据对齐

* 静态库 动态库
  * 静态库
    * libxx.a
    * 是先吃撑了，防止之后饿
  * 动态库
    * libxx.so
    * 是把粮食带着，等饿了再吃

* size_t
  * 表示C中任何对象所能达到的最大长度，是无符号整数

* 声明和定义
  * 声明不分配空间
  * 声明可以有多个，定义只有一个

* inline 内联函数
  * 用于频繁被调用的函数中
  * 以空间换时间

* namespace
  * 区分不同库中的相同函数、变量等

# 面向对象

* 类成员默认为私有 private
  
* 友元函数 friend
  
* this指针
  
* 多继承

* 多态
  * virtual 虚函数
  * 晚绑定
  * 纯虚函数 virtual .... = 0
  
* 深拷贝 浅拷贝
  * 深拷贝在析构时，各自对象占用资源不会冲突

# C++ 新特性

* 异常处理
  * try ... catch
  * throw

* 动态内存
  * new delete
  * malloc需要人为计算申请内存大小，而new可以自动计算申请内存大小
  * realloc
  * new分配的内存块保存在**堆区**

* 内存管理
  * CSAPP-p587
  * 代码段 数据段 BSS段 堆区 文件映射区 栈区
  * 栈区：编译器自动分配管理 存放局部变量
  * 堆区：程序员分配和管理

* **智能指针**
  * unique_ptr、shared_ptr、weak_ptr
  * 解决了内存泄漏（忘记释放）、二次释放等问题

* STL
  * 容器 算法 迭代器

* auto

* decltype

* labmda表达式

* 并行编程 #include <thread>
  * join()
  * detach()
