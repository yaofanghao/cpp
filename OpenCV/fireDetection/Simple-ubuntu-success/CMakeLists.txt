# cmake needs this line
cmake_minimum_required(VERSION 3.1)

message(STATUS "${CMAKE_SYSTEM_NAME}")
message(STATUS "TARGET ARCH ABI: ${TARGET_ARCH_ABI}")


# Define project name
project(fire_test)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(${PROJECT_SOURCE_DIR}/external_module)
add_subdirectory (external_module) 

add_executable(fire_test fireDetection-camera.cpp)

target_link_libraries(fire_test PRIVATE ${OpenCV_LIBS} external_module)
