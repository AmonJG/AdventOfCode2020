#include <iostream>
#include <functional>
#include <map>
#include "AdventOfCode2020.h"

template <typename AdventOfCodeFunctionType>
AdventOfCodeTaskPtr GenerateFunctionObject()
{
    return std::make_shared<AdventOfCodeFunctionType>();
}

std::map<int, std::function<AdventOfCodeTaskPtr()>> const dayFunctions =
{
    { 1, GenerateFunctionObject<AdventOfCodeTask1Day1> },
    { 2, GenerateFunctionObject<AdventOfCodeTask2Day1> }
};

void PrintLineStart()
{
    std::cout << ">";
}

void AdventOfCode::RunConsole()
{
    PrintLineStart();
    std::cin >> m_taskNr;

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please insert a number!" << std::endl;
        PrintLineStart();
        std::cin >> m_taskNr;
    }
}

void AdventOfCode::ExecuteTask()
{
    auto dayFunction = dayFunctions.find(m_taskNr);
    if (dayFunction != dayFunctions.end())
    {
        std::cout << "You selected Task " << m_taskNr << std::endl << std::endl;
        dayFunction->second();
    }
    else
    {
        std::cout << "Task does not exist!" << std::endl << std::endl;
    }
}

AdventOfCode::AdventOfCode()
{
    std::cout << std::endl << "Please insert task of AdventOfCode:" << std::endl;
    RunConsole();
    ExecuteTask();
}

int main()
{
    std::cout << "Welcome to Amons AdventOfCode Solutions!" << std::endl;
    while (true)
    {
        AdventOfCode();
    }
}
