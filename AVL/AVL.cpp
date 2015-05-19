/*
 * AVL.cpp
 * created on may 18 2015
 * author: sheaim
 *
 */
#include <iostream>
#include "AVL/AVL.h"
#include "AVL/cell.h"
#include "common/logger.h"

BTree::BTree()
{
    Root = NULL;
}

BTree::~BTree()
{
    while(Root!=NULL)
    {
        deleteNode(Root);
    }
}

void BTree::rotateRight(Cell* N)
{
    Cell* rotated = N->getRChild();
    Cell* B = N->getRChild()->getLChild();

    if(N==N->getParent()->getLChild())
    {
        N->getParent()->setLChild(rotated);
    }
    else
    {
        N->getParent()->setRChild(rotated);
    }
    rotated->setLChild(N);
    N->setRChild(B);
}

void BTree::rotateLeft(Cell* N)
{
    Cell* rotated = N->getLChild();
    Cell* B = N->getLChild()->getRChild();
    if(N==N->getParent()->getLChild())
    {
        N->getParent()->setLChild(rotated);
    }
    else
    {
        N->getParent()->setRChild(rotated);
    }
    rotated->setRChild(N);
    N->setLChild(B);
}

void BTree::checkTreeBalance(Cell* Node)
{
    if(Node==NULL)
        treeBalance=0;
    else
    {
        if(Node->getRChild()!=NULL)
            {
                treeBalance+=Node->getRChild()->getBalance();
                checkTreeBalance(Node->getRChild());
            }
        if(Node->getLChild()!=NULL)
            {
                treeBalance+=Node->getLChild()->getBalance();
                checkTreeBalance(Node->getLChild());
            }
    }
}

void BTree::addNode(int key)
{

}

void BTree::deleteNode(Cell* node)
{

}

Cell* BTree::retrieveNode(int key)
{

}

