#include "reservation.h"

/***********************/
/** Reservation Class **/
/***********************/

Reservation::Reservation(Date date, Room room) {
	this->date = date;
	this->room = room;
}

Date Reservation::getDate() const {
	return this->date;
}

Room Reservation::getRoom() const {
	return this->room;
}

void Reservation::setDate(Date date) {
	this->date = date;
}

void Reservation::setRoom(Room room) {
	this->room = room;
}

string Reservation::getInfo() {
	stringstream ss;
	ss << "Date - " << date.getInfo() << endl;
	ss << "Room - " << room.getInfo() << endl;
	return ss.str();
}

/**********************************/
/** InvalidReservation exception **/
/**********************************/

InvalidReservation::InvalidReservation(Date date, Room room) {
	this->date = date;
	this->room = room;
}

Date InvalidReservation::getDate() const {
	return this->date;
}

Room InvalidReservation::getRoom() const {
	return this->room;
}
