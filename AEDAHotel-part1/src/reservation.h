#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <sstream>
#include <vector>
#include <typeinfo>
#include "date.h"
#include "room.h"

// Reservation Class
class Reservation {
	Date date;
	Room* room;
	int duration; // In days for Bedrooms and in hours for the Meeting Rooms
	double price;
public:
	Reservation();
	Reservation(Date date, Room *room, int duration);
	~Reservation() {};
	// get
	Date getDate() const;
	Room* getRoom() const;
	int getDuration() const;
	double getPrice() const;
	string getInfo() const;
	// set
	void setDate(Date date);
	void setRoom(Room *room);
	void setPrice(int duration, Room *room);
	void setDuration(int duration);
	// Operators
	bool operator <(Reservation & r) const;
	Reservation operator =(Reservation &r);
};

// NonExistingReservation exception
class NonExistingReservation {
protected:
	Date date;
	Room* room;
public:
	NonExistingReservation(Date date, Room *room);
	Date getDate() const;
	Room *getRoom() const;
};

#endif /* RESERVATION_H_ */
