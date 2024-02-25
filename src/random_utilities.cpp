#include "../include/random_utilities.h"

float get_random_between(float a, float b) {
	std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(a, b);	
    return distr(eng);
}