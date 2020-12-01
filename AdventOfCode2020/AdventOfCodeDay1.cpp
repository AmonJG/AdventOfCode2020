#include <iostream>
#include <vector>
#include "AdventOfCodeDay1.h"

AdventOfCodeTask1Day1::AdventOfCodeTask1Day1()
{
	int inputEntry;
	std::vector<int> inputList;
	auto inputStream = GetInput("Day1.txt");

	while (inputStream >> inputEntry)
	{
		inputList.push_back(inputEntry);
		for (size_t i = 1; i < inputList.size(); i++)
		{
			if (inputList[inputList.size() - 1] + inputList[i - 1] == 2020)
			{
				std::cout << inputList[inputList.size() - 1] * inputList[i - 1] << std::endl;
				return;
			}
		}
	}
}

AdventOfCodeTask2Day1::AdventOfCodeTask2Day1()
{
	int inputEntry;
	std::vector<int> inputList;
	auto inputStream = GetInput("Day1.txt");

	while (inputStream >> inputEntry)
	{
		inputList.push_back(inputEntry);
		for (size_t i = 1; i < inputList.size(); i++)
		{
			for (size_t x = 2; x < inputList.size(); x++)
			{
				if (inputList[inputList.size() - 1] + inputList[i - 1] + inputList[x - 2] == 2020)
				{
					std::cout << inputList[inputList.size() - 1] * inputList[i - 1] * inputList[x - 2] << std::endl;
					return;
				}
			}
		}
	}
}
