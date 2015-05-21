#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
class Edge;
class Node;

class Graph
{
protected:
    virtual void resizeNodeArray(int newLength);
    virtual void resizeEdgeArray(int newLength);
    virtual void addEdge(Node* from, Node* to, int weight);
    int nodeArrayLength;
    int edgeArrayLength;
private:
    Node* root;
    Node** nodes;
    Edge** edges;
public:
    Graph();
    virtual ~Graph();
public:
    virtual Node* getRoot();
    virtual void addNode(int key);
    virtual void addEdge(int fromKey, int toKey, int weight);
    virtual int* findNodePath(int destination);
    virtual void printGraph(Node* first);
};
#endif // GRAPH_H_
