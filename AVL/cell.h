#ifndef CELL_H_
#define CELL_H_

#include <stdlib.h>
class Cell
{
    protected:
        Cell();
        virtual void setParent(Cell* newParent);
    private:
        Cell* parent;
        int value;
        Cell* childRight;
        Cell* childLeft;
    public:
        Cell(int newValue);
        virtual ~Cell();
        virtual int getValue();
        virtual bool setLChild(Cell* newChild);
        virtual bool setRChild(Cell* newChild);
};
#endif // CELL_H_
