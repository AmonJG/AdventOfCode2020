#include <iostream>
#include <string>
#include <vector>
#include "AdventOfCodeDay3.h"

AdventOfCodeTask1Day3::AdventOfCodeTask1Day3()
{
	std::string inputLine;
	int rightShift = 3;
	auto inputStream = GetInput("Day3.txt");

	int treeCounter = 0;
	int xPos = 0;
	while (inputStream >> inputLine)
	{
		if (inputLine[xPos] == '#')treeCounter++;
		xPos += rightShift;
		if (xPos >= inputLine.size())
		{
			xPos -= inputLine.size();
		}
	}
	std::cout << treeCounter;
}

AdventOfCodeTask2Day3::AdventOfCodeTask2Day3()
{
	struct Shift
	{
		int const rightShift, downShift;
		int xPos = 0;
		int treeCounter = 0;
	};

	std::string inputLine;
	std::vector<Shift> Shifts =
	{
		{1, 1},
		{3, 1},
		{5, 1},
		{7, 1},
		{1, 2}
	};
	auto inputStream = GetInput("Day3.txt");

	int currentRow = 0;
	while (inputStream >> inputLine)
	{
		for (int i = 0; i < Shifts.size(); i++)
		{
			if (currentRow % Shifts[i].downShift) break;
			if (inputLine[Shifts[i].xPos] == '#')Shifts[i].treeCounter++;
			Shifts[i].xPos += Shifts[i].rightShift;
			if (Shifts[i].xPos >= inputLine.size())
			{
				Shifts[i].xPos -= inputLine.size();
			}
		}
		currentRow++;
	}
	int treeProduct = 1;
	for (int i = 0; i < Shifts.size(); i++)
	{
		treeProduct *= Shifts[i].treeCounter;
	}
	std::cout << treeProduct;
}
