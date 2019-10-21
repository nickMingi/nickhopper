#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateProfit(vector<int> &mynum)
{
    int profit = 0;
    for(int i = 1; i < mynum.size(); i++)
    {
        if(mynum[i]>mynum[i-1])
        {
            profit += mynum[i] - mynum[i-1];
        }
    }
    return profit;
}

int stockprofitmain()
{
    vector<int> mynum;
    mynum.push_back(7);
    mynum.push_back(1);
    mynum.push_back(5);
    mynum.push_back(3);
    mynum.push_back(6);
    mynum.push_back(1);
    mynum.push_back(1);
    int profit = calculateProfit(mynum);
    cout << "max profit = " << profit << endl;
    cout << mynum.size() << endl;
    return mynum.size();
}