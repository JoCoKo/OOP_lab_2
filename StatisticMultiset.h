#ifndef STATISTICMULTISET_H
#define STATISTICMULTISET_H
#include <vector>


class StatisticMultiset
{
    public:
        StatisticMultiset();
        virtual ~StatisticMultiset();
        // ��������� ����� � �����.
        void AddNum( int num );
        void AddNum( const std::vector<int>& );
        void AddNumsFromFile( const char* filename );
        void AddNums( const StatisticMultiset& a_stat_set );
        // ������������ ����� � ������.
        int GetMax() const;
        // ����������� ����� � ������.
        int GetMin() const;
        // ������� �������������� ����� ������.
        float GetAvg() const;
        // ���-�� ����� � ������ ������ ��������� ������.
        int GetCountUnder( float threshold ) const;
        // ���-�� ����� � ������ ������ ��������� ������.
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
