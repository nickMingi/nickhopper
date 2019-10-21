#include <iostream>
#include "./vertex.h"
using namespace std;

struct Stack
{
    int count;
    Node* top;
};

void initStack(Stack& s);
void deleteStack(Stack& s);
bool pushStack(Stack& s, Vertex* dataIn);
bool popStack(Stack& s, Vertex*& dataOut);
bool stackTop(Stack& s, Vertex*& dataOut);
bool emptyStack(Stack& s);
bool fullStack(Stack& s);
int stackCount(Stack& s);

void initStack(Stack& s)
{
    s.top = NULL;
    s.count = 0;
}

void deleteStack(Stack& s)
{
    Node* temp;

    while(s.top != NULL)
    {
        temp = s.top;
        s.top = s.top->next;
        delete temp;
    }
}

bool pushStack(Stack& s, Vertex* dataIn)
{
    bool success;
    Node* newPtr;

    if(!(newPtr = new Node))
        success = false;
    else
    {
        newPtr->data = dataIn;
        newPtr->next = s.top;
        s.top = newPtr;
        s.count++;
        success = true;
    }
    return success;
}

bool popStack(Stack& s, Vertex*& dataOut)
{
    Node* dltPtr;
    bool success;

    if(s.count == 0)
        success = false;
    else
    {
        dltPtr = s.top;
        dataOut = s.top->data;
        s.top = s.top->next;
        s.count--;
        delete dltPtr;
        success = true;
    }
    return success;
}

bool stackTop(Stack& s, Vertex*& dataOut)
{
    bool success;

    if(s.count == 0)
        success = false;
    else
    {
        dataOut = s.top->data;
        success = true;
    }
    return success;
}

bool emptyStack(Stack& s)
{
    return (s.count ==0);
}

bool fullStack()
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

int stackCount(Stack& s)
{
    return s.count;
}