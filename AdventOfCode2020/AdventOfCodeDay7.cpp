#include <iostream>
#include <functional>
#include <vector>
#include "AdventOfCodeDays.h"

struct Bag
{
	std::string trait;
	std::string color;
	std::vector<std::shared_ptr<Bag>> bagPtrs;
	bool hasGoldBag = false;
};

bool findGoldBag(std::vector<std::shared_ptr<Bag>> const& bags)
{
	bool goldenBagFound = false;
	for (auto bag : bags)
	{
		if (bag->hasGoldBag)
		{
			return true;
		}
		if (bag->bagPtrs.size() != 0)
		{
			goldenBagFound = findGoldBag(bag->bagPtrs);
			if (goldenBagFound) return true;
		}
	}
	return false;
}

AdventOfCodeTask1Day7::AdventOfCodeTask1Day7()
{
	std::string inputEntry;
	auto inputStream = GetInput("Day7.txt");

	std::vector<std::shared_ptr<Bag>> bags;
	std::shared_ptr<Bag> keyBagReference = nullptr;
	Bag keyBag;
	Bag valueBag;
	std::string trait;
	std::string color;
	int inputWordPos = 0;
	while (inputStream >> inputEntry)
	{

		if (inputWordPos == 0 || (inputWordPos >= 5 && (inputWordPos - 5) % 4 == 0))
		{
			trait = inputEntry;
		}
		else if (inputWordPos == 1 || (inputWordPos >= 6 && (inputWordPos - 6) % 4 == 0))
		{
			if (inputEntry.find('.') != std::string::npos)
			{
				inputWordPos = -1;
			}
			else
			{
				color = inputEntry;
			}
		}
		else if (inputWordPos == 2)
		{
			keyBag.trait = trait;
			keyBag.color = color;
			for (auto bag : bags)
			{
				if (bag->trait == keyBag.trait && bag->color == keyBag.color)
				{
					keyBagReference = bag;
					goto end;
				}
			}
			keyBagReference = nullptr;
		}
		else if (inputWordPos >= 7 && (inputWordPos - 7) % 4 == 0)
		{
			if (trait == "shiny" && color == "gold")
			{
				keyBagReference == nullptr ? keyBag.hasGoldBag = true : keyBagReference->hasGoldBag = true;
				goto testIfEnd;
			}
			valueBag.trait = trait;
			valueBag.color = color;
			for (auto bag : bags)
			{
				if (bag->trait == valueBag.trait && bag->color == valueBag.color)
				{
					keyBagReference == nullptr ? keyBag.bagPtrs.push_back(bag) : keyBagReference->bagPtrs.push_back(bag);
					goto testIfEnd;
				}
			}
			bags.push_back(std::make_shared<Bag>(valueBag));
			keyBagReference == nullptr ? keyBag.bagPtrs.push_back(bags.back()) : keyBagReference->bagPtrs.push_back(bags.back());
			valueBag.bagPtrs.clear();

			testIfEnd:;
			if (inputEntry.find('.') != std::string::npos)
			{
				if (keyBagReference == nullptr)
				{
					bags.push_back(std::make_shared<Bag>(keyBag));
					keyBag.bagPtrs.clear();
					keyBag.hasGoldBag = false;
				}
				inputWordPos = -1;
			}
		}
		end:;
		inputWordPos++;
	}
	int bagsThatContainGoldBag = 0;
	for (auto bag : bags)
	{
		if (bag->hasGoldBag == true)
		{
			bagsThatContainGoldBag++;
		}
		else if (bag->bagPtrs.size() != 0)
		{
			if (findGoldBag(bag->bagPtrs))bagsThatContainGoldBag++;
		}
	}
	std::cout << bagsThatContainGoldBag << std::endl;
}

struct Bag2
{
	std::string trait;
	std::string color;
	std::vector<std::pair<std::shared_ptr<Bag2>, int>> bagPtrs;
};

int countContainedBags(std::vector<std::pair<std::shared_ptr<Bag2>, int>> const& bags)
{
	int containedBags = 0;
	for (auto bag : bags)
	{
		containedBags += bag.second;
		if (bag.first->bagPtrs.size() != 0)
		{
			containedBags += (countContainedBags(bag.first->bagPtrs) * bag.second);
		}
	}
	return containedBags;
}

AdventOfCodeTask2Day7::AdventOfCodeTask2Day7()
{
	std::string inputEntry;
	auto inputStream = GetInput("Day7.txt");

	std::vector<std::shared_ptr<Bag2>> bags;
	std::shared_ptr<Bag2> keyBagReference = nullptr;
	Bag2 keyBag;
	Bag2 valueBag;
	std::string trait;
	std::string color;
	int amountOfValueBags = 0;
	int inputWordPos = 0;
	while (inputStream >> inputEntry)
	{

		if (inputWordPos == 0 || (inputWordPos >= 5 && (inputWordPos - 5) % 4 == 0))
		{
			trait = inputEntry;
		}
		else if (inputWordPos == 1 || (inputWordPos >= 6 && (inputWordPos - 6) % 4 == 0))
		{
			if (inputEntry.find('.') != std::string::npos)
			{
				inputWordPos = -1;
			}
			else
			{
				color = inputEntry;
			}
		}
		else if (inputWordPos == 2)
		{
			keyBag.trait = trait;
			keyBag.color = color;
			for (auto bag : bags)
			{
				if (bag->trait == keyBag.trait && bag->color == keyBag.color)
				{
					keyBagReference = bag;
					goto end;
				}
			}
			keyBagReference = nullptr;
		}
		else if (inputWordPos >= 4 && (inputWordPos - 4) % 4 == 0)
		{
			if (inputEntry == "no")
			{
				inputWordPos = -1;
			}
			else
			{
				amountOfValueBags = std::stoi(inputEntry);
			}
		}
		else if (inputWordPos >= 7 && (inputWordPos - 7) % 4 == 0)
		{
			valueBag.trait = trait;
			valueBag.color = color;
			for (auto bag : bags)
			{
				if (bag->trait == valueBag.trait && bag->color == valueBag.color)
				{
					keyBagReference == nullptr ? keyBag.bagPtrs.push_back(std::make_pair(bag, amountOfValueBags)) : keyBagReference->bagPtrs.push_back(std::make_pair(bag, amountOfValueBags));
					goto testIfEnd;
				}
			}
			bags.push_back(std::make_shared<Bag2>(valueBag));
			keyBagReference == nullptr ? keyBag.bagPtrs.push_back(std::make_pair(bags.back(), amountOfValueBags)) : keyBagReference->bagPtrs.push_back(std::make_pair(bags.back(), amountOfValueBags));
			valueBag.bagPtrs.clear();

			testIfEnd:;
			if (inputEntry.find('.') != std::string::npos)
			{
				if (keyBagReference == nullptr)
				{
					bags.push_back(std::make_shared<Bag2>(keyBag));
					keyBag.bagPtrs.clear();
				}
				inputWordPos = -1;
			}
		}
		end:;
		inputWordPos++;
	}
	for (auto bag : bags)
	{
		if (bag->trait == "shiny" && bag->color == "gold")
		{
			std::cout << countContainedBags(bag->bagPtrs) << std::endl;
		}
	}
}
