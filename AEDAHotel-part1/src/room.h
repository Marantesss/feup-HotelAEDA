#ifndef ROOM_H_
#define ROOM_H_

#include <string>

using namespace std;

// Room Class
class Room {
protected:
	int number;
	int capacity;
public:
	Room(int number, int capacity);
	~Room();
	// get
	int getNumber() const;
	int getCapacity() const;
	// set
	void setNumber(int number);
	void setCapacity(int capacity);
};


// MeetingRoom Class
class MeetingRoom: public Room {
protected:
	bool video;
	bool audio;
	int price;
public:
	MeetingRoom(int number, int capacity, bool video, bool audio);
	~MeetingRoom();
	// get
	bool getVideo() const;
	bool getAudio() const;
	int getPrice() const;
	// set
	void setVideo(bool video);
	void setAudio(bool audio);
	void setPrice(int price);
};


// Bedroom Class
class Bedroom: public Room {
protected:
	string location;
	int price;
public:
	Bedroom(int number, int capacity, string location);
	~Bedroom();
	// get
	string getLocation() const;
	int getPrice() const;
	// set
	void setLocation(string location);
	void setPrice(int price);
};


// NonExistingRoom exception
class NonExistingRoom {
	int number;
public:
	NonExistingRoom(int num);
	int getNumber() const;
};

#endif /* ROOM_H_ */
