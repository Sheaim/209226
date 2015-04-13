#ifndef  CellH
#define  CellH
#include <iostream>
#include <string>
#include <math.h>

class Cell{

private:
/* Deklaracja pól */
    int value;
    std::string key;
    Cell * next;
    Cell * prev;

public:

/* Deklaracja funkcji */
	void set_value(int newValue);
	int get_value();
	void set_key(std::string newKey);
	std::string get_key();
    void set_next(Cell * next);
    void set_prev(Cell * prev);
    Cell * get_next();
    Cell * get_prev();
    Cell(std::string newKey, int newValue);
    ~Cell();

};

#endif // Cell
