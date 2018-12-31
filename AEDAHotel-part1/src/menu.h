#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include "hotel.h"
#include "AuxFunctions.h"

using namespace std;

/**
 * @brief Function to clear input buffer
 *
 * Calls cin.clear() and cin.ignore()
 */
void clearBuffer();

/**
 * @brief Function to increment a date passed as argument
 */
void nextDay(Date* date);

/**
 * @brief Function to get menu options
 *
 * Displays date passed as argument
 * Calls showMenu() to print menu options
 * @see showMenu()
 *
 * @param Pointer to date's memory location
 *
 * @return The menu option chosen by the user
 */
int menu(Date *date);

/**
 * @brief Prints the various menu options available on screen
 *
 * @return The menu option chosen by the user
 */
int showMenu();



/********** Hotel Information **********/

/**
 * @brief Function to get hotel information menu options
 *
 * Calls showHotelInformationMenu() to print hotel information menu options
 * @see showHotelInformationMenu()
 */
void hotelInformationMenu(Hotel *h);

/**
 * @brief Prints the various hotel information menu options available on screen
 *
 * @return The hotel information menu option chosen by the user
 */
int showHotelInformationOptions(Hotel *h);

/**
 * @brief Function to change hotel address
 *
 * Reads the new address introduced by the user
 */
void changeHotelAddress(Hotel *h);

/**
 * @brief Function to remove hotel's top floor
 *
 * Also removes all reservations regarding that floor
 */
void removeHotelTopFloor(Hotel *h);



/********** Client Information **********/

/**
 * @brief Function to get client information menu options
 *
 * Calls showClientMenu() to print clients information menu options
 * @see showClientMenu()
 */
void clientMenu(Hotel *h);

/**
 * @brief Prints the various client menu options available on screen
 *
 * @return The client information menu option chosen by the user
 */
int showClientOptions(Hotel *h);

/**
 * @brief Function to create and add a new client
 *
 * Reads the new client's name and adds it to the hotel's client vector
 */
void addClient(Hotel *h);

/**
 * @brief Function to find and remove an existing client
 *
 * Reads the client's name, searches it, and deletes it from the hotel's client vector
 */
void removeClient(Hotel *h);

/**
 * @brief Function to find an existing client
 *
 * Reads the client's name and searches it, printing its information on screen
 */
void searchClient(Hotel *h);

/**
 * @brief Function to import clients from txt file
 */
void importClient(Hotel *h);



/********** Room Information **********/

/**
 * @brief Function to get room information menu options
 *
 * Calls showRoomMenu() to print clients information menu options
 * @see showRoomOptions()
 */
void roomsMenu(Hotel *h);

/**
 * @brief Prints the various room menu options available on screen
 *
 * @return The room information menu option chosen by the user
 */
int showRoomsOptions(Hotel *h);

/**
 * @brief Function to create and add a new room
 *
 * Reads the type of room the user wants to add and calls
 * addMeetingRoom() and addBedroom() accordingly
 * @see addMeetingRoom()
 * @see addBedroom()
 */
void addRoom(Hotel *h);

/**
 * @brief Function to create and add a new Meeting Room
 *
 * Reads the new room's information and adds it to the hotel's room vector
 */
void addMeetingRoom(Hotel *h);

/**
 * @brief Function to create and add a new Bedroom
 *
 * Reads the new room's information and adds it to the hotel's room vector
 */
void addBedroom(Hotel *h);

/**
 * @brief Function to find and remove an existing room
 *
 * Reads the room's number, searches it, and deletes it from the hotel's room vector
 */
void removeRoom(Hotel *h);

/**
 * @brief Function to find an existing client
 *
 * Reads the client's name and searches it, printing its information on screen
 */
void searchRoom(Hotel *h);

/**
 * @brief Function to import rooms from txt file
 */
void importRoom(Hotel *h);


/********** Reservation Information **********/

/**
 * @brief Function to get room information menu options
 *
 * Calls showEmployeeOptions() to print clients information menu options
 * @see showEmployeeOptions()
 */
void reservationMenu(Hotel *h);

/**
 * @brief Prints the various employee menu options available on screen
 *
 * @return The employee information menu option chosen by the user
 */
int showReservationOptions(Hotel *h);

/**
 * @brief Function to create and add a new reservation
 *
 * Reads the new reservations's date and room, and adds it to the hotel's reservation vector
 */
void addReservation(Hotel *h);

/**
 * @brief Function to find and remove an existing reservation
 *
 * Reads the reservation's date and room, searches it, and deletes it from the hotel's reservation vector
 */
void removeReservation(Hotel *h);



/********** Employee Information **********/

/**
 * @brief Function to get room information menu options
 *
 * Calls showEmployeeOptions() to print clients information menu options
 * @see showEmployeeOptions()
 */
void employeesMenu(Hotel *h);

/**
 * @brief Prints the various employee menu options available on screen
 *
 * @return The employee information menu option chosen by the user
 */
int showEmployeeOptions(Hotel *h);

/**
 * @brief Function to create and add a new employee
 *
 * Reads the new employees's name and adds it to the hotel's client vector
 */
void addEmployee(Hotel *h);

/**
 * @brief Function to find and remove an existing employee
 *
 * Reads the employee's id, searches it, and deletes it from the hotel's room vector
 */
void removeEmployee(Hotel *h);

/**
 * @brief Function to find an existing client
 *
 * Reads the employee's id and searches it, printing its information on screen
 */
void searchEmployee(Hotel *h);

/**
 * @brief Function to import employees from txt file
 */
void importEmployee(Hotel *h);

#endif /* MENU_H_ */
