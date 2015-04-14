#include <iostream>
#include <math.h>
#include "list2.h"


void dllist::print_list(){
	Cell * current=first;

	while(current!=NULL){
		std::cout<<current->get_key()<<": "<<current->get_value()<<" ";
		current=current->get_next();
	}
	std::cout<<std::endl;
}

/* Usuwa element o zadanym indeksie */
/* Zwraca -1 w przypadku niepowodzenia, 0 w p.p */

int dllist::delete_Cell(int index){

	std::cout<<"^Deleting Cell nr "<<index<<"^"<<std::endl;

	Cell * destination = first;

	if(index<0||first==NULL||index>=size) return -1;

	if(index==0){
		first->get_next()->set_prev(NULL);
		first=first->get_next();
		delete destination;
		return 0;
	}

	for(int i=1; i<=index; i++){
		destination=destination->get_next();
	}

	Cell * before = destination->get_prev();
	Cell * after = destination->get_next();

	after->set_prev(before);
	before->set_next(after);


	delete destination;
	return 0;



}

/* getter : first */
Cell * dllist::get_list(){
	return first;
}

/* setter : first */
void dllist::set_list(Cell * new_first){
	this->first=new_first;
}


/* Konstruktor bazowy */
dllist::dllist(){
	first = NULL;
	size = 0;
}

/* Destruktor bazowy */
dllist::~dllist(){

	Cell * rubbish = first;
	Cell * rubbish_parent=NULL;

//znajdz ostatnia komorke (usuwamy od ostatniej)
	while(rubbish->get_next()!=NULL){
		rubbish=rubbish->get_next();
	}

	std::cout<<"^mam ostania komorke^"<<std::endl;
//znajdŸ jej rodzica i usuñ
	while(rubbish_parent!=first){
		rubbish_parent = rubbish->get_prev();
		delete rubbish;
		rubbish_parent->set_next(NULL);
		rubbish=rubbish_parent;
	}
//zosta³a ju¿ tylko komórka first
	delete first;
}

/* Dodaje element na koniec listy */

void dllist::append(Cell * other){

	if(first==NULL){
		first=other;
	}
    else
    {
        Cell * destination = first;

        while(destination->get_next()!=NULL){
            destination=destination->get_next();
        }

        destination->set_next(other);
        other->set_prev(destination);
    }
    size++;
}

/* Wstawia element w wyznaczone miejsce */
/* Zwraca 0, jesli sie udalo, -1 w. p.p. */
int dllist::add(Cell * other, int where){

	if(where>=size||where<0){
		return -1;
	}

	Cell * destination = first;

	if(where==0){
		this->first=other;
	}

	for(int i=1; i<=where; i++){
		destination=destination->get_next();
	}

	other->set_next(destination);
	destination->set_prev(other);

	size++;
	return 0;

}
