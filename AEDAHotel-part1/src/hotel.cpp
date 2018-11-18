#include "hotel.h"

/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel() {}

Hotel::~Hotel() {}

vector<Reservation> Hotel::getReservations() const {
	return this->reservations;
}

vector<Room> Hotel::getRooms() const {
	return this->rooms;
}

vector<Client> Hotel::getClients() const {
	return this->clients;
}

void Hotel::sortClients() {
	insertionSort(this->clients);
}

void Hotel::addClient(Client & c) {
	this->clients.push_back(c);
}

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
