#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "reservation.h"

using namespace std;

/**
*  A class used to represent a client.
*  Each client object has a name and a reservations vector (further explanation on the Reservation Class).
*/
class Client {
	string name;	/**< string name. The client's name. */
	vector<Reservation*> reservations;	/**< vector<Reservation> reservations. The client's hotel reservations. */
public:
	/**
	* A default constructor.
	*/
	Client();

	/**
	* A constructor.
	* The constructor creates a Client object with the data passed as argument.
	* @param name The client's name.
	*/
	Client(string name);

	/**
	* A default destructor.
	*/
	~Client();

	/**
	* A const member function with no arguments to get the client's name.
	* @return A string, the client's name.
	*/
	string getName() const;

	/**
	* A member function with no return value to change the client's name.
	* @param name The client's new name.
	*/
	void setName(string name);

	/**
	* A const member function with no arguments to get the client's information.
	* @return A string, the client's name and reservations.
	*/
	string getInfo() const;

	/**
	* A member function with no return value to add a new reservation.
	* @param R The client's new reservation.
	*/
	void addReservation(Reservation * R);

	/**
	* Overload of Operator < for class Client.
	* @param c2 The other client to be compared to.
	* @return true, if the first client's name comes first in alphabetical order
	* 		  false, if otherwise
	*/
	bool operator < (Client & c2);

	/**
	* Overload of Operator == for class Client.
	* @param c2 The other client to be compared to.
	* @return true, if both the clients' name is the same
	* 		  false, if otherwise
	*/
	bool operator == (Client & c2);
};

/**
*  A class used to represent an exception.
*  The exception object contains the invalid client.
*/
class NonExistingClient {
	string name;	/**< string name. The NonExistingClient's name. */
public:
	/**
	* A constructor.
	* The constructor creates a NonExistingClient object with the supplied name.
	* @param A string, the name of the NonExistingClient.
	*/
	NonExistingClient(string nm);

	/**
	* A const member function with no arguments to get the object's name.
	* @return A string, the name that originated the creation of this object.
	*/
	string getName() const;
};


#endif /* CLIENT_H_ */
