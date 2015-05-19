/*
 * AVL.h
 * created on may 18 2015
 * author: sheaim
 *
 */

#include "cell.h"
#ifndef AVL_H_
#define AVL_H_

class BTree
{
    protected:
        virtual void rotateRight(Cell* N);
        virtual void rotateLeft(Cell* N);
        virtual void checkTreeBalance(Cell* Node);
    private:
        Cell* Root;
        int treeBalance;
    public:
        //generic constructor for creating an empty tree
        BTree();
        virtual ~BTree();

    public:
        virtual Cell* getRoot();
        virtual void addNode(int key, Cell* subRoot);
        virtual void deleteNode(Cell* node);
        virtual Cell* RetrieveNode(int key, Cell* subRoot);
        virtual void RebalanceTree(Cell* Node);
};



#endif // AVL_H_
