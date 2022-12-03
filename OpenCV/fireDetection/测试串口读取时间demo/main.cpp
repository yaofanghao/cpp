// 2022.12.3

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <string.h>
#include <ctime>
#include "WzSerialPort.h"
using namespace std;

int main(int argumentCount, const char* argumentValues[]) 
{
	WzSerialPort w;
	clock_t t1,t2,t3; 
	while (true)
	{
		if (w.open("/dev/ttyS0", 115200, 0, 8, 1)){
			// std::cout << "connect to STM32..."<<std::endl;
			t1 = clock();     
			cout << "time1: " <<  1.0*t1/CLOCKS_PER_SEC << " s" << endl;
			
			char buf[1024];   // buf存放接收到的数据		
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
				// printf( "result is \"%s\"\n", result);
				ret = strtod(result, &ptr);
				i++;
				// if (typeid(ret)==typeid(double)){
					// cout << "receive a double number: " << ret << endl;
					// receive_num.push_back(ret);
				// 	i++;
				// }				
				result = strtok( NULL, delims );

				if (i==4){
						cout << "success received!" << endl;					
					}
				}

			}
		else{
			cout << "open serial port failed...";
			return -1;	
		}
	}

	w.close();
	return 0;
} 