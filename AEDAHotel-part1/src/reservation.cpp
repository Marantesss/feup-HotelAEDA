#include "reservation.h"

/***********************/
/** Reservation Class **/
/***********************/

Reservation::Reservation(Date date, Room *room, int duration) {
	this->date = date;
	this->room = room;
	this->duration = duration;
	this->price = duration * room->getPrice();
}

Date Reservation::getDate() const {
	return this->date;
}

Room *Reservation::getRoom() const {
	return this->room;
}

void Reservation::setDate(Date date) {
	this->date = date;
}

void Reservation::setRoom(Room *room) {
	this->room = room;
	this->price = this->duration * room->getPrice();
}

string Reservation::getInfo() const {
	stringstream ss;
	ss << "\nDate - " << date.getInfo() << endl;
	ss << "Room - " << room->getInfo() << endl;
	ss << "Price - " << price << " Euros" << endl;
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
