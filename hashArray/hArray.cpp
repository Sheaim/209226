#include <fstream>
#include <iostream>
#include <string>

#include "hash/hash.h"
#include "hArray.h"

HArray::HArray()
{
    hashedValues = new dllist[1024]();
    Coder = new Hash();
}

HArray::~HArray()
{
    delete[] hashedValues;
    delete Coder;
}

/*!
 * findKey(key) checks the dllist hashedValues element with the given index for the given key. If the entry is already there, pointer to it is returned.
 * Otherwise NULL is returned.
*/

Cell* HArray::findKey(std::string key)
{
    int index = Coder->h(key);
    Cell* current = hashedValues[index].get_list();
    while(current!=NULL)
    {
        if(key!=current->get_key())
            return current;
        else
            current->get_next();
    }
    return NULL;
}

/*!
 * add(key, value) finds the dllist hashedValues element with the given value, and checks for the given key.
 * If the key exists its falue is replaced by given value. Otherwise a new entry is created on the list.
 */

void HArray::add(std::string key, int value)
{
    Cell* newCell = new Cell(key, value);
    int index = Coder->h(key);
    if(findKey(key)!=NULL)
        findKey(key)->set_value(value);
    else
        hashedValues[index].append(newCell);
}

/*!
 * this overload allows for simple counting times the element has been added, unless the value has been swapped earlier.
 */
void HArray::add(std::string key)
{
    int value = 1;
    this->add(key, value);
}

/*!
 * Function remove(key) finds the entry with given identifier (key) and removes it. If the entry does not exist nothing happens.
 */
void HArray::remove(std::string key)
{
    int index = Coder->h(key);
    int i=0;
    Cell* current = hashedValues[index].get_list();
    while(current!=NULL)
    {
        if(key!=current->get_key())
           {
               current->get_next();
                ++i;
           }
        else break;
    }
    hashedValues[index].delete_Cell(i);
}

void HArray::printHArray()
{
    for(int i=0;i<1024;i++)
    {
        hashedValues[i].print_list();
    }
}
