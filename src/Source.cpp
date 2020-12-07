#include <iostream>

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"

int main() {
	try {
		std::cout << "Day 1 solution: " << run1(2020) << "\n";
	} catch (const std::string& errorMsg) {
		std::cout << errorMsg;
	}
	try {
		std::cout << "Day 2 solution: " << run2().at(0) << "\n";
		std::cout << "Day 2 second solution: " << run2().at(1) << "\n";
	} catch (const std::string& errorMsg) {
		std::cout << errorMsg;
	}
	try {
		std::cout << "Day 3 solution: " << run3().at(0) << "\n";
		std::cout << "Day 3 second solution: " << run3().at(1) << "\n";
	} catch (const std::string& errorMsg) {
		std::cout << errorMsg;
	}
	try {
		std::cout << "Day 4 solution: " << run4() << "\n";
	} catch (const std::string& errorMsg) {
		std::cout << errorMsg;
	}

	return 0;
}