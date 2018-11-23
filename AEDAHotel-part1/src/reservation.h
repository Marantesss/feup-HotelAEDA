#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <sstream>
#include <vector>
#include <typeinfo>
#include "date.h"
#include "room.h"

// Reservation Class
/**
 *  An abstract class used to represent a reservation.
 *
 *  Each reservation object has a date, a room, a duration and a price.
 *
 *  @see Date Class
 *
 *  @see Room Class
 */
class Reservation {

	/**
	 * Date date The reservation's date
	 */
	Date date;

	/**
	 * Room* room The reservation's room
	 */
	Room* room;

	/**
	 * int duration The reservation's duration
	 */
	int duration; // In days for Bedrooms and in hours for the Meeting Rooms

	/**
	 * double price The reservation's price
	 */
	double price;

public:
	/**
	 * @brief Default constructor.
	 */
	Reservation();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a Reservation object with the data passed as argument.
	 *
	 * @param date The Reservation's date.
	 *
	 * @param room The Reservation's room.
	 *
	 * @param duration The Reservation's duration.
	 */
	Reservation(Date date, Room *room, int duration);

	/**
	 * @brief Default destructor.
	 */
	~Reservation() {};

	/**
	 * @brief Const member function to get the reservation's date.
	 *
	 * @return The reservation's date.
	 */
	Date getDate() const;

	/**
	 * @brief Const member function to get the reservation's room.
	 *
	 * @return The reservation's room.
	 */
	Room* getRoom() const;
	
	int getDuration() const;
	double getPrice() const;

	/**
	 * @brief Const member function to get the reservation's information.
	 *
	 * @return The reservation's information.
	 */
	string getInfo() const;

	/**
	 * @brief Member function to change the reservation's date.
	 *
	 * @param date The reservation's new date.
	 */
	void setDate(Date date);

	/**
	 * @brief Member function to change the reservation's room.
	 *
	 * @param room The reservation's new room.
	 */
	void setRoom(Room *room);

	/**
	 * @brief Member function to change the reservation's price.
	 *
	 * @param duration The reservation's duration.
	 *
	 * @param droom The reservation's room.
	 */
	void setPrice(int duration, Room *room);

	/**
 	 * @brief Member function to change the reservation's duration.
	 *
	 * @param duration The reservation's new duration.
	 */
	void setDuration(int duration);
	// Operators
	bool operator <(Reservation & r) const;
	Reservation operator =(Reservation &r);
};

// NonExistingReservation exception
/**
 *  A class used to represent an exception.
 *
 *  The exception object contains the invalid reservation.
 */
class NonExistingReservation {

protected:
	/**
	 * Date date The NonExistingReservation's date.
	 */
	Date date;

	/**
	 *  Room* room The NonExistingReservation's room.
	 */
	Room* room;

public:
	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a NonExistingReservation object with the supplied date and room.
	 *
	 * @param date The date of the NonExistingReservation.
	 *
	 * @param room The room of the NonExistingReservation.
	 */
	NonExistingReservation(Date date, Room *room);

	/**
	 * @brief Const member function with no arguments to get the object's date.
	 *
	 * @return The date that originated the creation of this object.
	 */
	Date getDate() const;

	/**
	 * @brief Const member function with no arguments to get the object's room.
	 *
	 * @return The room that originated the creation of this object.
	 */
	Room *getRoom() const;
};

#endif /* RESERVATION_H_ */
