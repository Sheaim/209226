#ifndef NODE_H_
#define NODE_H_

class Edge;
class Node
{
protected:
    Node();
private:
    int key;
    int adjArrayLength;
    Edge** adj;
public:
    Node(int newKey);
    virtual int getKey();
    virtual int getAdjArrayLength();
    virtual void resizeAdjArray(int newSize);
    virtual void addEdge(Edge* adjacent);
    virtual Edge** getAdj();
};

#endif // NODE_H_
