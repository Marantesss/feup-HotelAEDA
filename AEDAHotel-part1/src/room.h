#ifndef ROOM_H_
#define ROOM_H_

#include <string>
#include <sstream>
#include "employee.h"

using namespace std;

/**
*  An abstract class used to represent a room.
*
*  Each room object has a room number, a room capacity and an assigned supervisor.
*
*  @see Employee Class
*/
class Room {
protected:
	/**
	* int number The room's name
	*/
	int number;	

	/**
	*  int capacity The room's maximum capacity
	*/
	int capacity;

	/**
	* Employee supervisor The room's assigned supervisor
	*/
	Employee supervisor;
public:
	/**
	* @brief Default constructor.
	*/
	Room();

	/**
	* @brief Constructor.
	*
	* The constructor creates a Room object with the data passed as argument.
	*
	* @param name The Rooms's number.
	*
	* @param capacity The Rooms's capacity.
	*/
	Room(int number, int capacity);

	/**
	* @brief Default destructor.
	*/
	virtual ~Room() {};

	// get
	/**
	* @brief Const member function to get the rooms's number.
	*
	* @return The room's number.
	*/
	int getNumber() const;

	/**
	* @brief Const member function to get the rooms's capacity.
	*
	* @return The room's capacity.
	*/
	int getCapacity() const;

	/**
	* @brief Const member function to get the rooms's floor number.
	*
	* @return The room's floor number.
	*/
	int getFloorNumber() const;
	virtual double getPrice() const;
	virtual string getInfo() const;

	// set
	/**
	* @brief Member function to change the room's number.
	*
	* @param number The room's new number.
	*/
	void setNumber(int number);

	/**
	* @brief Member function to change the room's capacity.
	*
	* @param capacity The room's new capacity.
	*/
	void setCapacity(int capacity);

	/**
	* @brief Member function to change the room's employee.
	*
	* @param e The room's new employee.
	*/
	void setSupervisor(Employee e);

	//operators
	/**
	* @brief Overload of Operator == for class Room.
	*
	* @param number The number to be compared to.
	*
	* @return true, if the room's number is equal to the parameter number
	*		  false, if otherwise
	*/
	bool operator== (int number);

	/**
	* @brief Overload of Operator < for class Room.
	*
	* @param room The other room to be compared to.
	*
	* @return true, if the first room's number is is lower
	*		  false, if otherwise
	*/
	bool operator< (Room & room);
};


// MeetingRoom Class
/**
*  A subclass of the Room class to represent meeting rooms
*
*  Each meeting room has the possibility of having video, audio
*
*  Each meeting room has a price
*/
class MeetingRoom: public Room {

	/**
	* bool video The existance of video in the meeting room
	*/
	bool video;

	/**
	* bool audio The existance of audio in the meeting room
	*/
	bool audio;

	/**
	*  double price The meeting room's price per hour
	*/
	double price;

public:
	/**
	* @brief Constructor.
	*
	* The constructor creates a meeting room object with the data passed as argument.
	*
	* @param number The meeting room's number.
	*
	* @param capacity The meeting room's capacity.
	*
	* @param video The existance of video in the meeting room.
	*
	* @param audio The existance of audio in the meeting room.
	*/
	MeetingRoom(int number, int capacity, bool video, bool audio);

	// get
	/**
	* @brief Const member function to get the meeting room's existance of video.
	*
	* @return true if the meeting room has video
	*		  false, if otherwise
	*/
	bool getVideo() const;

	/**
	* @brief Const member function to get the meeting room's existance of audio.
	*
	* @return true if the meeting room has audio
	*		  false, if otherwise
	*/
	bool getAudio() const;

	/**
	* @brief Const member function to get the meeting room's price.
	*
	* @return The meeting room's price.
	*/
	double getPrice() const;

	/**
	* @brief Const member function to get the meeting room's info.
	*
	* @return a string with the meeting room's info, and the video, audio and price
	*/
	string getInfo() const;

	// set
	/**
	* @brief Member function to change the meeting room's existance of video.
	*
	* @param video The meeting room's new existance of video.
	*/
	void setVideo(bool video);

	/**
	* @brief Member function to change the meeting room's existance of audio.
	*
	* @param video The meeting room's new existance of audio.
	*/
	void setAudio(bool audio);

	/**
	* @brief Member function to change the meeting room's price.
	*
	* @param price The meeting room's new price.
	*/
	void setPricePerHour(double price);

};


// Bedroom Class
/**
*  A subclass of the Room class to represent bedrooms
*
*  Each bedroom has a location and a price
*/
class Bedroom: public Room {

	/**
	*  string location The bedroom's location
	*/
	string location;

	/**
	*  double price The bedroom's price
	*/
	double price;

public:
	/**
	* @brief Constructor.
	*
	* The constructor creates a bedroom object with the data passed as argument.
	*
	* @param number The bedroom's number.
	*
	* @param capacity The bedroom's capacity.
	*
	* @param video The bedroom's location.
	*/
	Bedroom(int number, int capacity, string location);

	// get
	/**
	* @brief Const member function to get the bedroom's location.
	*
	* @return The bedroom's location.
	*/
	string getLocation() const;

	/**
	* @brief Const member function to get the bedroom's price.
	*
	* @return The bedroom's price.
	*/
	double getPrice() const;

	/**
	* @brief Const member function to get the bedroom's info.
	*
	* @return a string with the bedroom's info, and the location and price
	*/
	string getInfo() const;

	// set
	/**
	* @brief Member function to change the bedroom's location.
	*
	* @param location The bedroom's new location.
	*/
	void setLocation(string location);

	/**
	* @brief Member function to change the bedroom's price.
	*
	* @param price The bedroom's new price.
	*/
	void setPrice(double price);
};


/**
*  A class used to represent an exception.
*
*  The exception object contains the invalid room.
*/
class NonExistingRoom {
	/**
	* int number The NonExistingRoom's number
	*/
	int number;

public:
	/**
	* @brief Constructor.
	*
	* The constructor creates a NonExistingRoom object with the supplied number.
	*
	* @param num The number of the NonExistingRoom.
	*/
	NonExistingRoom(int num);

	/**
	* @brief Const member function to get the object's number.
	*
	* @return The number that originated the creation of this object.
	*/
	int getNumber() const;
};

#endif /* ROOM_H_ */
