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
			} else if (elem.find(" ", end + 1) < elem.size()) {
				auxWord = elem.substr(end + 1, elem.find(" ", end + 1) - (end + 1));
			} else {
				auxWord = elem.substr(end + 1);
			}
			std::cout << auxWord << "\n";
			chop4(auxPassport, auxWord);
			end = elem.find(" ", end + 1);
		}
	}
	dataSet.push_back(auxPassport);
	std::cout << "\n\n\n\n";
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

std::array<int, 2> run4() {
	std::array<int, 2> returnArray;
	std::vector<Passport> dataSet{ loadData4() };
	int valid{ 0 };
	int valid2{ 0 };
	for (const auto& elem : dataSet) {
		if (elem.isValid1()) {
			valid++;
		}
		if (elem.isValid2()) {
			valid2++;
		}
	}
	returnArray.at(0) = valid;
	returnArray.at(1) = valid2;

	return returnArray;
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
bool Passport::validByr() const {
	if (byr) {
		int value{ std::stoi(*byr) };
		if (value >= 1920 && value <= 2002) return true;
		return false;
	}
	return false;
}

bool Passport::validIyr() const {
	if (iyr) {
		int value{ std::stoi(*iyr) };
		if (value >= 2010 && value <= 2020) return true;
		return false;
	}
	return false;
}

bool Passport::validEyr() const {
	if (eyr) {
		int value{ std::stoi(*eyr) };
		if (value >= 2020 && value <= 2030) return true;
		return false;
	}
	return false;
}

bool Passport::validHgt() const {
	if (hgt) {
		if (hgt->find("cm") != std::string::npos) {
			int value{ std::stoi(hgt->substr(0, 3)) };
			if (value >= 150 && value <= 193) return true;
			else return false;
		} else if (hgt->find("in") != std::string::npos) {
			int value{ std::stoi(hgt->substr(0, 2)) };
			if (value >= 59 && value <= 76) return true;
			else return false;
		}
		return false;
	}
	return false;
}

bool Passport::validHcl() const {
	if (hcl) {
		if (hcl->at(0) == '#') {
			std::string value{ hcl->substr(1) };
			if (value.size() == 6) {
				for (const auto elem : value) {
					if (std::isdigit(elem)) {
						int d{ std::isdigit(elem) };
						if (d < 0 && d > 9) return false;
					} else if (elem < 'a' && elem > 'f') return false;
				}
				return true;
			}
		}
		return false;
	}
	return false;
}

bool Passport::validEcl() const {
	if (ecl) {
		if (*ecl == "amb" || *ecl == "blu" || *ecl == "brn" || *ecl == "gry" || *ecl == "grn" || *ecl == "hzl" || *ecl == "oth") return true;
		return false;
	}
	return false;
}

bool Passport::validPid() const {
	if (pid) {
		if (pid->size() == 9) {
			for (auto elem : *pid) {
				if (!std::isdigit(elem)) return false;
			}
			return true;
		}
		return false;
	}
	return false;
}

bool Passport::isValid1() const {
	if (!byr) return false;
	else if (!iyr) return false;
	else if (!eyr) return false;
	else if (!hgt) return false;
	else if (!hcl) return false;
	else if (!ecl) return false;
	else if (!pid) return false;
	return true;
}

bool Passport::isValid2() const {
	if (!validByr()) return false;
	else if (!validIyr()) return false;
	else if (!validEyr()) return false;
	else if (!validHgt()) return false;
	else if (!validHcl()) return false;
	else if (!validEcl()) return false;
	else if (!validPid()) return false;
	return true;
}