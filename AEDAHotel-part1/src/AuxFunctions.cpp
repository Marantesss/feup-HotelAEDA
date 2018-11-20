#include "AuxFunctions.h"

template <typename T>
void insertionSort(vector<T> &v) {
	for (size_t i = 1; i < v.size(); i++)
	{
		T tmp = v[i];
		size_t j;
		for (j = i; j > 0 && tmp < v[j - 1]; j--) {
			v[j] = v[j - 1];
		}
		v[j] = tmp;
	}
}

template <class T, class A>
int sequencialSearch(vector<T> vec, A x) {
	for (unsigned int i = 0; i < vec.size(); i++)
		if (vec[i] == x)
			return i;
	return -1;
}

