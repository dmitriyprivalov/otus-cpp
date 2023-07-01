cmake_minimum_required(VERSION 3.14)

project(07_homework CXX)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)


add_executable(07_homework
    main.cpp
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(07_homework PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(07_homework PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(07_homework PUBLIC cxx_std_17)

enable_testing()

add_subdirectory(gtests)
