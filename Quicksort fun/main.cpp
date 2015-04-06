#include <iostream>
// #include <windows.h>
#include <fstream>
#include <string>
#include <assert.h>


#include "common/logger.h"


#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "Stoper.hh"

/*!
 *\mainpage Program framework benchmarkujacy dla struktury danych Stos
 *\author Wojciech Makuch
 *\date 16.03.2015
 *\version 1.1
 *Program przeprowadza operacje zliczania czasu wypelnienia struktury danych stos
 *liczbami pseldolosowymi. Program sprawdza dzialanie i szybkosc obliczeniowa struktury
 *danych przy alokacji pamieci zarowno o 1 element i razy 200%.
 *Wyliczony czas podawany z dokladnoscia do us.
 *Uzyskane dane program zapisuje do pliku o nazwie "Pomiar_czasu3.txt"
 */

using namespace std;

int benchmarkFillinUpStack()
{
    const char* nazwa_pliku="Pomiar_czasu.txt";

     Stos<int> *s=new Stos<int>;
     unique_ptr<student::common::Logger> logger = new student::common::Logger( nazwa_pliku );

     logger->log( "Powiekszanie o 1:" );
     logger->log( "ilosc element.\tczas" );

     for(int i=10;i<100001;i*=10)
     {
    	 logger->log( std::to_string( i ) + "ilosc element.\tczas" + std::to_string( licz(s,i) ) );
     }

    {
        Stos<int> *s=new Stos<int>;

        logger->log( "Powiekszanie 2x:" );
        logger->log( "ilosc element.\tczas" );

        for(int i=10;i<10000001;i*=10)
        {
        	logger->log( std::to_string( i ) + "ilosc element.\tczas" + std::to_string( licz200(s,i) ) );
        }
    }
    logger->log( "Zapisano." );

    system("PAUSE"); // ????

    return 0;
}



int main()
{
    benchmarkFillinUpStack(); // TODO consider adding error handling

    return 0;
}

// TODO use external testing framework
