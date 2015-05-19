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
    treeBalance = 0;
}

BTree::~BTree()
{
    while(Root!=NULL)
    {
        deleteNode(Root);
        std::cout<<"node deleted"<<std::endl;
    }
}

void BTree::rotateRight(Cell* N)
{
    std::cout<<"Rotating right"<<std::endl;
    Cell* rotated = N->getRChild();
    std::cout<<"..."<<std::endl;
    Cell* B = N->getRChild()->getLChild();
    std::cout<<"..."<<std::endl;
    if(N==Root)
    {
        std::cout<<"new root: "<<N->getRChild()->getKey()<<std::endl;
        Root = N->getRChild();
        std::cout<<"..."<<std::endl;
        Root->setLChild(N);
        std::cout<<"..."<<std::endl;
        Root->resetParent();
        std::cout<<"...done"<<std::endl;
    }
    else
    {
        if(N==N->getParent()->getLChild())
        {
            std::cout<<"setting Lchild"<<std::endl;
            N->getParent()->setLChild(rotated);
            rotated->setLChild(N);
        }
        else
        {
            std::cout<<"setting Lchild"<<std::endl;
            N->getParent()->setRChild(rotated);
            rotated->setLChild(N);
        }
        if(B!=NULL)
        {
            std::cout<<"setting Rchild"<<std::endl;
            N->setRChild(B);
        }
    }
    std::cout<<"rebalancing finished"<<std::endl;
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
    std::cout<<"checking tree balance"<<std::endl;
//    if(Node->getLChild()!=NULL)
//    {
//        --treeBalance;
//    }
//    if(Node->getRChild()!=NULL)
//    {
//        ++treeBalance;
//    }
}

void BTree::addNode(int key, Cell* subRoot)
{
    Cell* Node = new Cell(key);
    Cell* Tmp = subRoot;
    if(Tmp==NULL)
    {
        std::cout<<"new root: "<<key<<std::endl;
        Root = Node;
        std::cout<<"...done"<<std::endl;
    }
    else
    {
        if(Tmp->getKey()>=key)
        {
            if (Tmp->getLChild()==NULL)
                {
                    Tmp->setLChild(Node);
                    std::cout<<"setting new LChild: "<<key<<std::endl;
                    RebalanceTree(Root);
                }
                else
                {
                    delete Node;
                    addNode(key, Tmp->getLChild());
                }
        }
        else
        {
            if (Tmp->getRChild()==NULL)
                {
                    Tmp->setRChild(Node);
                    std::cout<<"setting new RChild: "<<key<<std::endl;
                    RebalanceTree(Root);
                }
                else
                {
                    delete Node;
                    addNode(key, Tmp->getRChild());
                }
        }
    }
}

void BTree::RebalanceTree(Cell* Node)
{
    std::cout<<"rebalancing"<<std::endl;
    checkTreeBalance(Node);
    std::cout<<treeBalance<<std::endl;
    if(treeBalance<=-2)
    {
        std::cout<<"Tree is tilted to the left"<<std::endl;
        rotateLeft(Node);
        checkTreeBalance(Node);
    }
    else
    if(treeBalance>=2)
    {
        std::cout<<"Tree is tilted to the right"<<std::endl;
        rotateRight(Node);
        checkTreeBalance(Node);
    }
    else
    if(treeBalance<2 && treeBalance>-2)
    {
        std::cout<<"Tree is balanced"<<std::endl;
    }
    std::cout<<"Tree has been balanced properly"<<std::endl;
}

void BTree::deleteNode(Cell* Node)
{
    std::cout<<"deleting node"<<std::endl;
            if (Node->getLChild()==NULL && Node->getRChild()==NULL)
                {
                    if(Node==Root)
                    {
                        Root = NULL;
                        delete Node;
                        return;
                    }
                    else
                    if(Node==Node->getParent()->getLChild())
                    {
                        Node->getParent()->setRChild(Node->getLChild());
                    }
                    else
                    {
                        Node->getParent()->setLChild(Node->getLChild());
                    }
                    delete Node;
                }
            else
                if(Node->getLChild()!=NULL && Node->getRChild()==NULL)
                {
                    if(Node==Root)
                    {
                        Root = Node->getLChild();
                        delete Node;
                        return;
                    }
                    if(Node==Node->getParent()->getLChild())
                    {
                        Node->getParent()->setRChild(Node->getLChild());
                    }
                    else
                    {
                        Node->getParent()->setLChild(Node->getLChild());
                    }
                    delete Node;
                }
            else
                if(Node->getRChild()!=NULL && Node->getLChild()==NULL)
                {
                    if(Node==Root)
                    {
                        Root = Node->getRChild();
                        delete Node;
                        return;
                    }
                    if(Node==Node->getParent()->getRChild())
                    {
                        Node->getParent()->setRChild(Node->getRChild());
                    }
                    else
                    {
                        Node->getParent()->setLChild(Node->getRChild());
                    }
                    delete Node;
                }
            else
                {
                    Cell* Tmp = Node;
                    Tmp = Tmp->getRChild();
                    while(Tmp->getLChild()!=NULL)
                    {
                        Tmp = Tmp->getLChild();
                    }
                    if(Node->getParent()!=NULL)
                    {
                        if(Node==Node->getParent()->getRChild())
                        {
                            Node->getParent()->setRChild(Tmp);
                        }
                        else
                        {
                            Node->getParent()->setLChild(Tmp);
                        }
                    }
                    Tmp->getParent()->setLChild(Tmp->getRChild());
                    delete Node;
                }
    if(Root!=NULL)
    {
        RebalanceTree(Root);
    }
}

Cell* BTree::RetrieveNode(int key, Cell* subRoot)
{
    Cell* Node = subRoot;
    if(subRoot != NULL)
    {
        if(Node->getKey() == key)
            {
                return Node;
            }
        else
            if (key > Node->getKey())
            {
                RetrieveNode(key, Node->getRChild());
            }
        else
            {
                RetrieveNode(key, Node->getLChild());
            }
    }
    else
    return NULL;
}

Cell *BTree::getRoot()
{
    return Root;
}
