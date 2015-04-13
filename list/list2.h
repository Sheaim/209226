#ifndef  LIST2H
#define  LIST2H
#include <iostream>
#include <math.h>
#include "cell.h"
using namespace std;

class dllist{

private:
/* Deklaracja pól */
	int size;
	Cell * first;

public:
/* Deklaracja funkcji */
	void append(Cell * other);
	int add(Cell * other, int where);
	Cell * get_list();
	void set_list(Cell * new_first);
	void print_list();
	int delete_Cell(int index);
	void pop();

    dllist();
    ~dllist();

};

#endif
