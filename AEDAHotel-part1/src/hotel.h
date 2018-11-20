#ifndef HOTEL_H_
#define HOTEL_H_

#include "reservation.h"
#include "client.h"
#include "room.h"
#include "client.h"
#include "employee.h"
#include "AuxFunctions.h"

class Hotel {
	vector<Client*> clients;
	vector<Reservation*> reservations;
	vector<Room*> rooms;
	vector<Employee*> employees;
	int floors;
	int bedrooms;
	int meetingRooms;
	string address;
public:
	Hotel(int floors, int bedrooms, int meetingRooms, string address);
	~Hotel();
	// Clients
	vector<Client*> getClients() const;
	void sortClients();
	void addClient(Client * c);
	int removeClient(string name);
	// Rooms
	vector<Room*> getRooms() const;
	vector<Room*> getFloorNumberRooms(int floor) const;
	string getRoomsInfo();
	void addRoom(Room * r);
	void removeRoom(int number);
	void removeRoomsFromFloor(int floor);
	// Reservations
	vector<Reservation*> getReservations() const;
	void addReservation(Reservation * R);
	void removeReservation(Date *d, Room *R);
	// Employees
	vector<Employee*> getEmployees() const;
	void addEmployee(Employee * E);
	void removeEmployee(string name);
	// Building Information
	// Floors
	int getFloors() const;
	void addFloor();
	void removeFloor();
	// Bedrooms
	int getBedrooms() const;
	void addBedroom();
	void removeBedroom();
	// MeetingRooms
	int getMeetingRooms() const;
	void addMeetingRoom();
	void removeMeetingRoom();
	// Address
	string getAddress() const;
	void setAddress(string address);
};

#endif /* HOTEL_H_ */
