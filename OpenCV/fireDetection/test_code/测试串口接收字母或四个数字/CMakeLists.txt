cmake_minimum_required(VERSION 3.1)
set(CMAKE_SYSTEM_NAME Linux)

project( test )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if(TARGET_ARCH_ABI STREQUAL "armv8")
    set(CMAKE_CXX_FLAGS "-march=armv8-a ${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "-march=armv8-a ${CMAKE_C_FLAGS}")
elseif(TARGET_ARCH_ABI STREQUAL "armv7l")
    set(CMAKE_CXX_FLAGS "-march=armv7-a -mfloat-abi=hard -mfpu=neon-vfpv4 ${CMAKE_CXX_FLAGS}")
    set(CMAKE_C_FLAGS "-march=armv7-a -mfloat-abi=hard -mfpu=neon-vfpv4 ${CMAKE_C_FLAGS}" )
endif()

include_directories(${PROJECT_SOURCE_DIR}/external_module)
add_subdirectory (external_module) 
add_executable(test main.cpp)

target_link_libraries(test external_module)

