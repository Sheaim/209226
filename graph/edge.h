#ifndef EDGE_H_
#define EDGE_H_

class Node;
class Edge
{
protected:
    Edge();
private:
    Node* from;
    Node* to;
    int weight;
public:
    Edge(Node* f, Node* t, int w);
    virtual Node* getTo();
    virtual Node* getFrom();
    virtual int getWeight();
};

#endif // EDGE_H_
