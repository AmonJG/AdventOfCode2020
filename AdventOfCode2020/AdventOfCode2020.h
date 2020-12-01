#pragma once
#include <memory>
#include "AdventOfCodeTask.h"
#include "AdventOfCodeDay1.h"

using AdventOfCodeTaskPtr = std::shared_ptr<AdventOfCodeTask>;

class AdventOfCode
{
public:
	AdventOfCode();

private:
	void RunConsole();
	void ExecuteTask();
	int m_taskNr;
};
