cmake_minimum_required(VERSION 3.1)

project( fire )

set(CMAKE_CXX_FLAGS "$(CMAKE_CXX_FLAGS) -std=c++11 -O3")

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( fire fireDetecion.cpp )

target_link_libraries( fire ${OpenCV_LIBS} )

SET(CMAKE_BUILD_TYPE "Debug")
