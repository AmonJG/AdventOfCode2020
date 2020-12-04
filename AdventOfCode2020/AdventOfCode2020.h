#pragma once
#include <memory>
#include "AdventOfCodeTask.h"
#include "AdventOfCodeDay1.h"
#include "AdventOfCodeDay2.h"
#include "AdventOfCodeDay3.h"

using AdventOfCodeTaskPtr = std::shared_ptr<AdventOfCodeTask>;

class AdventOfCode
{
public:
	AdventOfCode();

private:
	int GetTaskNumberFromConsole();
	void ExecuteTask(int taskNr);
};
