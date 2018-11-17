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
public:
	Hotel();
	~Hotel();
	vector<Client*> getClients() const;
	vector<Reservation*> getReservations() const;
	vector<Room*> getRooms() const;
	//void sortClients(); 
	void addClient(Client * c);
	int removeClient(string name);
	void addRoom(Room * r);
	int removeRoom(int number);
	void addReservation(Reservation * R);
	//void removeReservation(Date d, Room R);
};

#endif /* HOTEL_H_ */