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

Hotel buildDemoHotel() {
	Hotel h(4, "Porto, Rua da Alegria 20");

	//... Building Rooms
	Bedroom b101(101, 2, "Back");
	h.addRoom(b101);
	Bedroom b102(102, 2, "Back");
	h.addRoom(b102);
	Bedroom b103(103, 2, "Front");
	h.addRoom(b103);
	Bedroom b104(104, 4, "Back");
	h.addRoom(b104);
	Bedroom b105(105, 4, "Front");
	h.addRoom(b105);
	Bedroom b201(201, 2, "Back");
	h.addRoom(b201);
	Bedroom b202(202, 2, "Back");
	h.addRoom(b202);
	Bedroom b203(203, 2, "Front");
	h.addRoom(b203);
	Bedroom b204(204, 4, "Back");
	h.addRoom(b204);
	Bedroom b205(205, 4, "Front");
	h.addRoom(b205);
	Bedroom b301(301, 2, "Back");
	h.addRoom(b301);
	Bedroom b302(302, 2, "Back");
	h.addRoom(b302);
	Bedroom b303(303, 2, "Front");
	h.addRoom(b303);
	Bedroom b304(304, 4, "Back");
	h.addRoom(b304);
	Bedroom b305(305, 4, "Front");
	h.addRoom(b305);
	MeetingRoom mr401(401, 25, true, true);
	h.addRoom(mr401);
	MeetingRoom mr402(402, 10, false, false);
	h.addRoom(mr402);

	//... Creating Reservations
	// winter
	Date winter1(12, 12, 2018);
	Reservation r1(winter1, &b305, 2);
	h.addReservation(r1);
	Date winter2(23, 01, 2018);
	Reservation r2(winter2, &b102, 1);
	h.addReservation(r2);
	// Spring
	Date spring1(21, 4, 2019);
	Reservation r3(spring1, &b102, 1);
	h.addReservation(r3);
	Date spring2(3, 5, 2019);
	Reservation r4(spring2, &b203, 3);
	h.addReservation(r4);
	// Summer
	Date summer1(20, 6, 2019);
	Reservation r5(summer1, &b105, 4);
	h.addReservation(r5);
	Date summer2(14, 7, 2019);
	Reservation r6(summer2, &b202, 5);
	h.addReservation(r6);
	// Autumn
	Date autumn1(11, 9, 2019);
	Reservation r7(autumn1, &b301, 10);
	h.addReservation(r7);
	Date autumn2(17, 10, 2019);
	Reservation r8(autumn2, &b203, 2);
	h.addReservation(r8);

	//... creating clients
	Client c1("Luis Goncalves");
	c1.addReservation(&r1);
	c1.addReservation(&r5);
	h.addClient(c1);

	Client c2("Joao Francisco");
	c2.addReservation(&r3);
	c2.addReservation(&r2);
	h.addClient(c2);

	Client c3("Maria Almeida");
	c3.addReservation(&r8);
	c3.addReservation(&r4);
	h.addClient(c3);

	Client c4("Carlos Marques");
	c4.addReservation(&r7);
	c4.addReservation(&r6);
	h.addClient(c4);

	//... creating employees
	Employee e1(1, "Diogo Torres", false);
	h.addEmployee(e1);

	Employee e2(2, "Gustavo Rodrigues", true);
	h.addEmployee(e2);

	Employee e3(3, "Tiago Ferreira", false);
	h.addEmployee(e3);

	Employee e4(4, "Armanda Correia", true);
	h.addEmployee(e4);

	Employee e5(5, "Roberto Dias", false);
	h.addEmployee(e5);

	Employee e6(6, "Joana Pereira", false);
	h.addEmployee(e6);

	return h;
}

int main() {
	int menuOption;
	Hotel h = buildDemoHotel();

	cout << "=======================================" << endl;
	cout << "======== Welcome to Hotel AEDA ========" << endl;
	cout << "=======================================" << endl;
	do {
		menuOption = menu();
		switch(menuOption) {
		case 1: // Hotel Information
			hotelInformationMenu(&h);
			break;
		case 2: // Clients
			clientMenu(&h);
			break;
		case 3: // Reservations
			break;
		case 4: // Rooms
			roomsMenu(&h);
			break;
		case 5: // Employees
			employeesMenu(&h);
			break;
		}
		if (menuOption < 0 || menuOption > 5) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return 0;
}
