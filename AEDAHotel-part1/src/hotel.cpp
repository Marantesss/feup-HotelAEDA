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
