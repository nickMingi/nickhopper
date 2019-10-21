#include <iostream>
using namespace std;
const int N = 100;
int sorted[N];
void makeRandomNumbers(int N,int values[])
{
    while(N>0)
    {
        values[N-1]=rand()%1001;
        N--;
    }
}

void printRandomNumbers(int N,int values[])
{
    for(int i = 0; i < N; i++)
    {
        printf("%d ",values[i]);
    }
}

void merge(int values[],int left, int mid, int right)
{
    int l = left;
    int m = mid+1;
    int key = left;

    while(l <= mid && m <= right)
    {
        if(values[l]<=values[m])
        {
            sorted[key] = values[l];
            l++;
        }else{
            sorted[key] = values[m];
            m++;
        }
        key++;
    }

    if(l <= mid)
    {
        for(int t = l; t<= mid; t++)
        {
            sorted[key] = values[t];
            key++;
        }
    }else{
        for(int t = m; t<= right; t++)
        {
            sorted[key] = values[t];
            key++;
        }
    }
    for(int t = left; t<= right; t++)
    {
        values[t] = sorted[t];
    }
}

void mergesort(int values[],int left,int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;
        mergesort(values,left,mid);
        mergesort(values,mid+1,right);
        merge(values,left,mid,right);
    }
}

int main1(void)
{
    int values[N];
    makeRandomNumbers(N,values);
    printRandomNumbers(N,values);
    printf("\n");
    mergesort(values,0,N-1);
    printRandomNumbers(N,values);
    printf("\n");
    return 0;
}