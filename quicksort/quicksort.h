/*
 * quicksort.h
 * created on april 5 2015
 * author: sheaim
 *
 */



#ifndef QUICKSORT_H_
#define QUICKSORT_H_
const std::string wrong_value_error_message = "Error: array part is not a number.";

/*
 * /param collection
 *
 *
 */
int* quicksort_number(int* collection,int array_lenght);
int* merge_arrays_number(int* low, int lowLenght, int* high, int highLenght);







//As I cannot have templates in a .cpp file, they need to be defined in a 'h file.
//TODO split this file in two, correct includes in other files and Cmakelist.txt


template<typename type>
type* quicksort(type* collection,int array_lenght);
template<typename type>
type* merge_arrays(type* low, int lowLenght, type* high, int highLenght);

template<typename type>
type* merge_arrays(type* low, int lowArrayLenght, type* high, int highArrayLenght)
{
    std::cout<<"low array"<<std::endl;
    for(int i=0; i<lowArrayLenght;++i)
    {
        std::cout<<low[i]<<" ";
    }
    std::cout<<std::endl;
    int mergedArrayLenght = lowArrayLenght+highArrayLenght;
    type* mergedArray = new type[mergedArrayLenght];
    for(int i=0; i<lowArrayLenght;++i)
    {
        mergedArray[i] = low[i];
    }
    std::cout<<"high array"<<std::endl;
    for(int i=0; i<highArrayLenght;++i)
    {
        std::cout<<high[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0; i<highArrayLenght;++i)
    {
        mergedArray[i+lowArrayLenght] = high[i];
    }
    for(int i=0; i<mergedArrayLenght;++i)
    {
        std::cout<<mergedArray[i]<<" ";
    }
    std::cout<<std::endl;
    return mergedArray;
}



template<typename type>
type* quicksort(type* collection, int array_lenght)
{
    type pivot;
    type* low = new type[array_lenght];
    type* high = new type[array_lenght];
    int counterOfLowArrayElements=0;
    int counterOfHighArrayElements=0;
    for(int i=0; i<array_lenght;++i)
    {
        std::cout<<collection[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"finding pivot"<<std::endl;
    pivot = 0;
    for (int i=0; i<array_lenght; ++i)
    {
        pivot = pivot + collection[i];
    }
    pivot = pivot/array_lenght;
    for(int i=0; i<array_lenght; ++i)
    {
        if (collection[i]<=pivot)
        {
            std::cout<<"adding "<<collection[i]<<"to low"<<std::endl;
            low[counterOfLowArrayElements]=collection[i];
            ++counterOfLowArrayElements;
        }
        else
            if(collection[i]>pivot)
        {
            high[counterOfHighArrayElements]=collection[i];
            ++counterOfHighArrayElements;
            std::cout<<"adding "<<collection[i]<<"to high"<<std::endl;
        }
        else
        {
            std::cout<<wrong_value_error_message<<std::endl;
            break;
        }
    }

    if(counterOfLowArrayElements!=1)
    {
        quicksort_number(low, counterOfLowArrayElements);
        quicksort_number(high, counterOfHighArrayElements);
    }


    for(int i=0; i<array_lenght;++i)
    {
        collection[i] = merge_arrays<type>(low, counterOfLowArrayElements, high, counterOfHighArrayElements)[i];
        std::cout<<collection[i]<<" ";
    }
    std::cout<<std::endl;
    return collection;
}


#endif // QUICKSORT_H_
