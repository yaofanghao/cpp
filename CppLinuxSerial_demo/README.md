# 基于CppLinuxSerial的串口通信
* 时间：2022.11.22-

# 实现过程的简要记录
## 树莓派环境配置
* git clone https://github.com/gbmhunter/CppLinuxSerial.git
* cd CppLinuxSerial
* mkdir build
* cd build
* cmake ..
* make
* sudo make install

## demo
* demo已在树莓派4b该路径下实现
	/home/pi/cpplinuxserial_test/build/serial_test
* main.cpp
```cpp
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

	cout << "serial open"<<endl;

	// Write some ASCII data
	serialPort.Write("Hello");

	// Read some data back (will block until at least 1 byte is received due to the SetTimeout(-1) call above)
	std::string readData;
	serialPort.Read(readData);

	// Close the serial port
	serialPort.Close();
	cout << "serial close" <<endl;
}
```
* CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
set(CMAKE_SYSTEM_NAME Linux)
project(serial_test)
message(STATUS "TARGET ARCH ABI: ${TARGET_ARCH_ABI}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(serial_test main.cpp)
target_link_libraries(serial_test -lCppLinuxSerial)
```

## 11.22
* 修改了串口，应使用ttyS0，硬件确保接线正确，成功实现树莓派与电脑通信

## 11.23
* 增加了一些功能