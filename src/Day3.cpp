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

int slopes(int right, int down, const std::vector<std::string>& dataSet) {
	int count{ 0 };
	int place{ 0 };
	for (int i = 0; i < dataSet.size(); i += down) {
		if (dataSet.at(i).at(place) == '#') {
			count++;
		}
		if (place + right < dataSet.at(i).size()) {
			place += right;
		} else {
			place = (place + right) - dataSet.at(i).size();
		}
	}
	return count;
}

std::array<long long, 2> run3() {
	std::array<long long, 2> returnArray{ 0,0 };
	std::vector<std::string> dataSet{ loadData3() };
	returnArray.at(0) = slopes(3, 1, dataSet);
	long long result{ returnArray.at(0) };
	result *= slopes(1, 1, dataSet);
	result *= slopes(5, 1, dataSet);
	result *= slopes(7, 1, dataSet);
	result *= slopes(1, 2, dataSet);

	returnArray.at(1) = result;
	return returnArray;
}