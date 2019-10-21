#include <iostream>
using namespace std;

void InsertionSort(int A[], int n)
{
    int key, i, j;
    for(j = 1; j < n; j++)
    {
        key = A[j];
        i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}