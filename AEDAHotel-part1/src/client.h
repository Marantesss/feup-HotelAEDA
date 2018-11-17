#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "reservation.h"

using namespace std;

// Client Class
class Client {
	string name;
	vector<Reservation> reservations;
public:
	Client(string name);	// constructor
	~Client();				// destructor
	string getName() const;
	vector<Reservation> getReservations() const;
	void setName(string name);
	void addReservation(Reservation reservation);
	bool operator < (Client & c2);
	string getInfo() const;
};

// NonExistingClient exception
class NonExistingClient {
	string name;
public:
	NonExistingClient(string nm);
	string getName() const;
};


#endif /* CLIENT_H_ */
