cmake_minimum_required(VERSION 3.5)

project(03.homework CXX)

add_executable(guess_the_number 
	header.h
	guess_the_number.cpp
    check_value.cpp
    random_value.cpp
	high_scores.cpp
	argument.cpp
)

set_target_properties(guess_the_number PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON)

target_compile_options(guess_the_number PRIVATE -Wall -Wextra -Werror -pedantic)