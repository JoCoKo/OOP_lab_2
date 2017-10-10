#include <iostream>
#include "StatisticMultiset.h"
using namespace std;

int main()
{
    StatisticMultiset first;
    for (int i=0;i<10;i++)
        first.AddNum(i*5);
    vector<int> nums {-3,5,100};
    first.AddNum(nums);
    //cout << "AddNums= " <<  << endl;
    first.AddNumsFromFile("input.txt");
    StatisticMultiset second;
    for (int i=0;i<10;i++)
        second.AddNum(i*100);
    first.AddNums(second);
    cout << "GetMax= " << first.GetMax() << endl;
    cout << "GetMin= " << first.GetMin() << endl;
    cout << "GetAvg= " << first.GetAvg() << endl;
    cout << "GetCountAbove= " << first.GetCountAbove(40) << endl;
    cout << "GetCountBelow= " << first.GetCountUnder(40) << endl;
	getchar();
	
	
    return 0;
}
