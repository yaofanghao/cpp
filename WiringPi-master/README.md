# 基于wiringPi的串口通信
* 时间：2022.11.20

http://wiringpi.com/
https://www.electronicwings.com/raspberry-pi/raspberry-pi-uart-communication-using-python-and-c
https://roboticsbackend.com/introduction-to-wiringpi-for-raspberry-pi/
https://www.bilibili.com/read/cv8344099
https://blog.csdn.net/www_xuhss_com/article/details/124071653
https://blog.csdn.net/weixin_49638344/article/details/119955742


# 实现过程的简要记录
## 树莓派环境配置
* git clone https://github.com/WiringPi/WiringPi.git
* cd ~/wiringPi
* ./build
* sudo nano /boot/cmdline.txt
// 删除 console=serial0,115200
* sudo vim /boot/config.txt
// 输入：
dtoverlay=uart2
dtoverlay=uart3
dtoverlay=uart4
dtoverlay=uart5
* sudo reboot
* ls /dev/ttyAMA* // 显示为/dev/ttyAMA0~4 共五个串口，成功
* 接线方式：
  * CH340的TX 和 树莓派GPIO15(引脚10)相连
  * CH340的RX 和 树莓派GPIO14(引脚8)相连
  * GND和树莓派任一GND(如引脚6或14】)相连共地。

## demo
* main.cpp
```c
#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int main()
{
	char buf[64] = {'\0'};
	int n_read;
	wiringPiSetup();
	
	int fd =serialOpen("/dev/ttyS0",115200); //打开串口
	
	if(fork() == 0){
		while(1){
			n_read = read(fd,buf,sizeof(buf));
			if(n_read != 0){
				printf("data %dB:%s\n",n_read,buf); //子进程一直等待数据接收
			}	
		}
	}else{
			while(1){
				serialPrintf(fd,"hello world!!\n"); //每隔三秒发送一次hello world!!
				delay(3000);
			}
	}
 
	return 0;
}
```
* CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 2.6)
add_definitions( -lwiringPi  )
project(test_wiringpi)
#find_package(OpenCV REQUIRED)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
add_executable(test_main main.cpp)
#target_link_libraries(test_main ${OpenCV_LIBS})
target_link_libraries(test_main ${WIRINGPI_LIBRARIES}  -lpthread) 
```

## 11.20
* 目前未完成，无法正常接收发送数据

## 11.22
* 修改了串口，应使用ttyS0，硬件确保接线正确，成功实现树莓派和电脑通信

## 11.23
* 暂时不使用该wiringPi库，转为cppLinuxSerial实现树莓派的串口通信，具体请见CppLinuxSerial_demo文件夹