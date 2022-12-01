// 2022.12.1
// convert char to double --stod() 
// change mode for read double num
// read 4 char from STM32 and process for SVM in raspberrypi4B

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <string.h>
#include "WzSerialPort.h"
using namespace std;

int main(int argumentCount, const char* argumentValues[]) 
{
	WzSerialPort w;
	if (w.open("/dev/ttyS0", 115200, 0, 8, 1))
	{
		w.send("helloworld ", 10);
		std::cout << "connect to STM32..."<<std::endl;
		
		char buf[1024];   // buf存放接收到的数据
		vector<double> receive_num;  // 将接收到的四个数据存放至此，格式为double

		while (true)
		{
			memset(buf, 0,1024);
			w.receive(buf, 1024);
			cout<<buf;

			char delims[] = " ";
			char *result = NULL;
			char *ptr;
			double ret;

			result = strtok(buf, delims);	// 收到的字符串按空格作为割
			int i = 0;
			while( result != NULL ) {
				printf( "result is \"%s\"\n", result);
				ret = strtod(result, &ptr);
				if (typeid(ret)==typeid(double)){
					cout << "receive a double number: " << ret << endl;
					receive_num.push_back(ret);
					i++;
				}				
				result = strtok( NULL, delims );

				if (i==4){
					cout << "success received!" << endl;

					// 基于vecotr迭代器读取数据，用于后续SVM模型的处理
					for (auto i:receive_num){
						if (typeid(i)==typeid(double)){
							cout << "receive num is: " << i << endl;
						}
						else{
							cout << i << "is not a number" << endl;
							return -1;
						}
					}

					// 读完四个数关闭串口，后续可以优化
					cout << "close serial!" << endl;
					w.close();
					return 0;					
				}
			}
			// else { 
			// 	cout << "fail" << endl;
			// }
		}
	}
	else{
		cout << "open serial port failed...";
		return -1;
	}

	w.close();
	return 0;
} 
