#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotatearray(vector<int> &mynum,int k)
{
    if(k==0)
        return;
    if(mynum.size()<=1)
        return;
    int index = 0;
    if(k<=mynum.size())
    {
        index = k;
    }else{
        index = k%mynum.size();
    }
    int tempa[index];
    vector<int> tempv;
    for(int i = 0; i<index; i++)
    {
        int temp = mynum.back();
        mynum.pop_back();
        tempa[i] = temp;
    }
    for(int i = index-1; i>=0; i--)
    {
        tempv.push_back(tempa[i]);
    }
    for(auto i = mynum.begin(); i!=mynum.end(); i++)
    {
        tempv.push_back(*i);
    }
    mynum = tempv;
}

int rotatearraymain()
{
    vector<int> mynum;
    vector<int> temp;
    mynum.push_back(1);
    mynum.push_back(2);
    mynum.push_back(3);
    mynum.push_back(6);
    mynum.push_back(1);
    temp.push_back(3);
    temp.push_back(6);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(2);
    rotatearray(mynum,3);
    if(mynum == temp)
    {
        cout << "success" << endl;
    }else
    {
        cout << "fail" << endl;
    }
}