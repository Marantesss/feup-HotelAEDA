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
 *
 *  Each client object has a name and a reservations vector
 *
 *  @see Reservation Class
 */
class Client {
	/**
	 * int id The clients's id
	 */
	int id;

	/**
	 * string name The client's name
	 */
	string name;

	/**
	 * Date birthday The client's birthday
	 */
	Date birthday;

	/**
	 * vector<Reservation*> reservations The client's hotel reservations.
	 */
	vector<Reservation*> reservations;

	/**
	 * static int nextId The next client's id.
	 */
	static int nextId;

public:
	/**
	 * @brief Default constructor.
	 */
	Client();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a Client object with the data passed as argument.
	 *
	 * @param name The client's name.
	 */
	Client(string name, Date birthday);

	/**
	 * @brief Default destructor.
	 */
	~Client();

	/**
	 * @brief Const member function to get the client's name.
	 *
	 * @return The client's name.
	 */
	string getName() const;

	/**
	 * @brief Member function to change the client's name.
	 *
	 * @param name The client's new name.
	 */
	void setName(string name);

	/**
	 * @brief Const member function to get the client's id.
	 *
	 * @return The client's id.
	 */
	int getId() const;

	/**
	 * @brief Const member function to get the client's information.
	 *
	 * The return string will contain the client's name
	 * followed by newline and a list containing all the reservations made
	 *
	 * @return The client's name and reservations.
	 */
	string getInfo() const;

	/**
	 * @brief Member function to add a new reservation.
	 *
	 * All the reservations are pointers to the reservations vector
	 * in the hotel class
	 *
	 * @param R Pointer to client's new reservation.
	 */
	void addReservation(Reservation * R);

	/**
	 * @brief Member function to get clients reservations.
	 *
	 * All the reservations are pointers to the reservations vector
	 * in the hotel class
	 *
	 * @return Vector of pointers to client's reservations.
	 */
	vector<Reservation*> getReservation() const;

	/**
	 * @brief Overload of Operator < for class Client.
	 *
	 * @param c2 The other client to be compared to.
	 *
	 * @return true, if the first client's name comes first in alphabetical order
	 * 	       false, if otherwise
	 */
	bool operator < (Client & c2);

	/**
	 * @brief Overload of Operator == for class Client.
	 *
	 * @param name The other client's name to be compared to.
	 *
	 * @return true, if the Clients name is the same as the parameter
	 * 		  false, if otherwise
	 */
	bool operator == (Client c);
};

/**
 *  A class used to represent an exception.
 *
 *  The exception object contains the invalid client.
 */
class NonExistingClient {
	/**
	 * string name The NonExistingClient's name.
	 */
	string name;
public:
	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a NonExistingClient object with the supplied name.
	 *
	 * @param The name of the NonExistingClient.
	 */
	NonExistingClient(string nm);

	/**
	 * @brief Const member function to get the object's name.
	 *
	 * @return The name that originated the creation of this object.
	 */
	string getName() const;
};

#endif /* CLIENT_H_ */
