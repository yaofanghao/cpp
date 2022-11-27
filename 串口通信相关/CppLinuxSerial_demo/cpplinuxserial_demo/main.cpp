// 2022.11.24
// 参考资料

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
	std::cout << "Start receive data." << std::endl;
	while(1){
		// std::cout << "Start receive data:" << std::endl;		
		std::string readData;	
		std::string readData_string;  
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
