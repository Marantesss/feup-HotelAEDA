#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <sstream>
#include <vector>
#include "date.h"
#include "room.h"

// Reservation Class
class Reservation {
	Date date;
	Room room;
public:
	Reservation(Date date, Room room);
	~Reservation() {};
	// get
	Date getDate() const;
	Room getRoom() const;
	// set
	void setDate(Date date);
	void setRoom(Room room);
	
	string getInfo();
};

// InvalidReservation exception
class InvalidReservation {
protected:
	Date date;
	Room room;
public:
	InvalidReservation(Date date, Room room);
	Date getDate() const;
	Room getRoom() const;
};


#endif /* RESERVATION_H_ */
