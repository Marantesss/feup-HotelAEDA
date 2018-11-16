#ifndef HOTEL_H_
#define HOTEL_H_

#include "reservation.h"
#include "client.h"
#include "room.h"
#include "client.h"
#include "employee.h"

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
	void sortClients(); 
	void addClient(Client & c); 
};

template <class T>
void insertionSort(vector<T> &v) {
	for (size_t i = 1; i < v.size(); i++)
	{
		T tmp = v[i];
		size_t j;
		for (j = i; j > 0 && tmp < v[j - 1]; j--) {
			v[j] = v[j - 1];
		}
		v[j] = tmp;	
	}
}

#endif /* HOTEL_H_ */