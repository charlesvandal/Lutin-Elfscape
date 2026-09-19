cmake_minimum_required(VERSION 3.28)

project(Elf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(Src)

add_executable(elf main.cpp)

target_link_libraries(elf
PRIVATE
CORE_LIBRARY
Qt6::Widgets
)
