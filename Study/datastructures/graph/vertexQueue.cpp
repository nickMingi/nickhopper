#include <iostream>
#include "./vertex.h"
using namespace std;

struct Queue
{
    Node* front;
    int count;
    Node* rear;
};

void initQueue(Queue& q);
void deleteQueue(Queue& q);
bool dequeue(Queue& q, Vertex*& dataOut);
bool enqueue(Queue& q, Vertex* dataIn);
bool queueFront(Queue& q, Vertex*& dataOut);
bool queueRear(Queue& q, Vertex*& dataOut);
int queueCount(Queue& q);
bool emptyQueue(Queue& q);
bool fullQueue(Queue& q);

void initQueue(Queue& q)
{
    q.front = NULL;
    q.rear = NULL;
    q.count = 0;
}

bool enqueue(Queue& q, Vertex* dataIn)
{
    Node* newPtr;
    if(!(newPtr = new Node))
        return false;
    
    newPtr->data = dataIn;
    newPtr->next = NULL;

    if(q.count == 0)
        q.front = newPtr;
    else
        q.rear->next = newPtr;

    q.count++;
    q.rear = newPtr;
    return true;
}

bool dequeue(Queue& q, Vertex*& dataOut)
{
    Node* deleteLoc;

    if(q.count == 0)
        return false;
    
    dataOut = q.front->data;
    deleteLoc = q.front;
    if(q.count == 1)
        q.rear = q.front = NULL;
    else
        q.front = q.front->next;

    q.count--;

    delete deleteLoc;

    return true;
}

bool queueFront(Queue& q, Vertex*& dataOut)
{
    if(q.count == 0)
        return false;
    else
    {
        dataOut = q.front->data;
        return true;
    }
}

bool queueRear(Queue& q, Vertex*& dataOut)
{
    if(q.count == 0)
        return false;
    else
    {
        dataOut = q.rear->data;
        return true;
    }
}

bool emptyQueue(Queue& q)
{
    return (q.count == 0);
}

bool fullQueue()
{
    Node* temp;
    temp = new Node;

    if(temp != NULL)
    {
        delete temp;
        return false;
    }
    return true;
}

int queueCount(Queue& q)
{
    return q.count;
}

void deleteQueue(Queue& q)
{
    Node* deletePtr;

    while(q.front != NULL)
    {
        deletePtr = q.front;
        q.front = q.front->next;
        delete deletePtr;
    }
}