/*
 * BST.h
 * created on june 2 2015
 * author: sheaim
 *
 */


#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
#include "node.h"

class BSTree {
private:

    Node* root;
    virtual void push(const int & n, Node * & v);
    virtual bool search( const int& s, Node * & tree) ;
public:
    BSTree();
    virtual ~BSTree();

    virtual Node* getRoot();
    virtual void push(const int & n);

    virtual void printPreOrder() const;
    virtual void preOrder(Node* pre) const;

    virtual void clear(Node* & tree);

    //search and utility functions
    virtual bool search(const int & s);
    virtual int bstHeight (Node * h);
    virtual int max(int v1, int v2);
    virtual void print(Node *node, int level);
};



#endif // AVL_H_
