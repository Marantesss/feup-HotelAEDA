#ifndef HOTEL_H_
#define HOTEL_H_

#include "reservation.h"
#include "client.h"
#include "room.h"

class Hotel {
	vector<Client> clients;
	vector<Reservation> reservations;
	vector<Room> rooms;
public:
	Hotel();
	~Hotel();
	vector<Client> getClients() const;
	vector<Reservation> getReservations() const;
	vector<Room> getRooms() const;

};

#endif /* HOTEL_H_ */
