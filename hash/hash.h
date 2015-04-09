#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <fstream>
#include <iostream>

class Hash
{
private:
    int seed;
public:
    Hash();
    virtual ~Hash();
    virtual unsigned int h(std::string &toHash);
};
#endif
