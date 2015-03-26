#include <iostream>
#include <windows.h>
#include <fstream>

#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "Stoper.hh"

using namespace std;

template<typename typ>
Stos<typ> quicksort(Stos<typ> unsorted)
{
    Stos<typ> sorted = unsorted;
    typ* i;
    typ* j;
    i=sorted.get_tab();
    j=sorted.get_tab()+sorted.size();
    /*!
     * \brief algorytm quicksort w calej swej ozdobie
     */
    typ pivot;
    typ *temp;
    for (int z=0; z<unsorted.size(); z++)
    {
        if(pivot<sorted.get_tab(z))
        {
            pivot = sorted.get_tab(z);
        }
    }
    pivot = pivot/2;
    while(*i<=*j)
    {
        while(*i<pivot)
        {
            i++;
            while(*j>pivot)
            {
                j--;
            }
        }
        temp = i;
        i=j;
        j=temp;
    }
    return sorted;
}
