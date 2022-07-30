cmake_minimum_required(VERSION 2.8)

project(testopenni)

include_directories($ENV{OPENNI2_INCLUDE})
link_directories($ENV{OPENNI2_REDIST})
message($ENV{OPENNI2_INCLUDE})
message($ENV{OPENNI2_REDIST})
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} opennitest.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} libOpenNI2.so )

