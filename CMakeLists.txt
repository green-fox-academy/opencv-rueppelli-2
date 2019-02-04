cmake_minimum_required(VERSION 3.12)
project(Computer_Vision)

set(CMAKE_CXX_STANDARD 14)


set(OpenCV_DIR $ENV{OPENCV_DIR})
set(SQLITE3_DIR $ENV{SQLite3})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
find_package(SQLITE3 REQUIRED)

add_executable(Computer_Vision main.cpp)

include_directories(src)
include_directories($ENV{SQlite3_inc})
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(src)
add_subdirectory(gtest)


if(WIN32)
    target_link_libraries(Computer_Vision ${OpenCV_LIBS} source_files sqlite3::sqlite3)
else()
    target_link_libraries(Computer_Vision ${OpenCV_LIBS} source_files sqlite3 dl)
endif()
