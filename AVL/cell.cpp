#include "cell.h"

Cell::Cell(int newValue)
{
    parent = NULL;
    childRight = NULL;
    childLeft = NULL;
    value = newValue;
}

Cell::~Cell()
{}

int Cell::getValue()
{
    return value;
}

void Cell::setParent(Cell* newParent)
{
    parent = newParent;
}
//Should the appropriate "child" spot be taken the method will return 1 rather than do anything this is so the algorithm that makes the tree knows the spot is taken.
//In addition to that, the child's "parent" pointer is set properly.
//To add the cell to a tree you need to call the right method and add the child using the "setChild" method. We DON'T want anyone to call setParent, as this would have unforseen consequences.
bool Cell::setLChild(Cell* newChild)
{
    childLeft = newChild;
    newChild->setParent(this);
}

bool Cell::setRChild(Cell* newChild)
{
    childRight = newChild;
    newChild->setParent(this);
}
