# opencv for vscode 的标准模板
cmake_minimum_required(VERSION 3.1)

project( test )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 设置成包含OpenCVconfig.cmake所在的路径
set(OpenCV_DIR E:\\OpenCV\\opencv\\build)

message(STATUS "TARGET ARCH ABI: ${TARGET_ARCH_ABI}")
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")

# E:\\OpenCV\\opencv\\build
find_package(OpenCV REQUIRED) 
if(OpenCV_FOUND OR OpenCV_CXX_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    message(STATUS "OpenCV library status:")
    message(STATUS "    version: ${OpenCV_VERSION}")
    message(STATUS "    libraries: ${OpenCV_LIBS}")
    message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "Could not found OpenCV!")
    return()
endif()

add_executable(test 2_8_ImagePyramids.cpp)

target_link_libraries(test ${OpenCV_LIBS})

