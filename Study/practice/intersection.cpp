#include <iostream>
#include <algorithm>
#include <vector>

vector<int> intersect(vector<int> &nums1,vector<int> &nums2){
    vector<int> result;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int i = 0, j = 0, size1 = nums1.size(), size2 = nums2.size();
    while(i<size1 && j<size2)
    {
        if(nums1[i]==nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
            j++;
        }else if(nums1[i]>nums2[j])
        {
            j++;
        }else if(nums2[j]>nums1[i])
        {
            i++;
        }
    }
    return result;
}

int intersectionmain()
{
    vector<int> num1;
    vector<int> num2;
    num1.push_back(4);
    num1.push_back(9);
    num1.push_back(5);
    num2.push_back(1);
    num2.push_back(9);
    num2.push_back(4);
    num2.push_back(9);
    num2.push_back(4);
    num2.push_back(2);
    num2.push_back(8);
    vector<int> result = intersect(num1,num2);
    for(auto i = result.begin(); i!=result.end();i++)
        cout<< *i << endl;
    return 0;
}