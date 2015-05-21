#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
            #include <vector>
            #include <map>
            #include <string>

            struct node{
                typedef std::pair<int,node*> ve;
                std::vector<ve> adj; //cost of edge, destination node
                int key;
                bool visited;
                node(int s)
                {
                    visited = 0;
                    key=s;
                }
            };

            //helper list
struct sList
{
  sList * next;
  int v;
};


class Graph
{
public:
        typedef std::map<int, node *> vmap;
        vmap work;
        void addNode(const int&);
        void addEdge(const int& from, const int& to, double cost);
        void findNodePath();
};
#endif // GRAPH_H_
