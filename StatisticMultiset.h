#ifndef STATISTICMULTISET_H
#define STATISTICMULTISET_H
#include <vector>
#include <set>
#include <list>

class StatisticMultiset
{
public:
	StatisticMultiset();
	virtual ~StatisticMultiset();
	// Добавляет число в набор.
	void AddNum(int num);
	void AddNum(const std::multiset<int>&);
	void AddNum(const std::vector<int>&);
	void AddNum(const std::list<int>&);
	void AddNumsFromFile(const char* filename);
	void AddNums(const StatisticMultiset& a_stat_set);
	// Максимальное число в наборе.
	int GetMax() const;
	// Минимальное число в наборе.
	int GetMin() const;
	// Среднее арифметическое всего набора.
	float GetAvg() const;
	// Кол-во чисел в наборе меньше заданного порога.
	std::size_t GetCountUnder(int threshold) const;
	// Кол-во чисел в наборе больше заданного порога.
	std::size_t GetCountAbove(int threshold) const;
	// Вывод структуры
	void PrintStr();
protected:

private:
	mutable int lastThresholdUnder = 0;
	mutable std::size_t lastCountUnder = 0;
	mutable int lastThresholdAbove = 0;
	mutable std::size_t lastCountAbove = 0;
	std::vector<int> data;
	int min;
	int max;
	int summ = 0;
	std::size_t count = 0;
};

#endif // STATISTICMULTISET_H
