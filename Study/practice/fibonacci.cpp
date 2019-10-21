#include <iostream>
using namespace std;

int fib(int x)
{
    return x <= 1 ? x : fib(x-1) + fib(x-2);  
}

int fibonaccimain()
{
    for(int i = 0; i<10; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;
    return 0;
}