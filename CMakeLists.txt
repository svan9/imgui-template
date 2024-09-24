# 2024

cmake_minimum_required(VERSION 3.15)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(project imgui-study)
project(${project} VERSION 1.0)

if (WIN32)
    set(glfw3_DIR ${CMAKE_SOURCE_DIR}/submodules/imgui/examples/libs/glfw)

    include_directories(${glfw3_DIR}/include)
    link_directories(${CMAKE_SOURCE_DIR}/submodules/lib/lib-mingw-w64)
else ()
    find_package(glfw3 REQUIRED CONFIG)
endif ()

set(GL3W_DIR ${CMAKE_BINARY_DIR}/submodules/gl3w)
set(HEADER_DIR ${GL3W_DIR}/include)

#build imgui libs
add_subdirectory(submodules)

if (WIN32)
   set(glfw_lib glfw3)
   set(windows_lib "")
else ()
   set(glfw_lib glfw)
endif ()

#original cmake example
include_directories(${GL3W_DIR}/include)
add_subdirectory(src)