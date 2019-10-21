#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
        int maximum = 0;
        if(nums.size()<=0)
            return maximum;
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        // for(auto i = nums.begin(); i!=nums.end();i++)
        // {
        //     cout << "*i = " << *i << endl;
        //     if(*i==maximum)
        //     {
        //         nums.erase(i--);
        //     }
        //     if(maximum < *i)
        //     {
        //         maximum = *i;
        //     }
        // }
        // for(auto j = nums.begin(); j!=nums.end();j++)
        //    { cout<<*j<<endl;}
        for(int const &i: nums)
        {
            cout << nums[i] <<endl;
        }
        cout << nums.size() << endl;
        return maximum;
}

int removeDuplicatesmain()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    int ret = removeDuplicates(nums);
    cout << "result = " << ret <<endl;
    return ret;
}