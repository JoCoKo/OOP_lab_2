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
        void AddNum( int num );
        void AddNum( const std::multiset<int>& );
		void AddNum( const std::vector<int>& );
		void AddNum( const std::list<int>& );
		void AddNumsFromFile( const char* filename );
        void AddNums( const StatisticMultiset& a_stat_set );
        // Максимальное число в наборе.
        int GetMax() const;
        // Минимальное число в наборе.
        int GetMin() const;
        // Среднее арифметическое всего набора.
        float GetAvg() const;
        // Кол-во чисел в наборе меньше заданного порога.
        int GetCountUnder( float threshold ) const;
        // Кол-во чисел в наборе больше заданного порога.
        int GetCountAbove( float threshold ) const;
		// Вывод структуры
		void PrintStr();
    protected:

    private:
        std::vector<int> data;
        int min;
        int max;
        int summ=0;
        int count=0;
};

#endif // STATISTICMULTISET_H
