#include "Day2.h"


void chop2(std::vector<Password>& dataSet, const std::string& rawData) {
	Password tempPassword;
	
	unsigned firstPos{ rawData.find("-") }; 
	unsigned secondPos{ rawData.find(" ") }; //find first space
	unsigned thirdPos{ rawData.find(" ", secondPos + 1) };  //find second space

	tempPassword.min = std::stoi(rawData.substr(0, firstPos));
	tempPassword.max = std::stoi(rawData.substr(firstPos + 1, secondPos - (firstPos + 1)));
	tempPassword.findChar = rawData.at(secondPos + 1);
	tempPassword.strPass = rawData.substr(thirdPos + 1);

	dataSet.push_back(tempPassword);
}

std::vector<Password> loadData2() {
	std::vector<Password>  returnVector;
	std::ifstream inputFile("./src/inputs/day2.txt");

	std::string data;

	if (inputFile.is_open()) {
		while (std::getline(inputFile, data)) {
			chop2(returnVector, data);
		}
	} else {
		throw std::string{ "day1.txt could not be opened" };
	}
	return returnVector;
}


std::array<int, 2> run2() {
	std::array<int, 2> returnArray;
	std::vector<Password> dataSet{ loadData2() };
	int times{ 0 };
	int total{ 0 };
	int total2{ 0 };
	for (auto& elem : dataSet) {
		times = std::count(elem.strPass.begin(), elem.strPass.end(), elem.findChar );
		if (times >= elem.min && times <= elem.max) {
			total++;
		}
		if (elem.strPass.at(elem.min - 1) == elem.findChar && elem.strPass.at(elem.max - 1) != elem.findChar) {
			total2++;
		} else if (elem.strPass.at(elem.min - 1) != elem.findChar && elem.strPass.at(elem.max - 1) == elem.findChar) {
			total2++;
		}
	}
	returnArray.at(0) = total;
	returnArray.at(1) = total2;

	return returnArray;
};

