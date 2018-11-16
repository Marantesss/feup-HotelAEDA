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
