#include "Day4.h"
#include <iostream>

void chop4(Passport& object, const std::string_view& rawData) {
	unsigned index{ rawData.find(":") };
	std::string key{ rawData.substr(0, index) };
	std::string value{ rawData.substr(index + 1) };
	object.setAttribute(key, value);
}

void chop4(std::vector<Passport>& dataSet, const std::vector<std::string>& rawData) {
	Passport auxPassport;
	std::string auxWord;
	for (const auto& elem : rawData) {
		int end{ 0 };
		while (end < elem.size()) {
			if (end == 0) {
				auxWord = elem.substr(end, elem.find(" "));
			} else {
				auxWord = elem.substr(end + 1, elem.find(" ") + 1);
			}
			chop4(auxPassport, auxWord);
			end = elem.find(" ", end + 1);
		}
	}
	dataSet.push_back(auxPassport);
}

std::vector<Passport> loadData4() {
	std::ifstream inputFile("./src/inputs/day4.txt");
	std::string data;
	std::vector<std::string> linesVector;
	std::vector<Passport> returnVector;
	if (inputFile.is_open()) {
		while (inputFile) {
			std::getline(inputFile, data);
			if (!data.empty()) {
				linesVector.push_back(data);
			} else {
				chop4(returnVector, linesVector);
				linesVector.clear();
			}
		}
	}
	return returnVector;
}

int run4() {
	std::vector<Passport> dataSet{ loadData4() };
	int valid{ 0 };
	for (const auto& elem : dataSet) {
		if (elem.isValid()) {
			valid++;
		}
	}
	return valid;
}

void Passport::setAttribute(const std::string& key, const std::string& value) {
	if (key == "byr") byr = std::make_shared<std::string>(value);
	else if (key == "iyr") iyr = std::make_shared<std::string>(value);
	else if (key == "eyr") eyr = std::make_shared<std::string>(value);
	else if (key == "hgt") hgt = std::make_shared<std::string>(value);
	else if (key == "hcl") hcl = std::make_shared<std::string>(value);
	else if (key == "ecl") ecl = std::make_shared<std::string>(value);
	else if (key == "pid") pid = std::make_shared<std::string>(value);
	else if (key == "cid") cid = std::make_shared<std::string>(value);
}

bool Passport::isValid() const {
	if (!byr) return false;
	else if (!iyr) return false;
	else if (!eyr) return false;
	else if (!hgt) return false;
	else if (!hcl) return false;
	else if (!ecl) return false;
	else if (!pid) return false;
	return true;
}