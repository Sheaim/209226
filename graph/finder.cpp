#include "finder.h"
#include "node.h"
#include "edge.h"
Finder::Finder(Graph* in)
{
    g = in;
    visited = new bool[g->getNAL()];
    resetMarks();
}

void Finder::resetMarks()
{
    for(int i=0; i<g->getNAL(); i++)
    {
        visited[i]=false;
    }
}

bool Finder::checkIfVisited(int target)
{
    int i=0;
    while(g->getNodes()[i]->getKey()!=target)
    {
        ++i;
    }
    if(visited[i]==true)
        return true;
    else
        return false;
}

void Finder::markVisited(int target)
{
    int i=0;
    while(g->getNodes()[i]->getKey()!=target)
    {
        ++i;
    }
    visited[i]=true;
}

void Finder::findNodePath(Node* first, int destination)
{
    Node* current = first;
    std::cout<<current->getKey()<<std::endl;
    while(current->getKey()!=destination)
    {
        for(int i=0;i<current->getAdjArrayLength();i++)
        {
            if(checkIfVisited(current->getAdj()[i]->getTo()->getKey()));
            else
            {
                findNodePath(current->getAdj()[i]->getTo(), destination);
            }
        }
    }
}
void Finder::findNodePath(int destination)
{
    findNodePath(g->getRoot(), destination);
}
void Finder::printGraph(Node* first)
{

}

void Finder::printGraph()
{
    printGraph(g->getRoot());
}

Finder::~Finder()
{
    delete[] visited;
    delete g;
}
