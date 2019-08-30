cmake_minimum_required(VERSION 2.8)

project(png_loader)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "png_drawer.cpp" "png_drawer.h")
