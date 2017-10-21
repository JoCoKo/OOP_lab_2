#ifndef STATISTICMULTISET_H
#define STATISTICMULTISET_H
#include <vector>
#include <set>
#include <list>
#include <iostream>

template<typename T>
class StatisticMultiset
{
    public:
        StatisticMultiset()
		{
			//ctor
			lastThresholdUnder = 0;
			lastCountUnder = 0;
			lastThresholdAbove = 0;
			lastCountAbove = 0;
			summ = 0;
			count = 0;
		}
        //virtual ~StatisticMultiset();
        // Добавляет число в набор.
        void AddNum( const T& num )
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
        void AddNum( const std::multiset<T>& )
		{
			for (auto it = nums.begin(); it != nums.end(); ++it)
			{
				AddNum(*it);
			}
		}
		void AddNum( const std::vector<T>& )
		{
			for (size_t i=0 ; i<nums.size() ; i++)
				AddNum(nums[i]);
		}
		void AddNum( const std::list<T>& )
		{
			for (auto it = nums.begin(); it != nums.end(); ++it)
			{
				AddNum(*it);
			}
		}
/*		void AddNumsFromFile( const char* filename )
		{
			std::ifstream fin(filename);
			T x;
			while(!fin.eof())
			{
				fin >> x;
				AddNum(x);
			}
			fin.close();
		}*/
        void AddNums( const StatisticMultiset& a_stat_set )
		{
			for (size_t i=0; i<a_stat_set.count ;i++)
				AddNum(a_stat_set.data[i]);
		}
        // Максимальное число в наборе.
        T GetMax() const
		{
			return max;
		}
        // Минимальное число в наборе.
        T GetMin() const
		{
			return min;
		}
        // Среднее арифметическое всего набора.
        float GetAvg() const
		{
			return count > 0 ? (float)summ / count : 0.0f;
		}
        // Кол-во чисел в наборе меньше заданного порога.
        std::size_t GetCountUnder( T threshold ) const
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
        // Кол-во чисел в наборе больше заданного порога.
        std::size_t GetCountAbove( T threshold ) const
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
		// Вывод структуры
		void PrintStr()
		{
			for (size_t i = 0; i< count; i++)
			{
				std::cout << data[i] << ' ';
			}
		}
    protected:

    private:
        mutable T lastThresholdUnder;
        mutable std::size_t lastCountUnder;
        mutable T lastThresholdAbove;
        mutable std::size_t lastCountAbove;
        std::vector<T> data;
        T min;
        T max;
        T summ;
        std::size_t count;
};

#endif // STATISTICMULTISET_H
