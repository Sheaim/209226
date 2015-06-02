#ifndef CELL_H_
#define CELL_H_

#include <stdlib.h>

//As I found it's easier to operate on struct in this particular case. Most AVL tree implementations available online use this method.
struct Node
{
        Node* left;
        Node* right;
        int height;
        int data;
        Node() {left = NULL; right = NULL;};
        Node(const int &v, Node* l, Node* r, int h){data = v; left = l;  right = r; height = h;};
};
#endif // CELL_H_
