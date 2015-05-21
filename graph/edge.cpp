#include "edge.h"

//Edge class specific functions
Edge::Edge(Node* f, Node* t, int w)
{
    from = f;
    to = t;
    weight = w;
}

Node* Edge::getFrom()
{
    return from;
}

Node* Edge::getTo()
{
    return to;
}

int Edge::getWeight()
{
    return weight;
}
