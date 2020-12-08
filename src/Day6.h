#pragma once
#include <vector>
#include <set>
#include <fstream>
#include <string>
#include <array>

void chop6(std::vector<std::set<char>>& dataSet, const std::vector<std::string>& linesVector);
std::vector<std::set<char>> loadData6();

std::array<int, 2> run6();
