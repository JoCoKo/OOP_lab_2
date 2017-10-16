#include "StatisticMultiset.h"
#include <vector>
#include <fstream>
#include <set>
#include <iostream>

StatisticMultiset::StatisticMultiset()
{
    //ctor
}
void StatisticMultiset::AddNum( int num )
{
    data.push_back(num);
    count++;
    if (count==1)
        min=max=num;
    else
        if (num > max)
            max=num;
        else
            if (num < min)
                min=num;
    summ+=num;
}
void StatisticMultiset::AddNum(const std::multiset<int>& nums)
{
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		AddNum(*it);
	}
}
void StatisticMultiset::AddNum( const std::vector<int>& nums )
{
    for (size_t i=0 ; i<nums.size() ; i++)
        AddNum(nums[i]);
}
void AddNum(const std::list<int>& nums)
{
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
	//	AddNum(*it);
	}
}
void StatisticMultiset::AddNumsFromFile( const char* filename )
{
    std::ifstream fin(filename);
    int x;
    while(!fin.eof())
    {
        fin >> x;
        AddNum(x);
    }
    fin.close();
}
void StatisticMultiset::AddNums( const StatisticMultiset& a_stat_set )
{
    for (int i=0; i<a_stat_set.count ;i++)
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
int StatisticMultiset::GetCountUnder( float threshold ) const
{
    int countUnder=0;
    for (int i=0; i< count; i++)
    {
        if (data[i]< threshold)
            countUnder++;
    }
    return countUnder;
}
int StatisticMultiset::GetCountAbove( float threshold ) const
{
    int countAbove=0;
    for (int i=0; i< count; i++)
    {
        if (data[i]> threshold)
            countAbove++;
    }
    return countAbove;
}
float StatisticMultiset::GetAvg() const
{
    return count > 0 ? (float)summ / count : 0.0f;
}

void StatisticMultiset::PrintStr()
{
	for (int i = 0; i< count; i++)
	{
		std::cout << data[i] << ' ';
	}
}

StatisticMultiset::~StatisticMultiset()
{
    //dtor
}
