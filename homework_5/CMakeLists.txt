cmake_minimum_required(VERSION 3.5)

# project(05.homework)

# add_executable(random_shuffle random_shuffle.cpp)
# set_target_properties(random_shuffle PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED OFF)

# add_executable(chrono_example chrono_example.cpp)
# set_target_properties(chrono_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED OFF)

# add_executable(statistics statistics.cpp)
# set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.10)

project(05_homework CXX)

add_executable(05_homework
    statistics.cpp
)

# target_include_directories(calc PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(05_homework PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(05_homework PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(05_homework PUBLIC cxx_std_17)
