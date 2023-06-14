#include <iostream>

int check_value(const int &target_value) {

	int current_value = 0;
	int try_counter = 0; 

	std::cout << "Enter your guess:" << std::endl;
	do {
		std::cin >> current_value;

		if (target_value < current_value) {
			std::cout << "less than " << current_value << ", try again:" << std::endl;
			++try_counter;
		}
		else if (target_value > current_value) {
			std::cout << "greater than " << current_value << ", try again:" << std::endl;
			++try_counter;
		}
		else {
			++try_counter;
			std::cout << "you win!" << " attempts = "<< try_counter << std::endl;
			
			break;
		}

	} while(true);

	return try_counter;

}