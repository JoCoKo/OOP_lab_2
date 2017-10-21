#include "StatisticMultiset.h"
#include <vector>
#include <fstream>
#include <set>
#include <iostream>

/*template<typename T>
StatisticMultiset<T>::StatisticMultiset()
{
    //ctor
	lastThresholdUnder = 0;
	lastCountUnder = 0;
	lastThresholdAbove = 0;
	lastCountAbove = 0;
	sum = 0;
	count = 0;
}*/
template<typename T>
void StatisticMultiset<T>::AddNum( const T& num )
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
    if (num > lastThresholdAbove)
        lastCountAbove++;
    if (num < lastThresholdUnder)
        lastCountUnder++;

}
template<typename T>
void StatisticMultiset<T>::AddNum(const std::multiset<T>& nums)
{
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		AddNum(*it);
	}
}
template<typename T>
void StatisticMultiset<T>::AddNum( const std::vector<T>& nums )
{
    for (size_t i=0 ; i<nums.size() ; i++)
        AddNum(nums[i]);
}
template<typename T>
void StatisticMultiset<T>::AddNum(const std::list<T>& nums)
{
	for (auto it = nums.begin(); it != nums.end(); ++it)
	{
		AddNum(*it);
	}
}
template<typename T>
void StatisticMultiset<T>::AddNumsFromFile( const char* filename )
{
    std::ifstream fin(filename);
    T x;
    while(!fin.eof())
    {
        fin >> x;
        AddNum(x);
    }
    fin.close();
}
template<typename T>
void StatisticMultiset<T>::AddNums( const StatisticMultiset& a_stat_set )
{
    for (size_t i=0; i<a_stat_set.count ;i++)
        AddNum(a_stat_set.data[i]);
}
template<typename T>
T StatisticMultiset<T>::GetMax() const
{
    return max;
}
template<typename T>
T StatisticMultiset<T>::GetMin() const
{
    return min;
}
template<typename T>
size_t StatisticMultiset<T>::GetCountUnder( T threshold ) const
{
    if (lastThresholdUnder==threshold)
        return lastCountUnder;
    size_t countUnder=0;
    for (size_t i=0; i< count; i++)
    {
        if (data[i]< threshold)
            countUnder++;
    }
    lastCountUnder=countUnder;
    lastThresholdUnder=threshold;
    return countUnder;
}
template<typename T>
size_t StatisticMultiset<T>::GetCountAbove( T threshold ) const
{
    if (lastThresholdAbove==threshold)
        return lastCountAbove;
    size_t countAbove=0;
    for (size_t i=0; i< count; i++)
    {
        if (data[i]> threshold)
            countAbove++;
    }
    lastThresholdAbove=threshold;
    lastCountAbove=countAbove;
    return countAbove;
}
template<typename T>
float StatisticMultiset<T>::GetAvg() const
{
    return count > 0 ? (float)summ / count : 0.0f;
}

template<typename T>
void StatisticMultiset<T>::PrintStr()
{
	for (size_t i = 0; i< count; i++)
	{
		std::cout << data[i] << ' ';
	}
}

template<typename T>
StatisticMultiset<T>::~StatisticMultiset()
{
    //dtor
}
