#include <iostream>
#include <functional>
#include <map>
#include "AdventOfCode2020.h"

template <typename AdventOfCodeFunctionType>
AdventOfCodeTaskPtr GenerateTaskObject()
{
    return std::make_shared<AdventOfCodeFunctionType>();
}

std::map<int, std::function<AdventOfCodeTaskPtr()>> const dayFunctions =
{
    { 1, GenerateTaskObject<AdventOfCodeTask1Day1> },
    { 2, GenerateTaskObject<AdventOfCodeTask2Day1> },
    { 3, GenerateTaskObject<AdventOfCodeTask1Day2> },
    { 4, GenerateTaskObject<AdventOfCodeTask2Day2> }
};

void PrintLineStart()
{
    std::cout << std::endl << ">";
}

int AdventOfCode::GetTaskNumberFromConsole()
{
    int taskNr;
    PrintLineStart();
    std::cin >> taskNr;

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "[ERROR] Please insert a number!";
        PrintLineStart();
        std::cin >> taskNr;
    }
    return taskNr;
}

void AdventOfCode::ExecuteTask(int taskNr)
{
    auto dayFunction = dayFunctions.find(taskNr);
    if (dayFunction != dayFunctions.end())
    {
        std::cout << "The answer for task " << taskNr << " is:" << std::endl << std::endl;
        dayFunction->second();
    }
    else
    {
        std::cout << "[ERROR] Task does not exist!";
    }
}

AdventOfCode::AdventOfCode()
{
    ExecuteTask(GetTaskNumberFromConsole());
}

int main()
{
    std::cout << "Welcome to Amons AdventOfCode Solutions!" << std::endl;
    std::cout << std::endl << "There are " << dayFunctions.size() << " AdventOfCode tasks! Please select task number to execute:";
    while (true)
    {
        AdventOfCode();
    }
}
