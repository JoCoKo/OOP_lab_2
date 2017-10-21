#include "StatisticMultiset.h"
#include <vector>
#include <fstream>
#include <set>
#include <iostream>

StatisticMultiset::StatisticMultiset()
{
	//ctor
}
void StatisticMultiset::AddNum(int num)
{
	data.push_back(num);
	count++;
	if (count == 1)
		min = max = num;
	else
		if (num > max)
			max = num;
		else
			if (num < min)
				min = num;
	summ += num;
	if (num > lastThresholdAbove)
		lastCountAbove++;
	if (num < lastThresholdUnder)
		lastCountUnder++;

}
void StatisticMultiset::AddNum(const std::multiset<int>& nums)
{
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		AddNum(*it);
	}
}
void StatisticMultiset::AddNum(const std::vector<int>& nums)
{
	for (size_t i = 0; i<nums.size(); i++)
		AddNum(nums[i]);
}
void StatisticMultiset::AddNum(const std::list<int>& nums)
{
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		AddNum(*it);
	}
}
void StatisticMultiset::AddNumsFromFile(const char* filename)
{
	std::ifstream fin(filename);
	int x;
	while (!fin.eof())
	{
		fin >> x;
		AddNum(x);
	}
	fin.close();
}
void StatisticMultiset::AddNums(const StatisticMultiset& a_stat_set)
{
	for (size_t i = 0; i<a_stat_set.count; i++)
		AddNum(a_stat_set.data[i]);
}
int StatisticMultiset::GetMax() const
{
	return max;
}
int StatisticMultiset::GetMin() const
{
	return min;
}
size_t StatisticMultiset::GetCountUnder(int threshold) const
{
	if (lastThresholdUnder == threshold)
		return lastCountUnder;
	size_t countUnder = 0;
	for (size_t i = 0; i< count; i++)
	{
		if (data[i]< threshold)
			countUnder++;
	}
	lastCountUnder = countUnder;
	lastThresholdUnder = threshold;
	return countUnder;
}
size_t StatisticMultiset::GetCountAbove(int threshold) const
{
	if (lastThresholdAbove == threshold)
		return lastCountAbove;
	size_t countAbove = 0;
	for (size_t i = 0; i< count; i++)
	{
		if (data[i]> threshold)
			countAbove++;
	}
	lastThresholdAbove = threshold;
	lastCountAbove = countAbove;
	return countAbove;
}
float StatisticMultiset::GetAvg() const
{
	return count > 0 ? (float)summ / count : 0.0f;
}

void StatisticMultiset::PrintStr()
{
	for (size_t i = 0; i< count; i++)
	{
		std::cout << data[i] << ' ';
	}
}

StatisticMultiset::~StatisticMultiset()
{
	//dtor
}
