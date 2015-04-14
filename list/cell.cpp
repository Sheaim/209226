#include <iostream>
#include <math.h>
#include "cell.h"


void Cell::set_key(std::string newKey)
{
    key = newKey;
}

std::string Cell::get_key()
{
    return key;
}

void Cell::set_value(int newValue){
	this->value=newValue;
}

int Cell::get_value(){
	return value;
}

Cell::~Cell(){
}

Cell::Cell(std::string newKey, int newValue){
	value = newValue;
	key = newKey;
	next=NULL;
	prev=NULL;
}

Cell * Cell::get_next(){

	return this->next;
}

void Cell::set_next(Cell * next){
	this->next=next;
}

Cell * Cell::get_prev(){
	return this->prev;
}

void Cell::set_prev(Cell * prev){
	this->prev=prev;
}

