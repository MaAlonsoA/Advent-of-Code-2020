#include "Day3.h"

std::vector<std::string> loadData3() {
	std::vector<std::string> returnVector;

	std::ifstream imputFile("./src/inputs/day3.txt");

	std::string data;

	if (imputFile.is_open()) {
		while (std::getline(imputFile, data)) {
			returnVector.push_back(data);
		}
	} else {
		throw std::string{ "day3.txt could not be opened" };
	}
	return returnVector;
}

int run3() {
	std::vector<std::string> dataSet{ loadData3() };
	int count{ 0 };
	int place{ 0 };
	for (int i = 0; i < dataSet.size(); i++) {
		if (dataSet.at(i).at(place) == '#') {
			count++;
		}
		if (place + 3 < dataSet.at(i).size()) {
			place += 3;
		} else {
			place = (place + 3) - dataSet.at(i).size();
		}
	}
	return count;
}