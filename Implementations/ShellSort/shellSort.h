#include <vector>
#include<iostream>
#include<fstream>
#include<string.h>

template<typename T>
void shellSort(std::vector<T> &array, std::vector<int> &gaps, int(*f)(T a, T b)) 
{   int dimension = array.size();
    for (int i = 0; i < gaps.size(); i++) 
    {   int gap = gaps[i];
        for (int i = gap; i < dimension; i += 1) 
        { 
            T temp = array[i]; 
            int j;             
            for (j = i; j >= gap && f(array[j - gap], temp) > 0; j -= gap) 
                array[j] = array[j - gap]; 
            array[j] = temp; 
        } 
    } 
}
