#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

static const int HEAP_SIZE = 10;

void insertHeap(int heap[], int key, int &lastIndex);
void reheapUp(int heap[], int locIndex);
void deleteHeap(int heap[], int &lastIndex);
void reheapDown(int heap[], int locIndex, int lastIndex);
void printHeap(int heap[], int lastIndex);
void heapify(int heap[], int &lastIndex, int size);

void insertHeap(int heap[], int key, int &lastIndex)
{
    if(lastIndex >= HEAP_SIZE)
    {
        cout << "Need to allocate memory before inserting.\n";
        return;
    }
    lastIndex++;
    heap[lastIndex] = key;
    reheapUp(heap, lastIndex);
}

void reheapUp(int heap[], int locIndex)
{
    if(locIndex == 0)
    {
        return;
    }
    int parentIndex = (locIndex - 1) / 2;

    if(heap[parentIndex] > heap[locIndex])
    {
        cout << heap[locIndex] << " is going to heap up " << endl;
        int hold = heap[parentIndex];
        heap[parentIndex] = heap[locIndex];
        heap[locIndex] = hold;

        reheapUp(heap, parentIndex);
    }
}

void deleteHeap(int heap[], int &lastIndex)
{
    if(lastIndex < 0)
    {
        cout << "Heap is empty.";
        return;
    }
    heap[0] = heap[lastIndex];
    lastIndex--;
    reheapDown(heap, 0, lastIndex);
}

void reheapDown(int heap[], int locIndex, int lastIndex)
{
    int leftIndex, rightIndex, smallestIndex, leftValue, rightValue;

    leftIndex = (2 * locIndex) + 1;
    if(leftIndex <= lastIndex)
    {
        leftValue = heap[leftIndex];
        rightIndex = leftIndex + 1;
        if(rightIndex <= lastIndex)
        {
            rightValue = heap[rightIndex];
        }
        else
        {
            rightValue = leftValue - 1;
        }

        if(leftValue < rightValue)
        {
            smallestIndex = leftIndex;
        }
        else
        {
            smallestIndex = rightIndex;
        }        

        // Check if we should swap
        if(heap[smallestIndex] < heap[locIndex])
        {
            cout << heap[locIndex] << " is going to heap down " << endl;
            int hold = heap[locIndex];
            heap[locIndex] = heap[smallestIndex];
            heap[smallestIndex] = hold;

            reheapDown(heap, smallestIndex, lastIndex);
        }
    }
}

void printHeap(int heap[], int lastIndex)
{
    cout << "" << endl;
    cout << "Currently in the array: ";
    for(int j = 0; j <= lastIndex; j++)
    {
        cout << heap[j] << " ";
    }
    cout << endl << endl;
}

void heapify(int heap[], int &lastIndex, int size)
{
    if(HEAP_SIZE < size)
    {
        cout << "Maximum heap size is 10. Please check";
        return;
    }
    if( size <= 0)
    {
        cout << "Heap size is equal or less than 0";
        return;
    }
    if(lastIndex < 0)
    {
        cout << "LastIndexCopy is 0";
        return;
    }
    cout << "heapify in" << endl;
    int parentIndex = (lastIndex - 1) / 2;
    if(heap[parentIndex] > heap[lastIndex])
    {
        reheapUp(heap, lastIndex);
    }
    else
    {
        reheapDown(heap, lastIndex, size-1);
    }
    int lastIndexCopy = lastIndex;
    lastIndexCopy--;
    heapify(heap, lastIndexCopy, size);
}

int heapMain()
{
    int heap[10];
    int size = 10;
    int min = 0, max = 100, newValue;
    int lastIndex = size - 1;

    srand((unsigned)time(0));
    cout << "Let's create 10 random numbers" << endl;
    for(int i = 0; i < size; i++)
    {
        newValue = rand()%(max+1 - min) + min;
        cout << newValue << " \n";
        heap[i] = newValue;
    }
    cout << endl << endl;
    cout << "LastIndex : " << lastIndex << endl;
    heapify(heap, lastIndex, sizeof(heap)/sizeof(int));
    printHeap(heap, 9);
    cout << "LastIndex : " << lastIndex << endl;
    return 0;
}