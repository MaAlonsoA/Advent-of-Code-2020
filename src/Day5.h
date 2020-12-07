#pragma once
#include <set>
#include <array>
#include <fstream>
#include <string>
#include <iostream>

int decodeRow(int min, int max, const std::string& row, int index);
int decodeColumn(int min, int max, const std::string& column, int index);
void chop5(std::set<int>& dataVector, const std::string& rawData);
std::set<int> loadData5();
std::array<int, 2> run5();
