#ifndef HOTEL_H_
#define HOTEL_H_

#include <fstream>
#include "reservation.h"
#include "client.h"
#include "room.h"
#include "client.h"
#include "employee.h"
#include "AuxFunctions.h"
#include "event.h"
#include "van.h"
#include "BST.h"
#include "restaurant.h"
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <stack>

/**
 * @defgroup hotel hotel
 * @{
 *
 *  Classes and Data Structures necessary to handle an hotel
 */

/**
 *  @brief A structure used to represent hash functions.
 */
struct clientPointerHash {
	/**
	 * @brief Hash function for Client*.
	 *
	 * @param Client c Pointer to a Client to be added to the hash table
	 *
	 * @return The added client's index in the hash table, which will be equal to its ID
	 */
	int operator() (const Client* c) const {
		return c->getId();
	}

	/**
	* @brief Comparison Function for Client*
	*
	* @param c1 Pointer to a Client object.
	* @param c2 Pointer to a Client object.
	*
	* @return true if Client c1 and c2 have the same ID
	*/
	bool operator() (const Client* c1, const Client* c2) const {
		return c1->getId() == c2->getId();
	}
};

/**
 * @brief Hash Table based on unordered_set
 */
typedef unordered_set<Client*, clientPointerHash, clientPointerHash> hashTabClientRecords;

/**
 *  @brief A class used to represent a hotel.
 *
 *  Each hotel object has a clients vector, a reservations vector, a rooms vector,
 *  an employees vector, the number of floors, the number of bedrooms,
 *  the number of meeting rooms and an address
 *
 *  @see Client Class
 *  @see Reservation Class
 *  @see Room Class
 *  @see Employee Class
 *  @see Event Class
 *  @see Van Class
 *  @see Restaurant Class
 */
class Hotel {
	/**
	 * @brief clients The hotel's checked-in clients
	 */
	vector<Client*> clientsCheckedIn;

	/**
	 * @brief clientRecords The hotel's clients' records
	 */
	hashTabClientRecords clientRecords;

	/**
	 * @brief reservations The hotel's reservations
	 */
	vector<Reservation> reservations;

	/**
	 * @brief rooms The hotel's rooms
	 */
	vector<Room*> rooms;

	/**
	 * @brief employees The hotel's employees
	 */
	vector<Employee> employees;

	/**
	 * @brief excursions The hotel's excursions
	 */
	priority_queue<Van> vans;
	
	/**
	* @brief events The hotel's events
	*/
	priority_queue<Event> events;

	/**
	 * @brief
	 */
	BST<Restaurant> restaurants;

	/**
	 * @brief floors The hotel's total number of floors
	 */
	int floors;

	/**
	 * @brief bedrooms The hotel's total number of bedrooms
	 */
	int bedrooms;

	/**
	 * @brief meetingRooms The hotel's total number of meeting rooms
	 */
	int meetingrooms;

	/**
	 * @brief trips The hotel's total number of done trips
	 */
	int trips;

	/**
	 * @brief address The hotel's address
	 */
	string address;
public:
	/**
	 * @brief Default Constructor.
	 */
	Hotel();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates an Hotel object with the data passed as argument.
	 *
	 * @param floors The hotel's total number of floors.
	 *
	 * @param address The hotel's address.
	 *
	 * @param trips ... TODO
	 */
	Hotel(int floors, string address, int trips = 0);

	/**
	 * @brief Default destructor.
	 */
	~Hotel();

	/**
	 * @brief Const member function to get the client's vector.
	 *
	 * @return The hotel's clients.
	 */
	vector<Client*> getClientsCheckedIn() const;

	/**
	 * @brief Const member function to get the clients' records Hash Table.
	 *
	 * @return The hotel's clients' records.
	 */
	hashTabClientRecords getClientRecords() const;

	/**
	 * @brief Member function to add a new client.
	 *
	 * @param c The hotel's new client.
	 */
	void checkInClient(Client *c);

	/**
	 * @brief Member function to add a new client.
	 *
	 * @param c The hotel's new client.
	 */
	void addClientRecord(Client *c);

	/**
	 * @brief Member function to get an existing client information.
	 *
	 * @param c The hotel's client.
	 */
	Client* getClientRecord(Client *c);

	/**
	 * @brief Member function to get an existing client information.
	 *
	 * @param name The hotel's client's name.
	 */
	Client* getClientRecord(string name);
	/**
	 * @brief Member function to remove a client.
	 *
	 * @param name The hotel's removed client's name.
	 */
	void checkoutClient(string name);

	/**
	 * @brief Member function to print all clients' information.
	 */
	void showClientsCheckedIn();


	/**
	 * @brief Member function to print all clients' information.
	 */
	void showClientRecords();

	/**
	 * @brief Member function to sort the vector clients.
	 */
	void sortClients();

	/**
	 * @brief Member function to get all the clients information.
	 *
	 * @param filename The file location containing all the
	 * clients and reservations information.
	 */
	void importClientsandReservations(string filename);

	/**
	 * @brief Function to search a specific client given its name.
	 *
	 * @param name The desired clients's name.
	 *
	 * @return The desired client's index in the vector,
	 * or -1 if not found
	 */
	int sequencialSearchClients(string name);

	/**
	 * @brief Function to search all Clients whose birthday is on date passed as argument.
	 *
	 * @param date The current date.
	 *
	 * @return Vector containing pointers to clients whose birthday is on date
	 */
	vector<Client*> checkBirthdays(Date date);

	/**
	 * @brief Const member function to get the room's vector.
	 *
	 * @return The hotel's rooms.
	 */
	vector<Room*> getRooms() const;

	/**
	 * @brief Member function to add a new room.
	 *
	 * @param r Pointer to the hotel's new room.
	 */
	void addRoom(Room *r);

	/**
	 * @brief Member function to remove a room.
	 *
	 * @param number The number of the hotel's removed room.
	 */
	void removeRoom(int num);

	/**
	 * @brief Const member function to sort the vector rooms.
	 */
	void sortRooms();

	/**
	 * @brief Const member function to get the room's vector from a specific floor.
	 *
	 * @param floor The hotel's floor.
	 *
	 * @return The hotel's rooms from a specific floor.
	 */
	vector<Room*> getFloorNumberRooms(int floor) const;

	/**
	 * @brief Member function to get all rooms information.
	 *
	 * @return String containing all room's information.
	 */
	string getRoomsInfo() const;

	/**
	 * @brief Member function to remove the rooms from a floor.
	 *
	 * @param floor The number of the floor of the hotel's removed rooms.
	 */
	void removeRoomsFromTopFloor();

	/**
	 * @brief Function to search a specific room given its number.
	 *
	 * @param num The room's number.
	 *
	 * @return The desired rooms's index in the vector,
	 * or -1 if not found
	 */
	int sequencialSearchRooms(int num);

	/**
	 * @brief Const member function to get the reservation's vector.
	 *
	 * @return The hotel's reservations.
	 */
	vector<Reservation> getReservations() const;

	/**
	 * @brief Member function to add a new reservation.
	 *
	 * @param R The hotel's new reservation.
	 */
	void addReservation(Reservation  R);

	/**
	 * @brief Const member function to sort the reservations rooms.
	 */
	void sortReservations();

	/**
	 * @brief Member function to remove a reservation.
	 *
	 * @param d The date of the hotel's removed reservation.
	 *
	 * @param R The room of the hotel's removed reservation.
	 */
	void removeReservation(Date d, Room * R);

	/**
	 * @brief Member function to remove all reservations with bedrooms belonging to the specified floor.
	 *
	 * @param R Pointer to the hotel's room
	 */
	void removeRoomReservations(Room * R);

	/**
	 * @brief Member function to remove all reservations with bedrooms belonging to the specified floor.
	 *
	 * @param floor The hotel's floor
	 */
	void removeFloorReservations(int floor);

	/**
	 * @brief Member function to print to the output buffer all the reservations information.
	 */
	void showReservations();

	/**
	 * @brief Const member function to get the employee's vector.
	 *
	 * @return The hotel's employees.
	 */
	vector<Employee> getEmployees() const;

	/**
	 * @brief Member function to add a new employee.
	 *
	 * @param E The hotel's new employee.
	 */
	void addEmployee(Employee E);

	/**
	 * @brief Member function to remove an employee.
	 *
	 * @param id The Id of the hotel's removed employee.
	 */
	void removeEmployee(int id);

	/**
	 * @brief Const member function to sort the employees rooms.
	 */
	void sortEmployees();

	/**
	 * @brief Member function to print all employees' information.
	 */
	void showEmployees();

	/**
	 * @brief Member function that equally distributes the supervisors over all the rooms.
	 */
	void allocateEmployees();

	/**
	 * @brief Member function to get the number of supervisors.
	 *
	 * @return The number of employees who are supervisors.
	 */
	int getNoSupervisors();

	/**
	 * @brief Member function to get all the employees information.
	 *
	 * @param filename The file location containing all the employees information.
	 */
	void importEmployees(string filename);

	/**
	 * @brief Function to search a specific employee given its id.
	 *
	 * @param id The desired employee's id.
	 *
	 * @return The desired employee's index in the vector,
	 * or -1 if not found
	 */
	int sequencialSearchEmployees(int id);

	/**
	 * @brief Member function to add a group to a van.
	 *
	 * @param group The group to be added to a hotel's van.
	 */
	void addGroup(vector<Client*>& group);

	/**
	 * @brief Const member function to get the vans's priority queue.
	 *
	 * @return The hotel's vans.
	 */
	priority_queue<Van> getVans() const;

	/**
	 * @brief Const member function to get the hotel's finished trips.
	 *
	 * @return The hotel's finished trips.
	 */
	unsigned getTrips() const;

	/**
	 * @brief Member function to end a van's trip.
	 *
	 * This function removes a van with the given id and adds 1 to the hotel's finished trips
	 *
	 * @param id The id of the van to be removed from the hotel's vans.
	 */
	void tripDone(int id);

	/**
	 * @brief Member function to cancel a van's trip.
	 *
	 * @param id The id of the van to be removed from the hotel's vans.
	 */
	void removeVan(int id);

	/**
	 * @brief Member function to print all vans information.
	 */
	void showVans();

	/**
	 * @brief Member function to add a new van.
	 *
	 * @param V The hotel's new van.
	 */
	void addVan(Van V);

	/**
	 * @brief Member function to get all the vans information from a file.
	 *
	 * @param filename The file location containing all the vans information.
	 */
	void importVans(string filename);

	/**
	 * @brief Const member function to get the hotel's events.
	 *
	 * @return The hotel's events.
	 */
	priority_queue<Event> getEvents() const;

	/**
	 * @brief Member function to add a new event.
	 *
	 * @param Ev The hotel's new event.
	 */
	void addEvent(Event Ev);

	/**
	 * @brief Member function to remove the earliest event.
	 */
	void removeEvent();

	/**
	 * @brief Member function to remove event before date.
	 *
	 * @param date The current.
	 */
	void updateEvents(Date date);

	/**
	 * @brief Member function to get all the event's information.
	 *
	 * @return string All hotel's event's informations
	 */
	string getEventsInfo();

	/**
	 * @brief Const member function to get the total number of the hotel's floors.
	 *
	 * @return The total number of the hotel's floors.
	 */
	int getFloors() const;

	/**
	 * @brief Member function to add a new floor.
	 */
	void addFloor();

	/**
	 * @brief Member function to remove a floor.
	 */
	void removeFloor();

	/**
	 * @brief Const member function to get the total number of the hotel's bedrooms.
	 *
	 * @return The total number of hotel's bedrooms.
	 */
	int getBedrooms() const;

	/**
	 * @brief Const member function to get the total number of the hotel's meeting rooms.
	 *
	 * @return The total number of hotel's meeting rooms.
	 */
	int getMeetingRooms() const;


	/**
	 * @brief Const member function to get the hotel's address.
	 *
	 * @return The hotel's address.
	 */
	string getAddress() const;

	/**
	 * @brief Member function to change the hotel's address.
	 *
	 * @param address The hotel's new address.
	 */
	void setAddress(string address);

	int addRestaurant(Restaurant r);

	int addRestaurant(string name, string type, int distance);
	
	vector<Restaurant> addRestaurants(vector<Restaurant> res);

	Restaurant searchRestaurant(string name);

	BST<Restaurant> getRestaurants();

	int removeRestaurant(string name);

	Restaurant getClosestRestaurant();

	vector<Restaurant> getRestaurantsOfType(string type);

	void importRestaurants(string filename);

	int getNoRestaurants();

	string getRestaurantsInfo();

	string getTypesOfRestaurants();

};

/**@}*/

#endif /* HOTEL_H_ */
