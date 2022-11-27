// 2022.11.27
// convert char to double --stod() 
// change mode for read double num

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <typeinfo>
#include "WzSerialPort.h"

using namespace std;

void sendDemo()
{
	WzSerialPort w;
	if (w.open("/dev/ttyS0", 115200, 0, 8, 1))
	{
		for (int i = 0;i < 10;i++)
		{
			w.send("helloworld ", 10);
		}
		cout << "send demo finished..."<<endl;
		w.close();
	}
	else{
		cout << "open serial port failed...";
	}
}

void receiveDemo()
{
	WzSerialPort w;
	if (w.open("/dev/ttyS0", 115200, 0, 8, 1))
	{
		char buf[1024];
		while (true)
		{
			memset(buf, 0,1024);
			w.receive(buf, 1024);
			cout<<buf;
		}
	}
	else{
		cout << "open serial port failed...";
	}
}

int main(int argumentCount, const char* argumentValues[]) 
{
	sendDemo();

	// receiveDemo();
	WzSerialPort w;
	if (w.open("/dev/ttyS0", 115200, 0, 8, 1))
	{
		char buf[1024];
		double num_of_buf = 0.0;

		while (true)
		{
			memset(buf, 0,1024);
			w.receive(buf, 1024);
			cout<<buf;
			
			num_of_buf = strtod(buf,NULL);
			if (typeid(num_of_buf)==typeid(double) && num_of_buf!=0){
				cout << "receive a double number: " << num_of_buf << endl;
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