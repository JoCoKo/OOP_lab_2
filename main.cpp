#include <iostream>
#include "StatisticMultiset.h"
using namespace std;

int main()
{
    StatisticMultiset<int> first;
    for (int i=0;i<10;i++)
        first.AddNum(i*5);
    //multiset<int> nums {5,5,-3,100};
    //first.AddNum(nums);
    //cout << "AddNums= " <<  << endl;
   // first.AddNumsFromFile("input.txt");
//    StatisticMultiset second;
//    for (T i=0;i<10;i++)
//        second.AddNum(i*100);
//    first.AddNums(second);
    cout << "GetMax= " << first.GetMax() << endl;
    cout << "GetMin= " << first.GetMin() << endl;
    cout << "GetAvg= " << first.GetAvg() << endl;
    cout << "GetCountAbove= " << first.GetCountAbove(40) << endl;
    cout << "GetCountBelow= " << first.GetCountUnder(40) << endl;
	first.PrintStr();
	first.AddNum(50);
	cout<< first.GetCountAbove(40) << endl;
	cout<< first.GetCountUnder(40);
	getchar();
    return 0;
}
