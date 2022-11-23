#include <CppLinuxSerial/SerialPort.hpp>

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

	// Write some ASCII data
	std::cout << "Send data: Hello " << std::endl;
	serialPort.Write("Hello");

	// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	// std::string readData;
	// serialPort.Read(readData);
	// Read some data back
    std::cout << "Start receive data, enter 1 to exit:" ;
	while(1) {
        std::string readData;
        serialPort.Read(readData);
        std::cout << "Received data: " << readData << std::endl;

		string str1 = "abc";	
		if (str1.compare(readData)==0)
		{
			std::cout << "Received data is: " << readData ;				
			std::cout << " .Start fire detection! " << std::endl;
			// put processing(Mat frame) for fire detection			
		}
		else
		{
			std::cout << "Received data is: " << readData ;
			std::cout << " .Fail to start!" << std::endl;
			std::cout << "Enter 'exit' to exit" << std::endl
		}		

		char x = 0;
		cin >> x;
		if (x == "exit")
		{
			std::cout << "Stop receive data!" << std::endl;
			break;
		}
    }

	// Close the serial port
	serialPort.Close();
	std::cout << "serial close" << std::endl;
}
