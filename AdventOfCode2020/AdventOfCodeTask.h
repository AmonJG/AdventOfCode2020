#pragma once
#include <string>
#include <sstream>
#include <fstream>

class AdventOfCodeTask
{
public:
	AdventOfCodeTask();

protected:
	std::ifstream GetInput(std::string const& inputPath);
	std::string GetInputAsString(std::string const& inputPath);
};
