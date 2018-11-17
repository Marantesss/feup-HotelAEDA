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
	virtual int getPrice() const;
	// set
	void setNumber(int number);
	void setCapacity(int capacity);
	void setSupervisor(Supervisor *s);
	virtual string getInfo() const;
};


// MeetingRoom Class
class MeetingRoom: public Room {
	bool video;
	bool audio;
	int price; //per hour
public:
	MeetingRoom(int number, int capacity, bool video, bool audio);
	// get
	bool getVideo() const;
	bool getAudio() const;
	int getPrice() const;
	// set
	void setVideo(bool video);
	void setAudio(bool audio);
	void setPricePerHour(int price);

	string getInfo() const;
};


// Bedroom Class
class Bedroom: public Room {
	string location;
	int price; //per day
public:
	Bedroom(int number, int capacity, string location);
	// get
	string getLocation() const;
	int getPrice() const;
	// set
	void setLocation(string location);
	void setPrice(int price);
	string getInfo() const;
};


// NonExistingRoom exception
class NonExistingRoom {
	int number;
public:
	NonExistingRoom(int num);
	int getNumber() const;
};

#endif /* ROOM_H_ */
