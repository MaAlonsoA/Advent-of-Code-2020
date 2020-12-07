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

std::array<int, 2> run1(int expectedSum) {
	std::array<int, 2> returnArray{ 0,0 };
	std::set<int> dataSet{ loadData1() };
	int result{ 0 };

	int searchedNumber{ 0 };
	for (auto elem : dataSet) {
		searchedNumber = expectedSum - elem;
		if (dataSet.find(searchedNumber) != dataSet.end()) {
			returnArray.at(0) = searchedNumber * elem;
			break;
		}
	}
	for (auto elem : dataSet) {
		for (auto elem2 : dataSet) {
			searchedNumber = expectedSum - elem - elem2;
			if (dataSet.find(searchedNumber) != dataSet.end()) {
				returnArray.at(1) = searchedNumber * elem * elem2;
				break;
			}
		}
	}
	return returnArray;
}