#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> plusone(vector<int> &digits)
{
    vector<int> result;
    int num = 0, len = digits.size();
    bool plus = true;

    for(int i = len-1; i>=0; i--)
    {
        num = digits[i];
        if(plus)
        {
            if(digits[i]+1 == 10)
            {
                if(i == 0){
                    result.push_back(0);
                    result.push_back(1);
                    break;
                }else{
                    num = 0;
                }
            }else{
                plus = false;
                num+=1;
            }
        }
        result.push_back(num);
    }
    reverse(result.begin(),result.end());
    return result;
}

int plusonemain()
{
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    vector<int> result = plusone(digits);
    for(auto i = result.begin();i!=result.end();i++)
        cout << *i << endl;
    return 0;
}