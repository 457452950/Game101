cmake_minimum_required(VERSION 3.20)
project(BezierCurve)

set(CMAKE_CXX_STANDARD 14)

add_executable(BezierCurve main.cpp)

target_link_libraries(BezierCurve ${OpenCV_LIBRARIES})
