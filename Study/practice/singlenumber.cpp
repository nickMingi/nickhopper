#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkSinglenum(vector<int> &mynum)
{
    if(mynum.size()==1)
        return mynum[0];
    sort(mynum.begin(),mynum.end());
    if(mynum[0]!=mynum[1])
        return mynum[0];
    for(int i = 1; i < mynum.size(); i++)
    {
        if(mynum[i]>mynum[i-1])
        {
            if(mynum.size()>i+1)
            {
                if(mynum[i]!=mynum[i+1])
                    return mynum[i];
            }else
            {
                return mynum[i];
            }
        }
    }
    return 0;
}

int singlenumbermain()
{
    vector<int> mynum;
    mynum.push_back(4);
    mynum.push_back(1);
    mynum.push_back(2);
    mynum.push_back(1);
    mynum.push_back(2);
    int single =checkSinglenum(mynum);
    cout << single << endl;
    return 0;
}