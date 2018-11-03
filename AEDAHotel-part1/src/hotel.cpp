#include "hotel.h"

using namespace std;


/*****************/
/** Hotel Class **/
/*****************/

Hotel::Hotel() {}

Hotel::~Hotel() {}

vector<Reservation> Hotel::getReservations() const {
	return this->reservations;
}

vector<Reservation> Hotel::getRooms() const {
	return this->rooms;
}
