cmake_minimum_required(VERSION 3.10)
project(class2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O1  -Wall")

add_executable(${PROJECT_NAME} main.cpp rasterizer.hpp rasterizer.cpp Triangle.hpp Triangle.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES} fmt::fmt Eigen3::Eigen)
