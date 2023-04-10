# 参考资料
* 网络是怎样连接的 
* 计算机网络-自顶向下方法
* 计算机网络-谢希仁
* 王道-计算机网络 
* https://mp.weixin.qq.com/s/M1ZuZPdKnoXEpBmdNFgmZQ
  
# TCP基本认识
* ![](images/../_images/TCP/1.png "TCP报文格式")
* 序列号：解决网络包乱序问题
* 确认应答号：解决丢包问题
* 控制位：
  * ACK 
  * RST
  * SYN
  * FIN
* ![](images/../_images/TCP/2.png "UDP报文格式")

# TCP三次握手
* ![](images/../_images/TCP/3.png "")
* ![](images/../_images/TCP/3-1.png "")
* ![](images/../_images/TCP/3-2.png "")
* ![](images/../_images/TCP/3-3.png "")
* 第三次握手可以携带数据，前两次握手不可以携带数据
* netstat -napt 命令查看TCP连接状态
* 三次握手才可以阻止重复历史连接的初始化（主要原因）
* ![](images/../_images/TCP/3-4.png "")
* 三次握手才可以同步双方的初始序列号
* 三次握手才可以避免资源浪费

# Socket编程
* ![](images/../_images/TCP/4.png "")