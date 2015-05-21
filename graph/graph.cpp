#include "graph.h"
#include <iomanip>

void Graph::addNode(const int &key)
{
    vmap::iterator itr=work.begin();
    itr=work.find(key);
    if(itr==work.end())
    {
        node *v;
        v= new node(key);
        work[key]=v;
        return;
    }
    std::cout<<"\nNode already exists!";
}

void Graph::addEdge(const int& from, const int& to, double cost)
{
    node *f=(work.find(from)->second);
    node *t=(work.find(to)->second);
    std::pair<int,node *> edge = std::make_pair(cost,t);
    f->adj.push_back(edge);
    std::pair<int,node *> edge2 = std::make_pair(cost, f);
    t->adj.push_back(edge);
}


int n;
sList ** A;
bool * visited;

// Recurrent DFS procedure
//----------------------------------------
void DFS(int v)
{
  sList * p;

  visited[v] = true;     // mark as visited
  std::cout << std::setw(3) << v;  // write down visited node

// visit all unvisited neighbors

  for(p = A[v]; p; p = p->next)
    if(!visited[p->v]) DFS(p->v);
}

void Graph::findNodePath()
{
  int m,i,v1,v2;
  sList *p,*r;

  n = work.size();  //read down number of nodes

  A = new sList * [n];       // Create table of adjacency lists
  visited = new bool[n];       // create visited marks list

  //fil the matrix with empty lists
  for(i = 0; i < n; i++)
  {
    A[i] = NULL;
    visited[i] = false;
  }

  // read edge definitions
  m=0;
  for(i=0; i<work.size(); i++)
  {
      for(int j=0; j<work[i]->adj.size(); j++)
        {
            m++;
        }
  }
  for(i=0; i<work.size(); i++)
  {
      for(int j=0; j<work[i]->adj.size(); j++)
      {
        v1 = work[i]->adj[j].second->key;
        v2 = work[i]->key;
        p = new sList;    // Create new element
        p->v = v2;          // number it as v2
        p->next = A[v1];    // add it to the beggining of the list
        A[v1] = p;
      }
  }

  std::cout << std::endl;

  // DFS commences
  DFS(0);
  // delete the adjacency lists

  for(i = 0; i < n; i++)
  {
    p = A[i];
    while(p)
    {
      r = p;
      p = p->next;
      delete r;
    }
  }
  delete [] A;
   delete [] visited;

  std::cout << std::endl;
}

