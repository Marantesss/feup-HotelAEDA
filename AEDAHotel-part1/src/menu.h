#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include "hotel.h"
#include "AuxFunctions.h"

using namespace std;

/**
 * @brief Function to clear input buffer.
 *
 * Calls cin.clear() and cin.ignore().
 */
void clearBuffer();

/**
 * @brief Function to get menu options.
 *
 * Displays date passed as argument.
 * Calls showMenu() to print menu options.
 * @see showMenu()
 *
 * @param Pointer to date's memory location.
 *
 * @return The menu option chosen by the user.
 */
int menu(Date *date);

/**
 * @brief Prints the various menu options available on screen.
 *
 * @return The menu option chosen by the user.
 */
int showMenu();



/********** Hotel Information **********/

/**
 * @brief Function to get hotel information menu options.
 *
 * Calls showHotelInformationMenu() to print hotel information menu options.
 * @see showHotelInformationMenu()
 */
void hotelInformationMenu(Hotel *h);

/**
 * @brief Prints the various hotel information menu options available on screen.
 *
 * @return The hotel information menu option chosen by the user.
 */
int showHotelInformationOptions(Hotel *h);

/**
 * @brief Function to change hotel address.
 *
 * Reads the new address introduced by the user.
 */
void changeHotelAddress(Hotel *h);

/**
 * @brief Function to remove hotel's top floor.
 *
 * Also removes all reservations regarding that floor.
 */
void removeHotelTopFloor(Hotel *h);



/********** Client Information **********/

/**
 * @brief Function to get client information menu options.
 *
 * Calls showClientMenu() to print clients information menu options.
 * @see showClientMenu()
 */
void clientMenu(Hotel *h);

/**
 * @brief Prints the various client menu options available on screen.
 *
 * @return The client information menu option chosen by the user.
 */
int showClientOptions(Hotel *h);

/**
 * @brief Function to create and add a new client.
 *
 * Reads the new client's name and adds it to the hotel's client vector.
 */
void addClient(Hotel *h);

/**
 * @brief Function to find and remove an existing client.
 *
 * Reads the client's name, searches it, and deletes it from the hotel's client vector.
 */
void removeClient(Hotel *h);

/**
 * @brief Function to find an existing client.
 *
 * Reads the client's name and searches it, printing its information on screen.
 */
void searchClient(Hotel *h);

/**
 * @brief Function to import clients from txt file.
 */
void importClient(Hotel *h);



/********** Room Information **********/

/**
 * @brief Function to get room information menu options.
 *
 * Calls showRoomMenu() to print clients information menu options.
 * @see showRoomOptions()
 */
void roomsMenu(Hotel *h);

/**
 * @brief Prints the various room menu options available on screen.
 *
 * @return The room information menu option chosen by the user.
 */
int showRoomsOptions(Hotel *h);

/**
 * @brief Function to create and add a new room.
 *
 * Reads the type of room the user wants to add and calls.
 * addMeetingRoom() and addBedroom() accordingly.
 * @see addMeetingRoom()
 * @see addBedroom()
 */
void addRoom(Hotel *h);

/**
 * @brief Function to create and add a new Meeting Room.
 *
 * Reads the new room's information and adds it to the hotel's room vector.
 */
void addMeetingRoom(Hotel *h);

/**
 * @brief Function to create and add a new Bedroom
 *
 * Reads the new room's information and adds it to the hotel's room vector.
 */
void addBedroom(Hotel *h);

/**
 * @brief Function to find and remove an existing room.
 *
 * Reads the room's number, searches it, and deletes it from the hotel's room vector.
 */
void removeRoom(Hotel *h);

/**
 * @brief Function to find an existing client.
 *
 * Reads the client's name and searches it, printing its information on screen.
 */
void searchRoom(Hotel *h);

/**
 * @brief Function to import rooms from txt file.
 */
void importRoom(Hotel *h);


/********** Reservation Information **********/

/**
 * @brief Function to get room information menu options.
 *
 * Calls showEmployeeOptions() to print clients information menu options.
 * @see showEmployeeOptions()
 */
void reservationMenu(Hotel *h);

/**
 * @brief Prints the various employee menu options available on screen.
 *
 * @return The employee information menu option chosen by the user.
 */
int showReservationOptions(Hotel *h);

/**
 * @brief Function to create and add a new reservation.
 *
 * Reads the new reservations's date and room, and adds it to the hotel's reservation vector.
 */
void addReservation(Hotel *h);

/**
 * @brief Function to find and remove an existing reservation.
 *
 * Reads the reservation's date and room, searches it, and deletes it from the hotel's reservation vector.
 */
void removeReservation(Hotel *h);



/********** Employee Information **********/

/**
 * @brief Function to get employees information menu options.
 *
 * Calls showEmployeeOptions() to print employees information menu options.
 * @see showEmployeeOptions()
 */
void employeesMenu(Hotel *h);

/**
 * @brief Prints the various employee menu options available on screen.
 *
 * @return The employee information menu option chosen by the user.
 */
int showEmployeeOptions(Hotel *h);

/**
 * @brief Function to create and add a new employee.
 *
 * Reads the new employees's name and adds it to the hotel's client vector.
 */
void addEmployee(Hotel *h);

/**
 * @brief Function to find and remove an existing employee.
 *
 * Reads the employee's id, searches it, and deletes it from the hotel's room vector.
 */
void removeEmployee(Hotel *h);

/**
 * @brief Function to find an existing client.
 *
 * Reads the employee's id and searches it, printing its information on screen.
 */
void searchEmployee(Hotel *h);

/**
 * @brief Function to import employees from txt file.
 */
void importEmployee(Hotel *h);

/**
 * @brief Function to get vans information menu options.
 *
 * Calls showVanOptions() to print vans information menu options.
 * @see showVanOptions()
 */
void vansMenu(Hotel *h);

/**
 * @brief Prints the various vans menu options available on screen.
 *
 * @return The vans information menu option chosen by the user.
 */
int showVanOptions(Hotel *h);

/**
 * @brief Function to add a group to a van.
 *
 * Reads all the client's name and adds them to a hotel's van.
 */
void addGroup(Hotel *h);

/**
 * @brief Function to find and remove an existing van.
 *
 * Reads the van's id, searches it, and deletes it from the hotel's vans queue.
 */
void removeVan(Hotel *h);

/**
 * @brief Function to find an existing van.
 *
 * Reads the van's id and searches it, printing its information on screen.
 */
void searchVan(Hotel *h);

/**
 * @brief Function to import vans from txt file
 */
void importVan(Hotel *h);

/********** Event Information **********/

/**
 * @brief Function to get event information menu options.
 *
 * Calls showEventOptions() to print events information menu options.
 * @see showEventOptions()
 */
void eventMenu(Hotel *h);

/**
 * @brief Prints the various event menu options available on screen.
 *
 * @return The event information menu option chosen by the user.
 */
int showEventOptions(Hotel *h);

/**
 * @brief Function to create and add a new event.
 *
 * Reads the new events's name, date, location and description and adds it to the hotel's event container.
 */
void addEvent(Hotel *h);


/********** Restaurant Menu **********/

/**
 * @brief Function to get restaurant information menu options.
 *
 * Calls showRestaurantOptions() to print the restaurant information menu options.
 * @see showRestaurantOptions()
 */
void restaurantMenu(Hotel *h);

/**
 * @brief Prints the various restaurant menu options available on screen.
 *
 * @return The restaurant information menu option chosen by the user.
 */
int showRestaurantOptions(Hotel *h);

/**
 * @brief Function to create and add a new restaurant.
 *
 * Reads the new restaurants's name, type, and distance and adds it to the binary search tree containing the restaurants.
 */
void addRestaurant(Hotel *h);

/**
 * @brief Function to search for a restaurant in the binary search tree containing the restaurants.
 *
 * Reads the restaurants's name inputed by the user and shows it's information if it exists in the binary search tree containing the restaurants.
 */
void searchRestaurant(Hotel *h);

/**
 * @brief Function to show all the restaurants with a certain type.
 *
 * Reads the type inputed by the user and shows a list with the information of all the restaurants with that type.
 */
void showRestaurantsOfType(Hotel *h);

/**
 * @brief Function to show the information of the restaurant which is closer to the hotel.
 */
void showClosestRestaurant(Hotel *h);

/**
 * @brief Function to search for a restaurant and delete it from the binary search tree containing the restaurants.
 *
 * Reads the restaurants's name inputed by the user and deletes it from the binary search tree containing the restaurants.
 */
void deleteRestaurant(Hotel *h);

#endif /* MENU_H_ */
