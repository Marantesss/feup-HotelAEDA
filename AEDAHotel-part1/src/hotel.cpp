#include "hotel.h"

/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel() {}

Hotel::~Hotel() {}

vector<Reservation*> Hotel::getReservations() const {
	return this->reservations;
}

vector<Room*> Hotel::getRooms() const {
	return this->rooms;
}

vector<Client*> Hotel::getClients() const {
	return this->clients;
}

void Hotel::addClient(Client * c) {
	this->clients.push_back(c);
}

int Hotel::removeClient(string name) {
	for (size_t i = 0; i <= clients.size(); i++) {
		if (clients[i]->getName() == name) {
			this->clients.erase(clients.begin() + i);
			return 0;
		}
	}
	return -1;
}

void Hotel::addRoom(Room * r) {
	this->rooms.push_back(r);
}

int Hotel::removeRoom(int number) {
	for (size_t i = 0; i <= rooms.size(); i++) {
		if (rooms[i]->getNumber() == number) {
			this->rooms.erase(rooms.begin() + i);
			return 0;
		}
	}
	return -1;
}

void Hotel::addReservation(Reservation * R) {
	this->reservations.push_back(R);
}

