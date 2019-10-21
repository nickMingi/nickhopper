/*
4.1-1
What does FIND-MAXIMUM-SUBARRAY return when all elements of A are negative?

Answer:It will return the greatest element of A.

4.1-3
Implement both the brute-force and recursive algorithms for the
maximum-subarray problem on your own computer. What problem size
n0 gives the crossover point at which the recursive algorithm to use
the brute-force algorithm? Then, change the base case of the recursive
algorithm to use the brute-force algorithm whenever the problem size is
less than n0. Does that change the crossover point?
*/

#include <iostream>
#include <array>
using namespace std;

struct subarrayResult{
    int startIndex;
    int endIndex;
    long totalSum;
};
const int SIZE = 17;
int sorted[SIZE] = {0};
void GetDifference(const int arr[],int size);
subarrayResult findMaximumSubarray(const int arr[],const int size,const int low,const int high);
subarrayResult findMaxCrossingSubarray(const int arr[],const int size,const int low,const int mid,const int high);

void GetDifference(const int arr[],int size)
{
    if(size==0)
        return;
    else{
        int* diff = {0};
        for(int i = 0; i <size; i++)
        {
            if(i!=0)
            {
                sorted[i] = arr[i] - arr[i-1];
            }
        }
    }
}
subarrayResult findMaximumSubarray(const int arr[],const int size,const int low,const int high)
{
    if(high==low)
    {
        //only one element
        subarrayResult result;
        result.startIndex = low;
        result.endIndex = high;
        result.totalSum = arr[low];
        return result;
    }else
    {
        int mid = (low+high)/2;
        subarrayResult left;
        subarrayResult right;
        subarrayResult cross;
        left = findMaximumSubarray(arr,size,low,mid);
        right = findMaximumSubarray(arr,size,mid+1,high);
        cross = findMaxCrossingSubarray(arr,size,low,mid,high);
        if(left.totalSum>=right.totalSum && left.totalSum>=cross.totalSum)
        {
            return left;
        }else if(right.totalSum>=left.totalSum && right.totalSum>=cross.totalSum)
        {
            return right;
        }else
        {
            return cross;
        }
    }
}

subarrayResult findMaxCrossingSubarray(const int arr[],const int size,const int low,const int mid,const int high)
{
    int leftsum = 0;
    int rightsum = 0;
    int sum = 0;
    subarrayResult result;
    leftsum = arr[mid];
    sum = arr[mid];
    result.startIndex = mid;
    for(int i = mid-1; i>=low; i--)
    {
        sum+=arr[i];
        if(sum>leftsum)
        {
            leftsum = sum;
            result.startIndex = i;
        }
    }
    sum = 0;
    rightsum = arr[mid+1];
    sum = arr[mid+1];
    result.endIndex = mid+1;
    for(int j = mid+2;j<=high;j++)
    {
        sum+=arr[j];
        if(sum>rightsum)
        {
            rightsum = sum;
            result.endIndex = j;
        }
    }
    result.totalSum = leftsum + rightsum;
    return result;
}

int assignment2main()
{
    subarrayResult res;
    int stock[SIZE] = {100,113,110,85,105,
                    102,86,63,81,101,
                    94,106,101,79,94,
                    90,97};
    // When we buy? and When we sell?
    GetDifference(stock,SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Difference element "<< i << " = " <<sorted[i] <<endl;
    }
    res = findMaximumSubarray(sorted,SIZE,0,SIZE-1);
    cout<< "low : " <<res.startIndex<<" high : "<<res.endIndex<<" sum : "<<res.totalSum<<endl;
    /*
    output
    Difference element 0 = 0
    Difference element 1 = 13
    Difference element 2 = -3
    Difference element 3 = -25
    Difference element 4 = 20
    Difference element 5 = -3
    Difference element 6 = -16
    Difference element 7 = -23
    Difference element 8 = 18
    Difference element 9 = 20
    Difference element 10 = -7
    Difference element 11 = 12
    Difference element 12 = -5
    Difference element 13 = -22
    Difference element 14 = 15
    Difference element 15 = -4
    Difference element 16 = 7
    low : 7 high : 11 sum : 43
    */
    return 0;
}