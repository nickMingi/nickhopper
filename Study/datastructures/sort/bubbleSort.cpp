// #include <iostream>

// using namespace std;

// void swap(int *xp, int *yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }

// void bubbleSort(int arr[], int n)
// {
//     for(int i = 0; i < n -1; i++)
//     {
//         for(int j = 0; j < n-i-1; j++)
//         {
//             if(arr[j] > arr[j+1])
//             {
//                 swap(&arr[j], &arr[j+1]);
//             }
//         }
//     }
// }

// void printArray(int arr[], int size)
// {
//     int i;
//         for(i = 0; i < size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//     cout << endl;
// }

// int bubblesortMain()
// {
//     int arr[] = {66, 32, 25, 11, 21, 10, 99};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     bubbleSort(arr, n);
//     cout<<"Array is sorted \n";
//     printArray(arr, n);
//     return 0;
// }