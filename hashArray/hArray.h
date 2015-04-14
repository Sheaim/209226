#ifndef HARRAY_H_
#define HARRAY_H_

#include <fstream>
#include <iostream>
#include <string>

#include "hash/hash.h"
#include "list/list2.h"


class HArray
{
private:
    dllist* hashedValues[1024];
    Hash* Coder;

public:
    HArray();
    virtual ~HArray();

public:
    virtual void add(std::string key, int value); //Will reassign value to given
    virtual void add(std::string key); //This one, in stead of changing the value assigned to key will increase it by one
    virtual void remove(std::string key); //Will remove entry with given key
    virtual void printHArray();
    virtual Cell* findKey(std::string key);
};








#endif // HARRAY_H_
