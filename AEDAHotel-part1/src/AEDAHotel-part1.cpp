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

Hotel* buildDemoHotel() {
	Hotel *h = new Hotel(4, "Porto, Rua da Alegria 20");

	//... creating employees
	Employee *e1 = new Employee("Diogo Torres", false);
	h->addEmployee(*e1);

	Employee *e2 = new Employee("Gustavo Rodrigues", true);
	h->addEmployee(*e2);

	Employee *e3 = new Employee("Tiago Ferreira", false);
	h->addEmployee(*e3);

	Employee *e4 = new Employee("Armanda Correia", true);
	h->addEmployee(*e4);

	Employee *e5 = new Employee("Roberto Dias", false);
	h->addEmployee(*e5);

	Employee *e6 = new Employee("Joana Pereira", false);
	h->addEmployee(*e6);

	//... Building Rooms
	Bedroom *b101 = new Bedroom(101, 1, "Back");
	h->addRoom(b101);
	Bedroom *b102 = new Bedroom(102, 1, "Back");
	h->addRoom(b102);
	Bedroom *b103 = new Bedroom(103, 1, "Front");
	h->addRoom(b103);
	Bedroom *b104 = new Bedroom(104, 2, "Back");
	h->addRoom(b104);
	Bedroom *b105 = new Bedroom(105, 2, "Front");
	h->addRoom(b105);
	Bedroom *b201 = new Bedroom(201, 1, "Back");
	h->addRoom(b201);
	Bedroom *b202 = new Bedroom(202, 1, "Back");
	h->addRoom(b202);
	Bedroom *b203 = new Bedroom(203, 1, "Front");
	h->addRoom(b203);
	Bedroom *b204 = new Bedroom(204, 2, "Back");
	h->addRoom(b204);
	Bedroom *b205 = new Bedroom(205, 2, "Front");
	h->addRoom(b205);
	Bedroom *b301 = new Bedroom(301, 1, "Back");
	h->addRoom(b301);
	Bedroom *b302 = new Bedroom(302, 1, "Back");
	h->addRoom(b302);
	Bedroom *b303 = new Bedroom(303, 1, "Front");
	h->addRoom(b303);
	Bedroom *b304 = new Bedroom(304, 2, "Back");
	h->addRoom(b304);
	Bedroom *b305 = new Bedroom(305, 2, "Front");
	h->addRoom(b305);
	MeetingRoom *mr401 = new MeetingRoom(401, 25, true, true);
	h->addRoom(mr401);
	MeetingRoom *mr402 = new MeetingRoom(402, 10, false, false);
	h->addRoom(mr402);

	//... Creating Reservations
	// winter
	Date *winter1 = new Date(12, 12, 2018);
	Reservation *r1 = new Reservation(*winter1, b305, 2);
	h->addReservation(*r1);
	Date *winter2 = new Date(12, 2, 2019);
	Reservation *r2 = new Reservation(*winter2, b205, 1);
	h->addReservation(*r2);
	// Spring
	Date *spring1 = new Date(21, 4, 2019);
	Reservation *r3 = new Reservation(*spring1, b102, 1);
	h->addReservation(*r3);
	Date *spring2 = new Date(3, 5, 2019);
	Reservation *r4 = new Reservation(*spring2, b203, 3);
	h->addReservation(*r4);
	// Summer
	Date *summer1 = new Date(20, 6, 2019);
	Reservation *r5 = new Reservation(*summer1, b105, 4);
	h->addReservation(*r5);
	Date *summer2 = new Date(14, 7, 2019);
	Reservation *r6 = new Reservation(*summer2, b202, 5);
	h->addReservation(*r6);
	// Autumn
	Date *autumn1 = new Date(11, 9, 2019);
	Reservation *r7 = new Reservation(*autumn1, b301, 10);
	h->addReservation(*r7);
	Date *autumn2 = new Date(17, 10, 2019);
	Reservation *r8 = new Reservation(*autumn2, b203, 2);
	h->addReservation(*r8);

	//... creating clients
	Date *bd1 = new Date(11, 9, 1990);
	Client *c1 = new Client("Luis Goncalves", *bd1);
	c1->addReservation(r1);
	c1->addReservation(r5);
	h->addClient(c1);

	Date *bd2 = new Date(21, 4, 1996);
	Client *c2 = new Client("Joao Francisco", *bd2);
	c2->addReservation(r3);
	c2->addReservation(r2);
	h->addClient(c2);

	Date *bd3 = new Date(7, 12, 1978);
	Client *c3 = new Client("Maria Almeida", *bd3);
	c3->addReservation(r8);
	c3->addReservation(r4);
	h->addClient(c3);

	Date *bd4 = new Date(2, 9, 1986);
	Client *c4 = new Client("Carlos Marques", *bd4);
	c4->addReservation(r7);
	c4->addReservation(r6);
	h->addClient(c4);

	return h;
}

int main() {
	int menuOption;

	Hotel *h = buildDemoHotel();
	Date currentDate = Date(31, 12, 2018);

	cout << "=======================================" << endl;
	cout << "======== Welcome to Hotel AEDA ========" << endl;
	cout << "=======================================" << endl;
	do {
		menuOption = menu(&currentDate);
		switch(menuOption) {
		case 1: // Hotel Information
			hotelInformationMenu(h);
			break;
		case 2: // Clients
			clientMenu(h);
			break;
		case 3: // Reservations
			reservationMenu(h);
			break;
		case 4: // Rooms
			roomsMenu(h);
			break;
		case 5: // Employees
			employeesMenu(h);
			break;
		case 6:
			currentDate++;
			break;
		}
		if (menuOption < 0 || menuOption > 6) {
			cout << "ERROR: Not a valid Operation! Please try again..." << endl;
		}
	} while (menuOption != 0);

	return 0;
}
