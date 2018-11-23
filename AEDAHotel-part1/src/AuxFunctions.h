#ifndef AUXFUNCTIONS_H_
#define AUXFUNCTIONS_H_

#include <iostream>
#include <string>
#include <vector>
#include "room.h"

using namespace std;

template <class T>
/**
* @brief Function to sort a vector by some specific condition.
*
* @param v The vector to be sorted.
*/
void insertionSort(vector<T> &v)
{
    for (unsigned int p = 1; p < v.size(); p++)
    {
    	T tmp = v[p];
    	int j;
    	for (j = p; j > 0 && tmp < v[j-1]; j--)
    		v[j] = v[j-1];
    	v[j] = tmp;
    }
}

template <class T, class A>
/**
* @brief Function to search an object in a vector of objects.
*
* @param vec The vector to be searched in.
*
* @param x The object to be searched.
*/
int sequencialSearch(vector<T> vec, A x) {
	for (unsigned int i = 0; i < vec.size(); i++)
		if (vec[i] == x)
			return i;
	return -1;
}

#endif /* AUXFUNCTIONS_H_ */
