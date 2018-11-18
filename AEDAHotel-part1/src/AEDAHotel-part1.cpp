//============================================================================
// Name        : AEDAHotel-part1.cpp
// Author      : Goncalo Marantes, Joao Santos, Luis Goncalves
// Version     : 1.0
// Copyright   : MIT License
// Description : AEDAHotel
//============================================================================

#include <iostream>
#include "hotel.h"
#include "client.h"
#include "reservation.h"
#include "room.h"
#include "date.h"
#include "AuxFunctions.h"
#include <string>
#include <sstream>

using namespace std;

int menu();
int hotelInformationMenu(Hotel *h);
int hotelChangeInformationMenu(Hotel *h);


int main() {
	Hotel h;
	cout << "------ Welcome to Hotel AEDA ------" << endl;
	int menuOption = menu();
	/* TESTES
	Client c1("Alex");
	Date d1(17, 11, 2018);
	MeetingRoom *Mr = new MeetingRoom(1,10,1,1);
	Reservation *R = new Reservation(d1, Mr,5);
	c1.addReservation(R);
	cout << c1.getInfo();
	*/

	return 0;
}

int menu() {
	int menuOption;

	do {
		cout << "What would you like to do?" << endl;
		cout << "Hotel Information - 1" << endl;
		cout << "Clients - 2" << endl;
		cout << "Reservations - 3" << endl;
		cout << "Rooms - 4" << endl;
		cout << "Employees - 5" << endl;
		cout << "Exit - 0" << endl;
		cout << "Option: ";
		cin >> menuOption;
		if (menuOption < 0 || menuOption > 5) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 5);

	return menuOption;
}

int hotelInformationMenu(Hotel *h) {
	int menuOption;

	do {
		cout << "------ HOTEL INFORMATION ------" << endl;
		cout << "Hotel AEDA - " << h->getAddress() << endl;
		cout << "Total Rooms: " << h->getBedrooms() + h->getMeetingRooms() << ", ";
		cout << "Bedrooms: " << h->getBedrooms()<< ", ";
		cout << "Meeting Rooms: " << h->getMeetingRooms() << endl;
		cout << "Clients: " << h->getClients().size() << endl;
		cout << "Employees: " << h->getEmployees().size() << endl << endl;

		cout << "What would you like to do?" << endl;
		cout << "Change Information - 1 " << endl;
		cout << "Back - 0 " << endl;
		cout << "Option: ";
		cin >> menuOption;
		if (menuOption < 0 || menuOption > 1) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 1);

	return menuOption;
}

int hotelChangeInformationMenu(Hotel *h) {
	int menuOption;

	do {
		cout << "------ CHANGE HOTEL INFORMATION ------" << endl;
		cout << "Hotel AEDA - " << h->getAddress() << endl;
		cout << "Total Rooms: " << h->getBedrooms() + h->getMeetingRooms() << ", ";
		cout << "Bedrooms: " << h->getBedrooms()<< ", ";
		cout << "Meeting Rooms: " << h->getMeetingRooms() << endl;
		cout << "Clients: " << h->getClients().size() << endl;
		cout << "Employees: " << h->getEmployees().size() << endl << endl;

		cout << "What would you like to do?" << endl;
		cout << "Change Information - 1 " << endl;
		cout << "Back - 0 " << endl;
		cout << "Option: ";
		cin >> menuOption;
		if (menuOption < 0 || menuOption > 1) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 1);

	return menuOption;
}
