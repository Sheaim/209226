#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "hash.h"

Hash::Hash()
{
    seed = 23; //Just a prime value
}

Hash::~Hash()
{
    seed = 0;
}

unsigned int Hash::h(std::string &toHash)
{
    const char* in = toHash.c_str();
    unsigned int out=0;
    while(*in!=NULL)
    {
        out *= seed;
        out += *in;
        out = out%sizeof(int);
        ++in;
    }
    return out;
}
