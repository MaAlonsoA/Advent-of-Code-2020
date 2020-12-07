#pragma once
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <array>
struct Passport {
	std::shared_ptr<std::string> byr;
	std::shared_ptr<std::string> iyr;
	std::shared_ptr<std::string> eyr;
	std::shared_ptr<std::string> hgt;
	std::shared_ptr<std::string> hcl;
	std::shared_ptr<std::string> ecl;
	std::shared_ptr<std::string> pid;
	std::shared_ptr<std::string> cid;

	void setAttribute(const std::string& key, const std::string& value);
	bool validByr() const;
	bool validIyr() const;
	bool validEyr() const;
	bool validHgt() const;
	bool validHcl() const;
	bool validEcl() const;
	bool validPid() const;

	bool isValid1() const;
	bool isValid2() const;
};

void chop4(std::vector<Passport>& dataSet, const std::vector<std::string>& rawData);
void chop4(Passport& object, const std::string_view& rawData);

std::vector<Passport> loadData4();

std::array<int, 2> run4();
