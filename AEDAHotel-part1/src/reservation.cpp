#include "reservation.h"

/***********************/
/** Reservation Class **/
/***********************/

Reservation::Reservation() {
	this->date = 0;
	this->room = 0;
	this->duration = 0;
	this->price = 0;
}

Reservation::Reservation(Date date, Room *room, int duration) {
	this->date = date;
	this->room = room;
	this->duration = duration;
	this->price = duration * room->getPrice();
	// Date influences time
	if (date.getSeason() == "Summer" || date.getSeason() == "Winter") {
		price = price * 1.1;
	}
}

Date Reservation::getDate() const {
	return this->date;
}

Room *Reservation::getRoom() const {
	return this->room;
}

void Reservation::setPrice(int duration, Room *room) {
	this->price = duration * room->getPrice();
}

void Reservation::setDate(Date date) {
	this->date = date;
}

void Reservation::setRoom(Room *room) {
	this->room = room;
	this->price = this->duration * room->getPrice();
}

void Reservation::setDuration(int duration) {
	this->duration = duration;
}

string Reservation::getInfo() const {
	stringstream ss;
	ss << "\nDate - " << date.getInfo() << endl;
	//ss << "Room - " << room.getInfo() << endl;
	ss << "Price - " << price << " Euros" << endl;
	return ss.str();
}

/**********************************/
/** InvalidReservation exception **/
/**********************************/

NonExistingReservation::NonExistingReservation(Date date, Room *room) {
	this->date = date;
	this->room = room;
}

Date NonExistingReservation::getDate() const {
	return this->date;
}

Room *NonExistingReservation::getRoom() const {
	return this->room;
}
