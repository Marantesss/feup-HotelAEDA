#include "reservation.h"

/***********************/
/** Reservation Class **/
/***********************/

Reservation::Reservation() {
	this->date = Date(1,1,2018);
	this->room = 0;
	this->duration = 0;
	this->price = 0;
}

Reservation::Reservation(Date date, Room *room, int duration) {
	this->date = date;
	this->room = room;
	this->duration = duration;
	this->price = 0;
	// If the room is a bedroom
	if(room->getIsBedroom()) {
		for (int i = 0; i < duration; i++) {
			// high season
			if (date.getSeason() == "Summer" || date.getSeason() == "Winter") {
				// weekend
				if (date.getWeekday() == "Saturday" || date.getWeekday() == "Sunday")
					price += room->getPrice() * 1.2;
				// weekday
				else
					price += room->getPrice() * 1.1;
			}
			// off-season
			else {
				// weekend
				if (date.getWeekday() == "Saturday" || date.getWeekday() == "Sunday")
					price += room->getPrice() * 1.1;
				//weekday
				else
					price += room->getPrice();
			}
			date++;
		}
		// getting date back to normal
		for (int i = 0; i < duration; i++)
			date--;
	}
	// If the room is a MeetingRoom
	else if(!room->getIsBedroom()) {
		// high season
		if (date.getSeason() == "Summer" || date.getSeason() == "Winter") {
			// weekend
			if (date.getWeekday() == "Saturday" || date.getWeekday() == "Sunday")
				price += room->getPrice() * 1.2 * duration;
			// weekday
			else
				price += room->getPrice() * 1.1 * duration;
		}
		// off-season
		else {
			// weekend
			if (date.getWeekday() == "Saturday" || date.getWeekday() == "Sunday")
				price += room->getPrice() * 1.1 * duration;
			// weekday
			else
				price += room->getPrice() * duration;
		}
	}
}

Date Reservation::getDate() const {
	return this->date;
}

Room *Reservation::getRoom() const {
	return this->room;
}

int Reservation::getDuration() const {
	return this->duration;
}

double Reservation::getPrice() const {
	return this->price;
}

string Reservation::getInfo() const {
	stringstream ss;

	ss << "Date: " << date.getInfo() << endl;
	ss << "Room: " << room->getInfo() << endl;
	ss << "Duration: " << duration << endl;
	ss << "Total price: " << price << " Euros";
	return ss.str();
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

bool Reservation::operator <(const Reservation & r) const {
	if (this->getDate() < r.getDate())
		return true;
	else
		return false;
}

Reservation Reservation::operator =(const Reservation & r) {
	this->date = r.getDate();
	this->room = r.getRoom();
	this->duration = r.getDuration();
	this->price = r.getPrice();
	return *this;
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
