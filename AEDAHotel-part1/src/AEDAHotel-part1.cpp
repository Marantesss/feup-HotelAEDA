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
