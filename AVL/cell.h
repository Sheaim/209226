#ifndef CELL_H_
#define CELL_H_

#include <stdlib.h>
class Cell
{
    protected:
    //we don't want anyone to call onto generic constructor and setParent, as the latter is only useful in child setters and the first is useless as we have no value setter.
        Cell();
        virtual void setParent(Cell* newParent);
    private:
        Cell* parent;
        int key;
        Cell* childRight;
        Cell* childLeft;
    public:
        Cell(int newValue);
        virtual ~Cell();
//setters
    public:
        virtual bool setLChild(Cell* newChild);
        virtual bool setRChild(Cell* newChild);
//getters;
    public:
        virtual Cell* getLChild();
        virtual Cell* getRChild();
        virtual int getKey();
//setter for key is not needed, as the value is static and will not change.
//beware: you will need to get both children when deleting the parent node, as not doing so will result in memory leaks.
};
#endif // CELL_H_
