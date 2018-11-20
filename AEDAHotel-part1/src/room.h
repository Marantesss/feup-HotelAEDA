#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <sstream>
#include "employee.h"

using namespace std;

// Room Class
class Room {
protected:
	int number;
	int capacity;
	Supervisor *supervisor;
public:
	Room(int number, int capacity);
	Room();
	virtual ~Room() {};
	// get
	int getNumber() const;
	int getCapacity() const;
	int getFloorNumber() const;
	virtual double getPrice() const;
	virtual string getInfo() const;
	// set
	void setNumber(int number);
	void setCapacity(int capacity);
	void setSupervisor(Supervisor *s);
	//operators
	bool operator== (int number);
	bool operator< (Room & room);
};


// MeetingRoom Class
class MeetingRoom: public Room {
	bool video;
	bool audio;
	double price; //per hour
public:
	MeetingRoom(int number, int capacity, bool video, bool audio);
	// get
	bool getVideo() const;
	bool getAudio() const;
	double getPrice() const;
	string getInfo() const;
	// set
	void setVideo(bool video);
	void setAudio(bool audio);
	void setPricePerHour(double price);

};


// Bedroom Class
class Bedroom: public Room {
	string location;
	double price; //per day
public:
	Bedroom(int number, int capacity, string location);
	// get
	string getLocation() const;
	double getPrice() const;
	string getInfo() const;
	// set
	void setLocation(string location);
	void setPrice(double price);
};


// NonExistingRoom exception
class NonExistingRoom {
	int number;
public:
	NonExistingRoom(int num);
	int getNumber() const;
};

#endif /* ROOM_H_ */
