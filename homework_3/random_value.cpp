#include <iostream>

#include <cstdlib>
#include <ctime>

int random_value(const int &maximum_value) {

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % maximum_value;

	//std::cout << random_value << std::endl;

	return random_value;
}