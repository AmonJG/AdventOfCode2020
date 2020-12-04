#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "AdventOfCodeDays.h"

AdventOfCodeTask1Day4::AdventOfCodeTask1Day4()
{
	std::map<std::string, bool> PassportFields{
		{"byr", false}, 
		{"iyr", false},
		{"eyr", false},
		{"hgt", false}, 
		{"hcl", false},  
		{"ecl", false}, 
		{"pid", false}, 
		{"cid", false}
	};

	std::string inputLine;
	auto inputStream = GetInput("Day4.txt");

	int validPassports = 0;
	while (std::getline(inputStream, inputLine))
	{
		for (size_t i = 0; i < inputLine.size(); i++)
		{
			if(inputLine[i]==':')
			{
				PassportFields.find(inputLine.substr(i - 3, 3))->second = true;
			}
		}
		if (inputLine == "")
		{
			bool passportIsValid = true;
			for (auto passportField = PassportFields.begin(); passportField != PassportFields.end(); passportField++)
			{
				if (passportField->second == false && passportField->first != "cid")
				{
					passportIsValid = false;
				}
				passportField->second = false;
			}
			if (passportIsValid)validPassports++;
		}
	}
	std::cout << validPassports;
}

AdventOfCodeTask2Day4::AdventOfCodeTask2Day4()
{
	std::map<std::string, std::pair<bool, std::function<bool(std::string const& value)>>> PassportFields{
		{"byr", {false, [](std::string const& value) -> bool 
		{
			return (std::stoi(value) >= 1920 && std::stoi(value) <= 2002);
		}
		}},
		{"iyr", {false, [](std::string const& value) -> bool
		{
			return (std::stoi(value) >= 2010 && std::stoi(value) <= 2020);
		}
		}},
		{"eyr", {false, [](std::string const& value) -> bool
		{
			return (std::stoi(value) >= 2020 && std::stoi(value) <= 2030);
		}
		}},
		{"hgt", {false, [](std::string const& value) -> bool
		{
			int cmPosition = value.find_first_of('c');
			int inchPosition = value.find_first_of('i');
			if(cmPosition != std::string::npos)
			{
				int cmHeight = std::stoi(value.substr(0, cmPosition));
				return (cmHeight >= 150 && cmHeight <= 193);
			}
			if (inchPosition != std::string::npos)
			{
				int inchHeight = std::stoi(value.substr(0, inchPosition));
				return (inchHeight >= 59 && inchHeight <= 76);
			}
			return false;
		}
		}},
		{"hcl", {false, [](std::string const& value) -> bool
		{
			if (value.size() != 7 || value[0] != '#')return false;
			return (value.find_first_not_of("0123456789abcdef", 1) == std::string::npos);
		}
		}},
		{"ecl", {false, [](std::string const& value) -> bool
		{
			std::vector<std::string> eyeColours = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
			for (auto eyeColour : eyeColours)
			{
				if (value == eyeColour)return true;
			}
			return false;
		}
		}},
		{"pid", {false, [](std::string const& value) -> bool
		{
			if (value.size() != 9)return false;
			return (value.find_first_not_of("0123456789") == std::string::npos);
		}
		}},
		{"cid", {false, [](std::string const& value) -> bool {return true;}}}
	};

	std::string inputLine;
	auto inputStream = GetInput("Day4.txt");

	int validPassports = 0;
	while (std::getline(inputStream, inputLine))
	{
		for (size_t i = 0; i < inputLine.size(); i++)
		{
			if (inputLine[i] == ':')
			{
				auto passportField = PassportFields.find(inputLine.substr(i - 3, 3));
				size_t valueStart = ++i;
				for (i; inputLine[i] != ' ' && i < inputLine.size(); i++);
				passportField->second.first = passportField->second.second(inputLine.substr(valueStart, i - valueStart));
			}
		}
		if (inputLine == "")
		{
			bool passportIsValid = true;
			for (auto passportField = PassportFields.begin(); passportField != PassportFields.end(); passportField++)
			{
				if (passportField->second.first == false && passportField->first != "cid")
				{
					passportIsValid = false;
				}
				passportField->second.first = false;
			}
			if (passportIsValid)validPassports++;
		}
	}
	std::cout << validPassports;
}
