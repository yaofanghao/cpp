#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <ctime>
#include "WzSerialPort.h"

using namespace std;

// 测试接收到的数据：
// 第一种：A
// 第二种：四个数字
int main()
{
	WzSerialPort w;
	if (w.open("/dev/ttyS0", 115200, 0, 8, 1)){
		// w.send("helloworld ", 10);
		std::cout << "connect to STM32... wait for serial open" << std::endl;

		char buf[1024];   // buf存放接收到的数据
		while (true){
			memset(buf, 0, 1024);
			w.receive(buf, 1024);
			// cout << buf;			

            if(*buf == 'A'){
				cout << "-------------------" << endl;
 				cout << "received " << buf;
                cout << "start image processing..." << endl;                

                // 关闭串口
				// 打开摄像头。。。不要设置保存视频了，会很复杂
                // 调用图像处理模块。。。。
				// 处理完成，获得vector<double> processing_result后，打开串口

            }
            else{                            
		        std::vector<double> receive_num; 
                char delims[] = " ";
                char* result = NULL;
                char* ptr;
                double ret;
                result = strtok(buf, delims);	// 收到的字符串按空格作为割
                int i = 0;                
                while (result != NULL) {
                	// printf("result is \"%s\"\n", result);
                	ret = strtod(result, &ptr);
                	if (typeid(ret) == typeid(double)) {
                		//cout << "receive a double number: " << ret << endl;
                		receive_num.push_back(ret);
                		i++;
                	}
                	result = strtok(NULL, delims);

                	if (i == 4) {	
						cout << "-------------------" << endl;			
                		cout << "received " << endl;
                        for (auto i : receive_num) {
						    cout << i << " ";
                        }
                        cout << endl;
						cout << "start SVM model predict..." << endl;
                        // w.close();

                	}
                }         
                  

            }


		}
	}
	else {
		cout << "open serial port failed...";
	}
	w.close();
	return 0;	




}






