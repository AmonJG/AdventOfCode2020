#include "AdventOfCodeTask.h"
#include "iostream"

AdventOfCodeTask::AdventOfCodeTask()
{
}

std::ifstream AdventOfCodeTask::GetInput(std::string const& inputPath)
{
	return std::ifstream(inputPath);
}

std::string AdventOfCodeTask::GetInputAsString(std::string const& inputPath)
{
	std::ifstream entrystream(inputPath);
	std::string content((std::istreambuf_iterator<char>(entrystream)),
		(std::istreambuf_iterator<char>()));
	return content;
}
