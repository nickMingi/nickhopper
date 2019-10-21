#include <iostream>
using namespace std;
int usingforloop(int value)
{
    int i = 0;
    for(i = 1; i<=13; i++)
    {
        value+=i;
        printf("value is = %d\n",value);
    }
    return value;
}

int usingwhileloop(int value)
{
    while(value >= 0)
    {
        printf("Count Backward = %d\n",value);
        value--;
    }
    return value;
}

int maincsc410assignment(void)
{
    int value = 0;
    value = usingforloop(value);
    return 0;
}