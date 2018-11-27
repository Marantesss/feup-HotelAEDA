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
 * @brief Function to get menu options
 *
 * Calls showMenu() to print menu options
 * @see showMenu()
 *
 * @return The menu option chosen by the user
 */
int menu();

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
int roomsMenu(Hotel *h);

/**
 * @brief Prints the various room menu options available on screen
 *
 * @return The room information menu option chosen by the user
 */
int showRoomsOptions(Hotel *h);


/********** Reservation Information **********/



/********** Employee Information **********/

int employeesMenu(Hotel *h);


#endif /* MENU_H_ */
