cmake_minimum_required(VERSION 3.1)
set(CMAKE_SYSTEM_NAME Linux)
project(wzserial_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/external_module)
add_subdirectory (external_module) 
add_executable(wzserial_test main.cpp)

target_link_libraries(wzserial_test ${OpenCV_LIBS} external_module)
