// #include <iostream>
// using namespace std;

// int number = 8, size = 0, count = 0;
// int sorted[8];

// void merge(int array[], int left, int middle, int right)
// {
//     int i = left;
//     int j = middle + 1;
//     int key = left;

//     while(i <= middle && j <= right)
//     {
//         if(array[i] <= array[j])
//         {
//             sorted[key]=array[i];
//             i++;
//         }else
//         {
//             sorted[key] = array[j];
//             j++;
//         }
//         key++;
//     }
//     if(i > middle)
//     {
//         for(int t = j; t<=right; t++)
//         {
//             sorted[key] = array[t];
//             key++;
//         }
//     }else
//     {
//         for(int t = i; t<= middle; t++)
//         {
//             sorted[key] = array[t];
//             key++;
//         }
//     }
//     for(int i = left; i <=right; i++)
//     {
//         array[i] = sorted[i];
//     }
// }

// void mergeSort(int array[], int left, int right)
// {
//     if(left < right)
//     {
//         int middle = (left + right) / 2;
//         mergeSort(array,left, middle);
//         mergeSort(array, middle+1, right);
//         merge(array, left, middle, right);
//     }
// }

// int mergemain()
// {
//     int array[8] = {7,6,5,8,3,5,9,1};
//     mergeSort(array, 0, 7);
//     for(int i = 0; i < 8; i++)
//     {
//         cout << array[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }