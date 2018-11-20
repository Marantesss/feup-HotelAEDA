#ifndef AUXFUNCTIONS_H_
#define AUXFUNCTIONS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void insertionSort(vector<T> &v);

template <class T, class A>
int sequencialSearch(vector<T> vec, A x);

#endif /* AUXFUNCTIONS_H_ */