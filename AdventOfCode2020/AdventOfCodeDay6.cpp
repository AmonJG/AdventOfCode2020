#include <iostream>
#include <vector>
#include "AdventOfCodeDays.h"

AdventOfCodeTask1Day6::AdventOfCodeTask1Day6()
{
	std::string inputLine;
	auto inputStream = GetInput("Day6.txt");

	int countsSum = 0;
	std::vector<char> questions;
	while (std::getline(inputStream, inputLine))
	{
		for(size_t i = 0; i < inputLine.size(); i++)
		{
			if(std::find(questions.begin(), questions.end(), inputLine[i]) == questions.end())
			{
				questions.push_back(inputLine[i]);
				countsSum++;
			}
		}
		if (inputLine == "")questions.clear();
	}
	std::cout << countsSum;
}

AdventOfCodeTask2Day6::AdventOfCodeTask2Day6()
{
	std::string inputLine;
	auto inputStream = GetInput("Day6.txt");

	size_t countsSum = 0;
	size_t linecount = 0;
	std::vector<char> remainingQuestions;
	while (std::getline(inputStream, inputLine))
	{
		if (linecount == 0)
		{
			for (size_t i = 0; i < inputLine.size(); i++)
			{
				remainingQuestions.push_back(inputLine[i]);
			}
		}
		else if (inputLine == "")
		{
			countsSum += remainingQuestions.size();
			remainingQuestions.clear();
			linecount = 0;
			continue;
		}
		else if (remainingQuestions.size() > 0)
		{
			std::vector<char> tempQuestions;
			for (size_t i = 0; i < inputLine.size(); i++)
			{
				if (std::find(remainingQuestions.begin(), remainingQuestions.end(), inputLine[i]) != remainingQuestions.end())
				{
					tempQuestions.push_back(inputLine[i]);
				}
			}
			remainingQuestions = tempQuestions;
		}
		linecount++;
	}
	countsSum += remainingQuestions.size();
	std::cout << countsSum;
}
