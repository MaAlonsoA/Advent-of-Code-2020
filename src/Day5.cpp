#include "Day5.h"

int decodeRow(int min, int max, const std::string& row, int index) {
	if (index == row.size() - 1) return row.at(index) == 'F' ? min : max;
	return row.at(index) == 'F' ? decodeRow(min, max - (max - min) / 2 - 1, row, index + 1) : decodeRow((min + (max - min) / 2) + 1, max, row, index + 1);
}

int decodeColumn(int min, int max, const std::string& column, int index) {
	if (index == column.size() - 1) return column.at(index) == 'L' ? min : max;
	return column.at(index) == 'L' ? decodeColumn(min, max - (max - min) / 2 - 1, column, index + 1) : decodeColumn(min + (max - min) / 2 + 1, max, column, index + 1);
}

void chop5(std::set<int>& dataVector, const std::string& rawData) {
	std::string row{ rawData.substr(0,7) };
	std::string column{ rawData.substr(7) };
	int irow = decodeRow(0, 127, row, 0);
	int icolumn = decodeColumn(0, 7, column, 0);
	int seat = irow * 8 + icolumn;
	dataVector.insert(seat);
}

std::set<int> loadData5() {
	std::set<int> returnVector;
	std::fstream inputFile("./src/inputs/day5.txt");
	std::string data;
	int i{ 0 };
	if (inputFile.is_open()) {
		while (std::getline(inputFile, data)) {
			chop5(returnVector, data);
		}
	}
	return returnVector;
}

std::array<int, 2> run5() {
	std::array<int, 2> returnArray{ 0 , 0 };
	std::set<int> dataSet{ loadData5() };
	returnArray.at(0) = *dataSet.rbegin();
	return returnArray;
}