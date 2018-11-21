#ifndef HOTEL_H_
#define HOTEL_H_

#include "reservation.h"
#include "client.h"
#include "room.h"
#include "client.h"
#include "employee.h"
#include "AuxFunctions.h"

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
	int meetingRooms;

	/**
	* string address The hotel's address
	*/
	string address;
public:
	/**
	* @brief Constructor.
	*
	* The constructor creates an Hotel object with the data passed as argument.
	*
	* @param floors The hotel's total number of floors.
	*
	* @param bedrooms The hotel's total number of bedrooms.
	*
	* @param meetingRooms The hotel's total number of meeting rooms.
	*
	* @param address The hotel's address.
	*/
	Hotel(int floors, int bedrooms, int meetingRooms, string address);

	/**
	* @brief Default destructor.
	*/
	~Hotel();

	// Clients
	/**
	* @brief Const member function to get the client's vector.
	*
	* @return The hotel's clients.
	*/
	vector<Client> getClients() const;


	void sortClients();

	/**
	* @brief Member function to add a new client.
	*
	* @param c The hotel's new client.
	*/
	void addClient(Client c);

	/**
	* @brief Member function to remove a client.
	*
	* @param c The hotel's removed client.
	*
	* @return 0 if the client is removed
	* 		  -1, if otherwise
	*/
	int removeClient(string name);

	// Rooms
	/**
	* @brief Const member function to get the room's vector.
	*
	* @return The hotel's rooms.
	*/
	vector<Room> getRooms() const;

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
	* @brief Member function to add a new room.
	*
	* @param r The hotel's new room.
	*/
	void addRoom(Room r);

	/**
	* @brief Member function to remove a room.
	*
	* @param number The number of the hotel's removed room.
	*/
	void removeRoom(int number);

	/**
	* @brief Member function to remove the rooms from the top floor.
	*/
	void removeRoomsFromTopFloor();

	// Reservations
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
	* @brief Member function to remove a reservation.
	*
	* @param d The date of the hotel's removed reservation.
	*
	* @param R The room of the hotel's removed reservation.
	*/
	void removeReservation(Date d, Room R);

	// Employees
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
	* @brief Member function to remove a employee.
	*
	* @param i index of the employee to remove.
	*/
	void removeEmployee(int id);

	/**
	* @brief Member function that equally distributes the supervisors over all the rooms.
	*/
	void allocateEmployees();

	/**
	* @brief Member function that shows all the employees information.	
	*/
	void showEmployees();

	// Building Information
	// Floors
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

	// Bedrooms
	/**
	* @brief Const member function to get the total number of the hotel's bedrooms.
	*
	* @return The total number of hotel's bedrooms.
	*/
	int getBedrooms() const;

	/**
	* @brief Member function to add a new bedroom.
	*/
	void addBedroom();

	/**
	* @brief Member function to remove a bedroom.
	*/
	void removeBedroom();

	// MeetingRooms
	/**
	* @brief Const member function to get the total number of the hotel's meeting rooms.
	*
	* @return The total number of hotel's meeting rooms.
	*/
	int getMeetingRooms() const;

	/**
	* @brief Member function to add a new meeting room.
	*/
	void addMeetingRoom();

	/**
	* @brief Member function to remove a meeting room.
	*/
	void removeMeetingRoom();

	// Address
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

	/**
	* @brief Member function that returns the number of the supervisors among the employees
	*/
	int getNoSupervisors();
};

#endif /* HOTEL_H_ */
