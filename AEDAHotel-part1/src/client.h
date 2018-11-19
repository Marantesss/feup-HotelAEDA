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
	vector<Reservation*> reservations;
public:
	Client(string name);	// constructor
	~Client();				// destructor
	string getName() const;
	void setName(string name);
	string getInfo() const;
	void addReservation(Reservation * R);
	//operators
	bool operator < (Client & c2);
	bool operator == (string name);
};

// NonExistingClient exception
class NonExistingClient {
	string name;
public:
	NonExistingClient(string nm);
	string getName() const;
};


#endif /* CLIENT_H_ */
