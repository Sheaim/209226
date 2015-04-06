/*
 * quicksort.h
 * created on april 5 2015
 * author: sheaim
 *
 */



#ifndef QUICKSORT_H_
#define QUICKSORT_H_


/*
 * /param collection
 *
 *
 */
int* quicksort_number(int* collection,int array_lenght);
int* merge_arrays_number(int* low, int lowLenght, int* high, int highLenght);

template<typename type>
type* quicksort(type* collection,int array_lenght);
template<typename type>
type* merge_arrays(type* low, int lowLenght, type* high, int highLenght);

#endif // QUICKSORT_H_
