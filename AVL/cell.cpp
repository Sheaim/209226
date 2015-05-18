#include "cell.h"

Cell::Cell(int newValue)
{
    parent = NULL;
    childRight = NULL;
    childLeft = NULL;
    value = newValue;
}

Cell::Cell(int newValue, Cell* newParent)
{
    parent = newParent;
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
bool Cell::setChild(Cell* newChild)
{
    if ((this->childLeft!=NULL && (this->childRight!=NULL || this->value < newChild->value)) || (this->childRight!=NULL && this->value >= newChild->value))
        {
            return 1;
        }
    else
        if(this->value >= newChild->value)
        {
            this->childLeft = newChild;
            newChild->setParent(this);
            return 0;
        }
    else
        if(this->value < newChild->value)
        {
           this->childRight = newChild;
           newChild->setParent(this);
           return 0;
        }
}
