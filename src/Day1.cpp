#include "Day1.h"

std::set<int> loadData1() {
	std::set<int> returSet;
	std::ifstream inputFile("./src/inputs/day1.txt");
	if (inputFile.is_open()) {
		int data{ 0 };
		while (inputFile) {
			inputFile >> data;
			returSet.insert(data);
		}
	} else {
		throw std::string{ "day1.txt could not be opened" };
	}
	return returSet;
}

int run1(int expectedSum) {
	std::set<int> dataSet{ loadData1() };

	int searchedNumber{ 0 };
	for (auto elem : dataSet) {
		searchedNumber = expectedSum - elem;
		if (dataSet.find(searchedNumber) != dataSet.end()) {
			return searchedNumber * elem;
		}
	}
	return -1;
}