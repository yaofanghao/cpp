cmake_minimum_required(VERSION 3.1)

project( fire )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( fire test.cpp )

target_link_libraries( fire ${OpenCV_LIBS} )

SET(CMAKE_BUILD_TYPE "Debug")
