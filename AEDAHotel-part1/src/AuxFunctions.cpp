#include "AuxFunctions.h"

template <class T>
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

void showMenu() {
}