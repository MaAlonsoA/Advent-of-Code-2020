#include "Day6.h"

void chop6(	std::vector<std::set<char>>& dataSet, const std::vector<std::string>& linesVector) {
	std::set<char> groupSet;

	for (const auto& word : linesVector) {
		for (const auto& elem : word) {
			groupSet.insert(elem);
		}
	}
	dataSet.push_back(groupSet);
}

std::vector<std::set<char>> loadData6() {
	std::vector<std::set<char>> dataSet;
	std::ifstream inputFile("./src/inputs/day6.txt");
	std::vector<std::string> linesVector;
	std::string data;
	if (inputFile.is_open()) {
		while (inputFile) {
			std::getline(inputFile, data);
			if (!data.empty()) {
				linesVector.push_back(data);
			} else {
				chop6(dataSet, linesVector);
				linesVector.clear();
			}
		}
	} else {	
		throw std::string{ "day6.txt could not be opened" };
	}
	return dataSet;
}

std::array<int, 2> run6() {
	std::vector < std::set<char> >dataSet{ loadData6() };
	std::array<int, 2> returnArray{ 0,0 };
	int result{ 0 };

	for (const auto& elem : dataSet) {
		result += elem.size();
	}
	returnArray.at(0) = result;


	return returnArray;

}
