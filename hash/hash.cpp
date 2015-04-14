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

int Hash::h(std::string &toHash)
{
    const char* in = toHash.c_str();
    int out=0;
    for(int i=0; i<toHash.length(); ++i)
    {
        out *= seed;
        out += in[i];
        out = out%1024;
    }
    return out;
}

