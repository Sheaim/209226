/*
 * AVL.h
 * created on may 18 2015
 * author: sheaim
 *
 */


#ifndef AVL_H_
#define AVL_H_

#include <iostream>
#include <string>
#include "node.h"

class AVLTree {
private:

    Node* root;
    virtual void push(const int n, Node * & v);
    virtual bool search( const int s, Node * & tree);
    virtual void clear(Node* tree);
public:
    AVLTree();
    virtual ~AVLTree();

    virtual Node* getRoot();
    virtual void push(const int n);

    virtual void printPreOrder() const;
    virtual void preOrder(Node* pre) const;

    virtual void clear();

    //rotations
    virtual void singleRightRotate(Node * & n);
    virtual void doubleRightRotate(Node * & n);
    virtual void singleLeftRotate(Node * & n);
    virtual void doubleLeftRotate(Node * & n);

    //search and utility functions
    virtual bool search(const int s);
    virtual int avlHeight (Node * h);
    virtual int max(int v1, int v2);
    virtual void print(Node *node, int level);
};



#endif // AVL_H_
