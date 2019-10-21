#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using std::string;
struct Vertex;
struct Arc;
struct Node;

struct Vertex
{
    char data;   
    Vertex* vNext;
    Arc* aHead;

    short processed;
    bool inTree;    //MST
    int pathLength; // For shortest path
};
struct Arc
{
    Vertex* dest; // destination
    Arc* aNext;

    int weight;
    bool inTree;
};
struct Node
{
    Vertex* data;
    Node* next;
};

#endif