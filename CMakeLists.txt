cmake_minimum_required(VERSION 3.26)
project(game101)

set(VCPKG_FEATURE_FLAGS "version")          # 用于支持自定义依赖版本
set(CMAKE_CXX_STANDARD 17)

find_package(opencv CONFIG REQUIRED)
if (OPENCV_FOUND)
    message(STATUS "opencv found")
else ()
    message(FATAL_ERROR "opencv not found")
endif ()

find_package(Eigen3 CONFIG REQUIRED)

find_package(fmt CONFIG REQUIRED)


include_directories(
        ${OPENCV_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIRS}
        ${FMT_INCLUDE_DIRS}
)

add_subdirectory(class1)
add_subdirectory(class2)
add_subdirectory(class3)
add_subdirectory(class4)
add_subdirectory(class5)
add_subdirectory(class7)
