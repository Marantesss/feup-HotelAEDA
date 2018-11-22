#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <sstream>
#include "employee.h"
#include "AuxFunctions.h"

using namespace std;

/**
*  An abstract class used to represent a room.
*  Each room object has a room number, a room capacity and an assigned supervisor (further explanation on the Employee Class).
*/
class Room {
protected:
	int number;		/**< int number. The room's name. */
	int capacity;	/**< int capacity. The room's maximum capacity. */
	Employee supervisor;		/**< Employee supervisor. The room's assigned supervisor */
	double price;
public:
	/**
	* A default constructor.
	*/
	Room();

	/**
	* A constructor.
	* The constructor creates a Room object with the data passed as argument.
	* @param name The Rooms's number.
	* @param capacity The Rooms's number.
	*/
	Room(int number, int capacity);
	virtual ~Room() {};
	// get
	int getNumber() const;
	int getCapacity() const;
	int getFloorNumber() const;
	double getPrice() const;
	virtual string getInfo() const;
	//bool getisBedRoom() const;
	// set
	void setNumber(int number);
	void setCapacity(int capacity);
	void setSupervisor(Employee e);
	//operators
	bool operator== (int number);
	bool operator< (Room & room);
};


// MeetingRoom Class
class MeetingRoom : public Room {
	bool video;
	bool audio;
public:
	MeetingRoom(int number, int capacity, bool video, bool audio);
	MeetingRoom();
	// get
	bool getVideo() const;
	bool getAudio() const;
	string getInfo() const;
	// set
	void setVideo(bool video);
	void setAudio(bool audio);
	void setPricePerHour(double price);
	void setDefaultPrice();

};


// Bedroom Class
class Bedroom : public Room {
	string location;
public:
	Bedroom(int number, int capacity, string location);
	Bedroom();
	// get
	string getLocation() const;
	string getInfo() const;
	// set
	void setLocation(string location);
	void setPricePerDay(double price);
	void setDefaultPrice();
};


/**
*  A class used to represent an exception.
*  The exception object contains the invalid room.
*/
class NonExistingRoom {
	int number;	/**< int number. The NonExistingRoom's number. */
public:
	/**
	* A constructor.
	* The constructor creates a NonExistingRoom object with the supplied number.
	* @param An int, the number of the NonExistingRoom.
	*/
	NonExistingRoom(int num);

	/**
	* A const member function with no arguments to get the object's number.
	* @return An int, the number that originated the creation of this object.
	*/
	int getNumber() const;
};

#endif /* ROOM_H_ */
