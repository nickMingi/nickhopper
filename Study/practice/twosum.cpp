#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> twosum(vector<int> nums,int target)
{
    vector<int> result;
    if(nums.size()==0)
        return result;
    int i = 0, j = 1, size1 = nums.size();
    while(i<size1)
    {
        if(j==size1)
        {
            i++;
            j=i+1;
        }
        if(nums[i]+nums[j]==target)
        {
            result.push_back(i);
            result.push_back(j);
            return result;
        }
        else
        {
            j++;
        }
    }
    return result;
}

int twosummain()
{
    vector<int> result;
    result.push_back(0);
    result.push_back(3);
    result.push_back(4);
    result.push_back(0);
    int target = 0;
    vector<int> answer = twosum(result,target);
    for(auto i = answer.begin(); i!=answer.end(); i++)
        cout << *i << endl;
    return 0;
}