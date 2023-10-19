cmake_minimum_required(VERSION 3.20)
project(class3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O1  -Wall")


add_executable(
        ${PROJECT_NAME}
        main.cpp
        rasterizer.hpp
        rasterizer.cpp
        global.hpp
        Triangle.hpp
        Triangle.cpp
        Texture.hpp
        Texture.cpp
        Shader.hpp
        OBJ_Loader.h
)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES} fmt::fmt Eigen3::Eigen)
#target_compile_options(Rasterizer PUBLIC -Wall -Wextra -pedantic)