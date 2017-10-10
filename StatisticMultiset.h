#ifndef STATISTICMULTISET_H
#define STATISTICMULTISET_H
#include <vector>


class StatisticMultiset
{
    public:
        StatisticMultiset();
        virtual ~StatisticMultiset();
        // Добавляет число в набор.
        void AddNum( int num );
        void AddNum( const std::vector<int>& );
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

    protected:

    private:
        std::vector<int> data;
        int min;
        int max;
        int summ=0;
        int count=0;
};

#endif // STATISTICMULTISET_H
