#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void movezerose(vector<int> &nums)
{
    vector<int> temp;
    temp = nums;
    sort(temp.begin(),temp.end());
    int count = 0;
    for(auto i = temp.begin(); i != temp.end(); i++)
    {
        if(*i == 0)
        {
            count++;
        }else if(*i<0)
        {
            continue;
        }else{
            break;
        }
    }
    for(auto i = nums.begin(); i!= nums.end(); i++)
    {
        if(count < 1)
            break;
        if(*i == 0)
        {
            nums.erase(i--);
            count--;
            nums.push_back(0);
        }
    }
}

int movezerosmain()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(7);
    nums.push_back(5);
    movezerose(nums);
    for(auto i = nums.begin(); i!= nums.end(); i++)
        cout << *i << endl;
    return 0;
}