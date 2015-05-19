#include "cell.h"

Cell::Cell(int newValue)
{
    parent = NULL;
    childRight = NULL;
    childLeft = NULL;
    key = newValue;
}

Cell::~Cell()
{}

//setters

void Cell::setParent(Cell* newParent)
{
    parent = newParent;
}
//Should the appropriate "child" spot be taken the method will return 1 rather than do anything this is so the algorithm that makes the tree knows the spot is taken.
//In addition to that, the child's "parent" pointer is set properly.
//To add the cell to a tree you need to call the right method and add the child using the "setChild" method. We DON'T want anyone to call setParent, as this would cause problems (most probably Segfaults).
void Cell::setLChild(Cell* newChild)
{
    childLeft = newChild;
    newChild->setParent(this);
}

void Cell::setRChild(Cell* newChild)
{
    childRight = newChild;
    newChild->setParent(this);
}

void Cell::checkNodeBalance()
{
    if (childRight == NULL && childLeft == NULL || childRight != NULL && childLeft != NULL)
        balance = 0;
    else
        if (childRight == NULL)
        balance = 1;
    else
        balance = -1;
}

//getters
int Cell::getKey()
{
    return key;
}

Cell* Cell::getLChild()
{
    return childLeft;
}

Cell* Cell::getRChild()
{
    return childRight;
}

Cell* Cell::getParent()
{
    return parent;
}

int Cell::getBalance()
{
    checkNodeBalance();
    return balance;
}
