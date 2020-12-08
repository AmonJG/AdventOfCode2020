#include <iostream>
#include <bitset>
#include <vector>
#include "AdventOfCodeDays.h"

AdventOfCodeTask1Day5::AdventOfCodeTask1Day5()
{
	std::string inputLine;
	auto inputStream = GetInput("Day5.txt");

	std::bitset<10> seatLocation;
	unsigned long highestSeatID = 0;
	while (inputStream >> inputLine)
	{
		for (int i = 0; i < 10; i++)
		{
			if (inputLine[i] == 'F' || inputLine[i] == 'L')
			{
				seatLocation[9 - i] = 0;
			}
			else if (inputLine[i] == 'B' || inputLine[i] == 'R')
			{
				seatLocation[9 - i] = 1;
			}
		}
		auto seatID = (seatLocation >> 3).to_ulong() * 8 + (seatLocation & std::bitset<10>("0000000111")).to_ulong();
		if (seatID > highestSeatID)highestSeatID = seatID;
	}
	std::cout << highestSeatID;
}

AdventOfCodeTask2Day5::AdventOfCodeTask2Day5()
{
	std::string inputLine;
	auto inputStream = GetInput("Day5.txt");

	std::bitset<10> seatLocation;
	std::vector<std::bitset<8>> rows(128);
	while (inputStream >> inputLine)
	{
		for (int i = 0; i < 10; i++)
		{
			if (inputLine[i] == 'F' || inputLine[i] == 'L')
			{
				seatLocation[9 - i] = 0;
			}
			else if (inputLine[i] == 'B' || inputLine[i] == 'R')
			{
				seatLocation[9 - i] = 1;
			}
		}
		rows[(seatLocation >> 3).to_ulong()][(seatLocation & std::bitset<10>("0000000111")).to_ulong()] = true;
	}
	for (int row = 1; row < 127; row++)
	{
		for (int seat = 0; seat < 8; seat++)
		{
			if (rows[row][seat] == false)
			{
				if (seat == 0)
				{
					if (rows[row - 1][7] == true && rows[row][seat + 1] == true)
					{
						std::cout << row * 8 + seat;
						return;
					}
				}
				else if (seat == 7)
				{
					if (rows[row][seat - 1] == true && rows[row + 1][0] == true)
					{
						std::cout << row * 8 + seat;
						return;
					}
				}
				else
				{
					if (rows[row][seat - 1] == true && rows[row][seat + 1] == true)
					{
						std::cout << row * 8 + seat;
						return;
					}
				}
			}
		}
	}
}
