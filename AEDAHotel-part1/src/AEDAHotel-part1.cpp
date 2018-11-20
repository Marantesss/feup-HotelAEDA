//============================================================================
// Name        : AEDAHotel-part1.cpp
// Author      : Goncalo Marantes, Joao Santos, Luis Goncalves
// Version     : 1.0
// Copyright   : MIT License
// Description : AEDAHotel
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include "hotel.h"
#include "client.h"
#include "reservation.h"
#include "room.h"
#include "date.h"
#include "AuxFunctions.h"
#include "menu.h"

using namespace std;

int menu();
int hotelInformationMenu(Hotel *h);
int hotelChangeInformationMenu(Hotel *h);

int main() {
	int menuOption;
	Hotel h(4, 15, 2, "Porto, Rua da Alegria 20");

	cout << "------ Welcome to Hotel AEDA ------" << endl;
	do {
		menuOption = menu();
		switch(menuOption) {
		case 1: // Hotel Information
			hotelInformationMenu(&h);
			break;
		case 2: // Clients
			break;
		case 3: // Reservations
			break;
		case 4: // Rooms
			break;
		case 5: // Employees
			break;
		}
		if (menuOption < 0 || menuOption > 5) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);
	
	system("PAUSE");
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
		cout << "Address: " << h->getAddress() << endl;
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
		if (menuOption == 1)
			hotelChangeInformationMenu(h);
		else if (menuOption < 0 || menuOption > 1) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption < 0 || menuOption > 1);

	return menuOption;
}

int hotelChangeInformationMenu(Hotel *h) {
	int menuOption, floorOperation;
	string newAddress;

	do {
		cout << "------ CHANGE HOTEL INFORMATION ------" << endl;
		cout << "Change Address - 1" << endl;
		cout << "Add Floor - 2" << endl;
		cout << "Remove Floor - 3" << endl;
		cout << "Back - 0 " << endl;
		cout << "Option: ";
		cin >> menuOption;
		switch (menuOption) {
		case 1:
			cout << "Enter new address: ";
			// cleaning the buffer
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin,newAddress);
			// updating the address
			h->setAddress(newAddress);
			cout << "Address updated!" << endl;
			break;
		case 2:
			// h->addFloor();
			cout << "Floor added!" << endl;
			break;
		case 3:
			cout << "Which floor do you want to remove?" << endl;
			cout << h->getRoomsInfo(); // Prints all rooms
			cout << "This action will remove all existing reservations and rooms in the floor." << endl;
			cout << "Enter floor number (or 0 to go back): ";
			cin >> floorOperation;
			if (floorOperation < 0 || floorOperation > h->getFloors()) {
				cout << "ERROR: Not a valid Floor/Operation! Please try again..." << endl;
			}
			else if (floorOperation > 0 || floorOperation <= h->getFloors()) {
				h->removeRoomsFromFloor(menuOption);
				h->removeFloor();
			}
			break;
		}
		if (menuOption < 0 || menuOption > h->getFloors()) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return 1;
}
