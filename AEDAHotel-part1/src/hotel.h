#ifndef HOTEL_H_
#define HOTEL_H_

#include <fstream>
#include "reservation.h"
#include "client.h"
#include "room.h"
#include "client.h"
#include "employee.h"
#include "AuxFunctions.h"
#include <typeinfo>       // std::bad_cast


/**
 *  A class used to represent a hotel.
 *
 *  Each hotel object has a clients vector, a reservations vector, a rooms vector,
 *  an employees vector, the number of floors, the number of bedrooms,
 *  the number of meeting rooms and an address
 *
 *  @see Client Class
 *  @see Reservation Class
 *  @see Room Class
 *  @see Employee Class
 */
class Hotel {
	/**
	 * vector<Client> clients The hotel's clients
	 */
	vector<Client> clients;

	/**
	 *  vector<Reservation> reservations The hotel's reservations
	 */
	vector<Reservation> reservations;

	/**
	 * vector<Room> rooms The hotel's rooms
	 */
	vector<Room> rooms;

	/**
	 * vector<Employee> employees The hotel's employees
	 */
	vector<Employee> employees;

	/**
	 * int floors The hotel's total number of floors
	 */
	int floors;

	/**
	 * int bedrooms The hotel's total number of bedrooms
	 */
	int bedrooms;

	/**
	 * int meetingRooms The hotel's total number of meeting rooms
	 */
	int meetingrooms;

	/**
	 * string address The hotel's address
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
	 */
	Hotel(int floors, string address);

	/**
	 * @brief Default destructor.
	 */
	~Hotel();

	/**
	 * @brief Const member function to get the client's vector.
	 *
	 * @return The hotel's clients.
	 */
	vector<Client> getClients() const;

	/**
	 * @brief Member function to add a new client.
	 *
	 * @param c The hotel's new client.
	 */
	void addClient(Client c);

	/**
	 * @brief Member function to remove a client.
	 *
	 * @param name The hotel's removed client's name.
	 */
	void removeClient(string name);

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
	 * @param vec Vector containing all the clients.
	 *
	 * @param name The desired clients's name.
	 *
	 * @return The desired client's index in the vector,
	 * or -1 if not found
	 */
	int sequencialSearchClients(string name);

	/**
	 * @brief Const member function to get the room's vector.
	 *
	 * @return The hotel's rooms.
	 */
	vector<Room> getRooms() const;

	/**
	 * @brief Member function to add a new room.
	 *
	 * @param r The hotel's new room.
	 */
	void addRoom(Room & r);

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
	vector<Room> getFloorNumberRooms(int floor) const;

	/**
	 * @brief Member function to get the floor's information.
	 *
	 * The return string will contain the floor's number
	 * followed by newline and a list containing all the rooms number
	 *
	 * @return The floor's rooms number.
	 */
	string getRoomsInfo();

	/**
	 * @brief Member function to remove the rooms from a floor.
	 *
	 * @param floor The number of the floor of the hotel's removed rooms.
	 */
	void removeRoomsFromTopFloor();

	/**
	 * @brief Member function to print all rooms' information.
	 */
	void showRooms();

	/**
	 * @brief Function to search a specific room given its number.
	 *
	 * @param vec Vector containing all the rooms.
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
	 * @param vec Vector containing all the employees.
	 *
	 * @param id The desired employee's id.
	 *
	 * @return The desired employee's index in the vector,
	 * or -1 if not found
	 */
	int sequencialSearchEmployees(int id);

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
};

#endif /* HOTEL_H_ */
