cmake_minimum_required(VERSION 3.1)

project( fire )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message(STATUS "TARGET ARCH ABI: ${TARGET_ARCH_ABI}")
message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")

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

include_directories(${PROJECT_SOURCE_DIR}/external_module)
add_subdirectory (external_module) 
add_executable(fire fireDetecion.cpp)

target_link_libraries(fire ${OpenCV_LIBS} external_module)

SET(CMAKE_BUILD_TYPE "Debug")
