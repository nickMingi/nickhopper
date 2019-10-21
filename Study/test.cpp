#include <iostream>

using namespace std;
const int N = 10;
int sorted[N];

void merge_sort(int array[],int left,int right)
{
    if(left < right)
    {
        int mid = (left+right)/2;
        merge_sort(array,left,mid);
        merge_sort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}
void merge(int array[],int left,int mid,int right)
{
    int l = left;
    int m = mid;
    int r = right;
    int key = m;

    while(l <= left && r <= right)
    {
        if(array[l]<=array[r])
        {
            sorted[key] = array[l];
            l++;
        }
        else{
            sorted[key] = array[r];
            r++;
        }
        key++;
    }

    if(l <= m)
    {
        for(int i = l; i<=m; i++)
        {
            sorted[key] = array[i];
        }
    }else{
        for(int i = m; i<=right; i++)
        {
            sorted[key] = array[i];
        }
    }

    for(int i = 0; i<=N; i++)
    {
        array[i] = sorted[i];
    }
}

int testmain()
{
    int array[N] = {2,5,7,8,3,7,9,1,4,2};
    merge_sort(array,0,N-1);
    for(int i = 0; i < N; i++)
    {
        cout << array[i] << endl;
    }
}