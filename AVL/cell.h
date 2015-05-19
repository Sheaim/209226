#ifndef CELL_H_
#define CELL_H_

#include <stdlib.h>
class Cell
{
    protected:
    //we don't want anyone to call onto generic constructor and setParent, as the latter is only useful in child setters and the first is useless as we have no value setter.
        Cell();
        virtual void checkNodeBalance();
        virtual void setParent(Cell* newParent);
    private:
        Cell* parent;
        Cell* childRight;
        Cell* childLeft;
        //in this case "key" value is also the record. Using hashing function would enable us to compile a dictionary similar to that made in "harray"
        int key;
        int balance;
    public:
        Cell(int newValue);
        virtual ~Cell();
//setters
    public:
        virtual void setLChild(Cell* newChild);
        virtual void setRChild(Cell* newChild);
//getters;
    public:
        virtual Cell* getLChild();
        virtual Cell* getRChild();
        virtual Cell* getParent();
        virtual int getKey();
        virtual int getBalance();
//setter for key is not needed, as the value is static and will not change.
//beware: you will need to get both children when deleting the parent node, as not doing so will result in memory leaks.
};
#endif // CELL_H_
