#include <iostream>
#include <algorithm>
#include <vector>

void reverseString(vector<char>& s)
{
    for(int i =0; i<s.size()/2; i++)
    {
        char temp = s[i];
        swap(temp, s[s.size()-1-i]);
        swqp(temp, s[i]);
    }
}

int reversestringmain()
{
    return 0;
}