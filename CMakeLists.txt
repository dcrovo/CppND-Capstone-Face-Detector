cmake_minimum_required(VERSION 3.7)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(OpenCV 4.1 REQUIRED)
#Include Opencv directories
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

project(face_detector)

# Find all executables
file(GLOB project_SRCS src/*.cpp) 

# Add project executable
add_executable(face_detector ${project_SRCS})
target_link_libraries(face_detector ${OpenCV_LIBRARIES})



