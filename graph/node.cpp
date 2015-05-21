#include "node.h"
#include<iostream>

//Node class specific functions
Node::Node(int newKey)
{
    key = newKey;
    adj = NULL;
    adjArrayLength = 0;
}

void Node::resizeAdjArray(int newSize)
{
    Edge** temp = new Edge*[adjArrayLength];
    for(int i=0;i<adjArrayLength;i++)
    {
        temp[i] = adj[i];
    }
    delete[] adj;
    adj = new Edge*[newSize];
    for(int i=0;i<adjArrayLength;i++)
    {
        adj[i] = temp[i];
    }
    delete[] temp;
}

int Node::getKey()
{
    return key;
}

void Node::addEdge(Edge* adjacent)
{
    resizeAdjArray(adjArrayLength+1);
    adj[adjArrayLength] = adjacent;
    adjArrayLength++;
}

int Node::getAdjArrayLength()
{
    return adjArrayLength;
}

Edge** Node::getAdj()
{
    return adj;
}
