#include "graph.h"
#include "edge.h"
#include "node.h"
//Graph class specific functions

Graph::Graph()
{
    root = NULL;
    nodeArrayLength = 0;
    edgeArrayLength = 0;
}

Graph::~Graph()
{
    delete[] nodes;
    delete[] edges;
    root = NULL;
}

Node* Graph::getRoot()
{
    return root;
}
void Graph::resizeEdgeArray(int newLength)
{
    Edge** temp = new Edge*[edgeArrayLength];
    for(int i=0; i<edgeArrayLength; ++i)
    {
        temp[i] = edges[i];
    }
    delete[] edges;
    edges = new Edge*[newLength];
    for(int i=0; i<edgeArrayLength; ++i)
    {
        edges[i] = temp[i];
    }
    delete[] temp;
}

void Graph::resizeNodeArray(int newLength)
{
    Node** temp = new Node*[nodeArrayLength];
    for(int i=0; i<nodeArrayLength; ++i)
    {
        temp[i] = nodes[i];
    }
    delete[] nodes;
    nodes = new Node*[newLength];
    for(int i=0; i<nodeArrayLength; ++i)
    {
        nodes[i] = temp[i];
    }
    delete[] temp;
}

void Graph::addNode(int key)
{
    Node* newNode = new Node(key);

    if(root==NULL)
        {
            root = newNode;
        }
    resizeNodeArray(nodeArrayLength+1);
    nodes[nodeArrayLength]=newNode;
    nodeArrayLength++;
}

void Graph::addEdge(Node* from, Node* to, int weight)
{
    Edge* newEdge = new Edge(from, to, weight);
    resizeEdgeArray(edgeArrayLength+1);
    edges[edgeArrayLength]=newEdge;
    edgeArrayLength++;
    from->addEdge(newEdge);
}
void Graph::addEdge(int fromKey, int toKey, int weight)
{
    int i;
    for(i=0; i<nodeArrayLength; i++)
    {
        if(nodes[i]->getKey()==fromKey)
            {
                break;
            }
        else;
    }
    Node* From = nodes[i];
    for(i=0; i<nodeArrayLength; i++)
    {
        if(nodes[i]->getKey()==toKey)
            {
                break;
            }
        else;
    }
    Node* To = nodes[i];
    addEdge(From, To, weight);
}
Node** Graph::getNodes()
{
    return nodes;
}
Edge** Graph::getEdges()
{
    return edges;
}
int Graph::getEAL()
{
    return edgeArrayLength;
}
int Graph::getNAL()
{
    return nodeArrayLength;
}
