cmake_minimum_required(VERSION 3.10)
project(tuple)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED)
add_executable(tuple main.cpp)
target_link_libraries(tuple Boost::headers)