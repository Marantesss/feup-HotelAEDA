#ifndef AUXFUNCTIONS_H_
#define AUXFUNCTIONS_H_

#include <iostream>
#include <string>
#include <vector>
#include "hotel.h"

using namespace std;

template <class T>
void insertionSort(vector<T> &v);

template <class T, class A>
int sequencialSearch(vector<T> vec, A x);

int menu();

int hotelInformationMenu(Hotel *h);

int hotelChangeInformationMenu(Hotel *h);

#endif /* AUXFUNCTIONS_H_ */