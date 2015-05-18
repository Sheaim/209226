#ifndef CELL_H_
#define CELL_H_

#include <stdlib.h>
class Cell
{
    protected:
        Cell();
    private:
        Cell* parent;
        int value;
        Cell* childRight;
        Cell* childLeft;
    public:
        Cell(int newValue);
        Cell(int newValue, Cell* newParent);
        virtual ~Cell();
        virtual int getValue();
        virtual void setParent(Cell* newParent);
        virtual bool setChild(Cell* newChild);
};
#endif // CELL_H_
