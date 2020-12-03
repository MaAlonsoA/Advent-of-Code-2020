#include <iostream>

#include "Day1.h"

int main() {

	try {
		 std::cout << "Day 1 solution: " << day1(2020) << "\n";
	} catch (const std::string& errorMsg) {
		std::cout << errorMsg;
	}
	
	return 0;
}