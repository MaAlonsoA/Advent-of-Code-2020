#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <array>

std::vector<std::string> loadData3();
std::array<long long, 2> run3();
int slopes(int right, int down, const std::vector<std::string>& dataSet);
