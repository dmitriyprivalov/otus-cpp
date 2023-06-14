#pragma once

#include <string>

int argument(int argc, char** argv);

int random_value(const int &maximum_value);

int check_value(const int &target_value);

int high_scores(const std::string &current_user_name, const int &attempts_count);