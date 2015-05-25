#ifndef FINDER_H_
#define FINDER_H_
#include "graph.h"

class Finder
{
protected:
    Finder();
    virtual void printGraph(Node* first);
    virtual void findNodePath(Node* First, int destination);
private:
    Graph* g;
    bool* visited;
public:
    Finder(Graph*);
    virtual ~Finder();

    virtual void markVisited(int target);
    virtual void resetMarks();
    virtual bool checkIfVisited(int target);
    virtual void printGraph();
    virtual void findNodePath(int destination);
};

#endif
