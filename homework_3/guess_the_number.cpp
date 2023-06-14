#include "header.h"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {

    /* 1_Take arguments */ 
    const int maximum_value = argument( argc, argv);
    int target_value, attempts_count;
    std::string current_user_name;

    // Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::cin >> current_user_name;

	/* 2_random_value */ 
    target_value = random_value (maximum_value);

	/* 3_Check_value */ 
    attempts_count = check_value (target_value);

	/* 4_show results */
    high_scores(current_user_name, attempts_count);

	return 0;
}