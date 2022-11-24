// 2022.11.24
// 参考资料
// https://github.com/satyamss7/UWB_with_VSOMEIP/blob/a5ac18785a07c4ce8f5ddb1ac0cb9c28e15ea41b/serialport.cpp
// https://github.com/harunkurtme/python_cpp_struct/blob/b3b00e7acf100635c688a857ea19433769c61a50/cpp/example1.cpp
// https://github.com/FirYuen/usbRelay/blob/19733781bcff997915a72b54afca69db3fb08cc9/src/main.cpp
// https://blog.csdn.net/weixin_44353958/article/details/104156394

#include <cstring>
#include <CppLinuxSerial/SerialPort.hpp>
#include <string>

using namespace std;
using namespace mn::CppLinuxSerial;

int main() {
	// Create serial port object and open serial port at 57600 buad, 8 data bits, no parity bit, one stop bit (8n1),
	// and no flow control"
	SerialPort serialPort("/dev/ttyS0", BaudRate::B_115200, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
	// Use SerialPort serialPort("/dev/ttyACM0", 13000); instead if you want to provide a custom baud rate
	serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	std::cout << "serial open"<< std::endl;
	std::cout << "----------------"<< std::endl;

	// Write some ASCII data
	std::cout << "Send data: Hello " << std::endl;
	serialPort.Write("Hello");
	std::cout << "----------------"<< std::endl;	

	// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	// Read some data back   
	std::cout << "Enter [y] to start receive data." << std::endl;
	char x = 0;
	cin >> x;	
	string readData_string;  
	switch(x){
		case 'y':{
			while(1){
			// std::cout << "Start receive data:" << std::endl;		
			std::string readData;
			serialPort.Read(readData);
			std::cout << "Received data: " << readData << std::endl;
			readData_string.append(readData);
			
			// string str1 = "abc";	
			// if (str1.compare(readData)==0)
			// {
			// 	std::cout << "Received data is: " << readData ;				
			// 	std::cout << " .Start fire detection! " << std::endl;
			// 	// put fire detection functions here			
			// }

			string str1 = " ";	
			if (str1.compare(readData)==0){
				std::cout << "Stop receive data!" << std::endl;
				std::cout << "Finally, received data: " << readData_string << std::endl;

				// Close the serial port
				serialPort.Close();
				std::cout << "----------------"<< std::endl;
				std::cout << "serial close" << std::endl;				
				return 0;			
				}
			}
		}

		default:{
			std::cout << "Failed to start receive data!"<< std::endl;
			return 0;
		}
	}  
}
