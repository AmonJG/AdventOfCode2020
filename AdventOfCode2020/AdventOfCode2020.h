#pragma once
#include <memory>
#include "AdventOfCodeTask.h"

using AdventOfCodeTaskPtr = std::shared_ptr<AdventOfCodeTask>;

class AdventOfCode
{
public:
	AdventOfCode();

private:
	int GetTaskNumberFromConsole();
	void ExecuteTask(int taskNr);
};
