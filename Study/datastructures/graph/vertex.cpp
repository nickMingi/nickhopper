#include <iostream>
#include <string>
#include <climits> // for INT_MAX
#include "./vertex.h"
#include "./vertexQueue.cpp"
#include "./vertexStack.cpp"
using namespace std;



void addVertex(Vertex*& vHead, char label);
void remVertex(Vertex*& vHead, char label);
void addArc(Vertex* vHead, char from, char to, int wgt);
void remArc(Vertex* vHead, char from, char to);
Vertex* findVertex(Vertex* vHead, char key);
void printGraph(Vertex* vHead);

void breadthFirst(Vertex* vHead);
void depthFirst(Vertex* vHead);

void createMST(Vertex* vHead);
void printMST(Vertex* vHead);

void createShortestPath(Vertex* vHead, char from, char to);
void printShortestPath(Vertex* vPtr, char to, string path);

void addVertex(Vertex*& vHead, char label)
{
    Vertex* newVertex = new Vertex;
    newVertex -> data = label;
    newVertex -> vNext = nullptr;
    newVertex -> aHead = nullptr;

    if(vHead == nullptr)
    {
        vHead = newVertex;
        return;
    }

    if(vHead->data > label)
    {
        newVertex->vNext = vHead;
        vHead = newVertex;
        return;
    }

    Vertex* curVer = vHead;

    while(curVer->vNext != nullptr && curVer->vNext->data < label)
    {
        curVer = curVer -> vNext;
    }

    // Determine if curVer is null or not
    if(curVer->vNext == nullptr)
    {
        curVer->vNext = newVertex;
    }
    else
    {
        newVertex->vNext = curVer->vNext;
        curVer->vNext = newVertex;
    }
}

void remVertex(Vertex*& vHead, char label)
{
    Vertex* fromVer = vHead;
    Vertex* curVer = vHead;
    while(fromVer->vNext != nullptr)
    {
        if(fromVer->vNext->data == label)
        {
            Arc* curArc = fromVer->vNext->aHead;
            while(curArc != nullptr)
            {
                Arc* dltPtr = curArc;
                if(curArc->aNext != nullptr)
                {
                    curArc = curArc->aNext;
                    fromVer->vNext->aHead = curArc;
                    delete dltPtr;
                }
                else
                {
                    fromVer->vNext->aHead = nullptr;
                    delete dltPtr;
                    curArc = curArc->aNext;
                }
            }
            Vertex* dltPtrVer = fromVer->vNext;
            fromVer->vNext = fromVer->vNext->vNext;
            delete dltPtrVer;
        }
        else
        {
            while(curVer!=nullptr)
            {
                remArc(fromVer,curVer->data,label);
                curVer = curVer->vNext;
            }
        }
        fromVer = fromVer->vNext;
    }
}

void addArc(Vertex* vHead, char from, char to, int wgt)
{
    Vertex* fromVer = vHead;
    while(fromVer != nullptr && fromVer->data < from)
    {
        fromVer = fromVer->vNext;
    }
    if(fromVer == nullptr || fromVer->data > from)
    {
        cout << "Starting vertex is not in the list.\n";
        return;
    }
    Vertex* toVer = vHead;
    while(toVer != nullptr && toVer->data < to)
    {
        toVer = toVer->vNext;
    }
    if(toVer == nullptr || toVer->data > to)
    {
        cout << "Destination vertex is not in the list.\n";
        return;
    }

    Arc* newArc = new Arc;
    newArc->dest = toVer;
    newArc->aNext = nullptr;
    newArc->weight = wgt;

    if(fromVer->aHead == nullptr)
    {
        fromVer->aHead = newArc;
        return;
    }

    if(fromVer->aHead->dest->data > to)
    {
        newArc->aNext = fromVer->aHead;
        fromVer->aHead = newArc;
        return;
    }

    Arc* curArc = fromVer->aHead;

    while(curArc->aNext != nullptr && curArc->aNext->dest->data < to)
    {
        curArc = curArc->aNext;
    }

    // Determine if curArc is null or not
    if(curArc->aNext == nullptr)
    {
        curArc->aNext = newArc;
    }else
    {
        newArc->aNext = curArc->aNext;
        curArc->aNext = newArc;
    }

}

void remArc(Vertex* vHead, char from, char to)
{
    Vertex* fromVer = vHead;
    while(fromVer != nullptr && fromVer->data < from)
    {
        fromVer = fromVer->vNext;
    }
    if(fromVer == nullptr || fromVer->data > from)
    {
        cout << "Starting vertex is not in the list.\n";
        return;
    }
    Arc* curArc = fromVer->aHead;
    if(curArc == nullptr)
    {
        cout << "Arc head is null.";
        cout << "There is no connect between "<< from << "-"<< to<<" vertices.\n";
        return;
    }
    if(curArc->dest->data == to)
    {
        Arc* dltPtr = curArc;
        fromVer->aHead = curArc->aNext;
        delete dltPtr;
        return;
    }
    while(curArc->aNext != nullptr && curArc->aNext->dest->data < to)
    {
        curArc = curArc ->aNext;
    }
    if(curArc->aNext == nullptr || curArc->aNext->dest->data > to)
    {
        cout << "There is no connection between "<< from << "-"<< to << " vertices.\n";
        return;
    }
    else{
        Arc* dltPtr = curArc->aNext;
        curArc->aNext = curArc->aNext->aNext;
        delete dltPtr;
    }
}

Vertex* findVertex(Vertex* vHead, char key)
{
    Vertex* foundVertex = nullptr;
    Vertex* curVer = vHead;
    if(vHead == nullptr)
    {
        cout << "Graph is null" << endl;
        return nullptr;
    }else if(vHead->data == key)
    {
        return curVer;
    }
    while(curVer->vNext != nullptr && curVer->vNext->data < key)
    {
        curVer = curVer->vNext;
    }
    if(curVer->vNext == nullptr)
    {
        cout << "curVer->vNext is nullptr "<<key<<" is not found."<<endl;
        return nullptr;
    }
    else if(curVer->vNext->data == key)
    {
        cout << "Found the key! "<< curVer->vNext->data<<endl;
        foundVertex = curVer->vNext;
        return foundVertex;
    }else if(curVer->data < key)
    {
        cout << "curVer is right position to do next action"<<endl;
        cout << "Could not found the key "<<key<<endl;
        return curVer;
    }
    return foundVertex;
}

void breadthFirst(Vertex* vHead)
{
    Vertex* vWalkPtr;
    Vertex* vPtr;
    Vertex* vToPtr;
    Arc* aWalkPtr;
    Queue queue;
    initQueue(queue);

    // If graph is empty, get on out.
    if(vHead == nullptr)
        return;

    vWalkPtr = vHead;
    while(vWalkPtr != nullptr)
    {
        vWalkPtr->processed = 0;
        vWalkPtr = vWalkPtr->vNext;
    }
    vWalkPtr = vHead;
    while(vWalkPtr != nullptr)
    {
        if(vWalkPtr->processed == 0)
        {
            enqueue(queue, vWalkPtr);
            vWalkPtr->processed = 1;
        }
        while(queue.front != nullptr)
        {
            dequeue(queue, vPtr);
            cout << vPtr->data << "\t";
            vPtr->processed = 2;

            aWalkPtr = vPtr->aHead;
            while(aWalkPtr != nullptr)
            {
                vToPtr = aWalkPtr->dest;
                if(vToPtr->processed == 0)
                {
                    enqueue(queue, vToPtr);
                    vToPtr->processed = 1;
                }
                aWalkPtr = aWalkPtr->aNext;
            }
        }
        vWalkPtr = vWalkPtr->vNext;
    }
    cout << "" << endl;
}

void depthFirst(Vertex* vHead)
{
    Vertex* vWalkPtr;
    Vertex* vPtr;
    Vertex* vToPtr;
    Stack stack;
    initStack(stack);
    Arc* aWalkPtr;

    if(vHead == nullptr)
        return;

    vWalkPtr = vHead;
    while(vWalkPtr != nullptr)
    {
        vWalkPtr->processed = 0;
        vWalkPtr = vWalkPtr->vNext;
    }

    vWalkPtr = vHead;
    while(vWalkPtr != nullptr)
    {
        if(vWalkPtr->processed == 0)
        {
            pushStack(stack, vWalkPtr);
            vWalkPtr->processed = 1;
        }

        while(stack.top != nullptr)
        {
            popStack(stack, vPtr);
            cout << vPtr->data << '\t';
            vPtr->processed = 2;

            aWalkPtr = vPtr->aHead;
            while(aWalkPtr != nullptr)
            {
                vToPtr = aWalkPtr->dest;
                if(vToPtr->processed == 0)
                {
                    pushStack(stack, vToPtr);
                    vToPtr->processed = 1;
                }
                aWalkPtr = aWalkPtr->aNext;
            }
        }
        vWalkPtr = vWalkPtr->vNext;
    }
    cout << "" << endl;
}

void printGraph(Vertex* vHead)
{
    Vertex* curVer = vHead;
    Arc* curArc;
    while(curVer != nullptr)
    {
        cout << curVer->data;
        if(curVer->aHead != nullptr)
            cout << " -> ";
        curArc = curVer->aHead;
        while(curArc != nullptr)
        {
            cout << curArc->dest->data;
            if(curArc->aNext != nullptr)
                cout << " -> ";

            curArc = curArc->aNext;
        }
        curVer = curVer->vNext;
        cout << endl;
    }
    cout << "" << endl;
}

void createMST(Vertex* vHead)
{
    if(vHead == nullptr)
        return;

    Vertex* vPtr = vHead;
    Arc* aPtr;

    while(vPtr != nullptr)
    {
        vPtr->inTree = false;
        aPtr = vPtr->aHead;
        while(aPtr != nullptr)
        {
            aPtr->inTree = false;
            aPtr = aPtr->aNext;
        }
        vPtr = vPtr->vNext;
    }
    //Create MST
    bool treeComplete = false;
    Arc* minAPtr;
    int minArc;

    vPtr = vHead;
    vPtr->inTree = true;

    while(treeComplete == false)
    {
        treeComplete = true;
        vPtr = vHead;
        minArc = INT_MAX;
        minAPtr = nullptr;

        while(vPtr != nullptr)
        {
            if(vPtr->inTree == true && vPtr->aHead != nullptr)
            {
                aPtr = vPtr->aHead;
                while(aPtr != nullptr)
                {
                    if(aPtr->dest->inTree == false)
                    {
                        treeComplete = false;
                        if(aPtr->weight < minArc)
                        {
                            minArc = aPtr->weight;
                            minAPtr = aPtr;
                        }
                    }
                    aPtr = aPtr->aNext;
                }
            }
            vPtr = vPtr->vNext;
        }
        if(minAPtr != nullptr)
        {
            minAPtr->inTree = true;
            minAPtr->dest->inTree = true;
        }
    }
    printMST(vHead);
}

void printMST(Vertex* vHead)
{
    Vertex* vPtr = vHead;
    Arc* aPtr = nullptr;

    while(vPtr != nullptr)
    {
        cout << vPtr->data;
        aPtr = vPtr->aHead;

        while(aPtr != NULL)
        {
            if(aPtr != NULL)
                cout << " -> "<<aPtr->dest->data<<':'<<aPtr->weight;

            aPtr = aPtr->aNext;
        }
        cout << endl;
        vPtr = vPtr->vNext;
    }
}

void createShortestPath(Vertex* vHead, char from, char to)
{
    if(vHead == nullptr)
        return;

    Vertex* vPtr = vHead;
    Arc* aPtr;

    while(vPtr != nullptr)
    {
        vPtr->inTree = false;
        vPtr->pathLength = 10000;
        aPtr = vPtr->aHead;
        while(aPtr != nullptr)
        {
            aPtr->inTree = false;
            aPtr = aPtr->aNext;
        }
        vPtr = vPtr->vNext;
    }
    bool treeComplete = false, destFound = false;
    Arc* minAPtr,*pathPtr;
    int minArc, minPath, newPathLength;

    vPtr = findVertex(vHead, from);
    vPtr->inTree = true;
    vPtr->pathLength = 0;

    while(treeComplete == false)
    {
        treeComplete = true;
        vPtr = vHead;
        minAPtr = nullptr;
        newPathLength = 10000;
        pathPtr = nullptr;
        while(vPtr != nullptr)
        {
            if(vPtr->inTree == true && vPtr->aHead != nullptr)
            {
                aPtr = vPtr->aHead;
                minPath = vPtr->pathLength;
                minArc = 10000;
                while(aPtr != nullptr)
                {
                    if(aPtr->dest->inTree == false)
                    {
                        treeComplete = false;
                        if(aPtr->weight < minArc)
                        {
                            minArc = aPtr->weight;
                            minAPtr = aPtr;
                        }
                    }
                    aPtr = aPtr->aNext;
                }
                if(minPath + minArc < newPathLength)
                {
                    newPathLength = minPath + minArc;
                    pathPtr = minAPtr;
                }
            }
            vPtr = vPtr->vNext;
        }
        if(pathPtr != nullptr)
        {
            pathPtr->inTree = true;
            pathPtr->dest->inTree = true;
            pathPtr->dest->pathLength = newPathLength;
            if(pathPtr->dest->data == to)
            {
                destFound = true;
                treeComplete = true;
            }
        }
    }
    if(destFound == true)
    {
        cout << "\nShortest path from "<<from<<" to "<<to<<" found.\n";
        printShortestPath(findVertex(vHead,'A'), to, "");
    }
    else
    {
        cout << "\nNo path from" <<from<<" to "<<to<<" exists.\n";
    }
}

void printShortestPath(Vertex* vPtr, char to, string path)
{
    if(vPtr->data == to)
    {
        path = path + to;
        cout << path;
    }
    else
    {
        path = path + vPtr->data;
        Arc* aPtr = vPtr->aHead;
        while(aPtr != nullptr)
        {
            if(aPtr->inTree == true)
                printShortestPath(aPtr->dest, to , path);

            aPtr = aPtr->aNext;
        }
    }
}

int vertexmain()
{
    Vertex* gHead = nullptr;

    addVertex(gHead, 'A');
    addVertex(gHead, 'B');
    addVertex(gHead, 'C');
    addVertex(gHead, 'D');
    addVertex(gHead, 'E');
    addVertex(gHead, 'F');

    addArc(gHead, 'A', 'B', 5);
    addArc(gHead, 'B', 'A', 5);

    addArc(gHead, 'B', 'C', 2);
    addArc(gHead, 'C', 'B', 2);

    addArc(gHead, 'B', 'E', 3);
    addArc(gHead, 'E', 'B', 3);

    addArc(gHead, 'C', 'E', 1);
    addArc(gHead, 'E', 'C', 1);

    addArc(gHead, 'C', 'D', 8);
    addArc(gHead, 'D', 'C', 8);

    addArc(gHead, 'E', 'D', 7);
    addArc(gHead, 'D', 'E', 7);

    addArc(gHead, 'E', 'F', 6);
    addArc(gHead, 'F', 'E', 6);

    printGraph(gHead);

    breadthFirst(gHead);

    depthFirst(gHead);

    createMST(gHead);

    createShortestPath(gHead,'A','E');

    return 0;
}