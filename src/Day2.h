#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <array>


	struct Password {
		unsigned  min;
		unsigned  max;
		char findChar;
		std::string strPass;
	};

	void chop2(std::vector<Password>& dataSet, const std::string& rawData);
	std::vector<Password> loadData2();
	std::array<int,2> run2();

