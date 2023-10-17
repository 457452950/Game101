cmake_minimum_required(VERSION 3.10)
project(RayTracing)

set(CMAKE_CXX_STANDARD 17)


add_executable(${PROJECT_NAME} main.cpp Object.hpp Vector.hpp Sphere.hpp global.hpp Triangle.hpp Scene.cpp Scene.hpp Light.hpp Renderer.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -pedantic -fsanitize=undefined)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENCV_LIBRARY})
