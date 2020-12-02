#include <iostream>
#include <string>
#include "AdventOfCodeDay2.h"

AdventOfCodeTask1Day2::AdventOfCodeTask1Day2()
{
	std::string inputEntry;
	auto inputStream = GetInput("Day2.txt");

	int min, max, validPasswords = 0;
	char policyChar;
	std::string password;

	while (std::getline(inputStream, inputEntry))
	{
		min = std::stoi(inputEntry.substr(0, inputEntry.find_first_of('-')));
		max = std::stoi(inputEntry.substr(inputEntry.find_first_of('-') + 1, inputEntry.find_first_of(' ')));
		policyChar = inputEntry[inputEntry.find_first_of(':') - 1];
		password = inputEntry.substr(inputEntry.find_first_of(':') + 2);

		int charCount = 0;
		for(int i = 0; i < password.size(); i++)
		{
			if (password[i] == policyChar)charCount++;
		}
		if (min <= charCount && charCount <= max)
		{
			validPasswords++;
		}
	}
	std::cout << validPasswords;
}

AdventOfCodeTask2Day2::AdventOfCodeTask2Day2()
{
	std::string inputEntry;
	auto inputStream = GetInput("Day2.txt");

	int min, max, validPasswords = 0;
	char policyChar;
	std::string password;

	while (std::getline(inputStream, inputEntry))
	{
		min = std::stoi(inputEntry.substr(0, inputEntry.find_first_of('-')));
		max = std::stoi(inputEntry.substr(inputEntry.find_first_of('-') + 1, inputEntry.find_first_of(' ')));
		policyChar = inputEntry[inputEntry.find_first_of(':') - 1];
		password = inputEntry.substr(inputEntry.find_first_of(':') + 2);

		bool isValid = false;
		if (password[min - 1] == policyChar)isValid = !isValid;
		if (password[max - 1] == policyChar)isValid = !isValid;
		if (isValid)validPasswords++;
	}
	std::cout << validPasswords;
}
