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
	// ��������� ����� � �����.
	void AddNum(int num);
	void AddNum(const std::multiset<int>&);
	void AddNum(const std::vector<int>&);
	void AddNum(const std::list<int>&);
	void AddNumsFromFile(const char* filename);
	void AddNums(const StatisticMultiset& a_stat_set);
	// ������������ ����� � ������.
	int GetMax() const;
	// ����������� ����� � ������.
	int GetMin() const;
	// ������� �������������� ����� ������.
	float GetAvg() const;
	// ���-�� ����� � ������ ������ ��������� ������.
	std::size_t GetCountUnder(int threshold) const;
	// ���-�� ����� � ������ ������ ��������� ������.
	std::size_t GetCountAbove(int threshold) const;
	// ����� ���������
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
