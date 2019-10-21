#include <iostream>
#include <vector>
#include <algorithm>

bool checkDuplicate(vector<int> &mynum)
{
    int original = mynum.size();
    sort(mynum.begin(),mynum.end());
    mynum.erase(unique(mynum.begin(),mynum.end()),mynum.end());
    int after = mynum.size();
    return (original!=after);
}

int iscontainduplicatemain()
{
    vector<int> mynum;
    mynum.push_back(1);
    mynum.push_back(2);
    mynum.push_back(4);
    mynum.push_back(6);
    mynum.push_back(1);
    mynum.push_back(3);
    if(checkDuplicate(mynum))
    {
        cout << "Duplicate" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}