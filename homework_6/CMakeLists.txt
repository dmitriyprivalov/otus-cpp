cmake_minimum_required(VERSION 3.10)

project(06_homework CXX)

add_executable(06_homework
    containers.cpp
)

# target_include_directories(calc PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(06_homework PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(06_homework PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(06_homework PUBLIC cxx_std_17)
