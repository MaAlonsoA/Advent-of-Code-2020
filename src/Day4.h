#pragma once
#include <fstream>
#include <string>
#include <memory>
#include <vector>

struct Passport {
	std::shared_ptr<std::string> byr;
	std::shared_ptr<std::string> iyr;
	std::shared_ptr<std::string> eyr;
	std::shared_ptr<std::string> hgt;
	std::shared_ptr<std::string> hcl;
	std::shared_ptr<std::string> ecl;
	std::shared_ptr<std::string> pid;
	std::shared_ptr<std::string> cid;
};

void chop4(std::vector<Passport>& dataSet, const std::string& rawData);
std::vector<Passport> loadData4();
int run4();

