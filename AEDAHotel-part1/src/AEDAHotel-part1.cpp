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

int main() {
	Hotel h();

	Client c1("Alex");

	Date d1(17, 11, 2018);

	MeetingRoom *Mr = new MeetingRoom(1,10,1,1);

	Reservation *R = new Reservation(d1, Mr,5);

	c1.addReservation(R);

	cout << c1.getInfo();

	system("PAUSE");
	return 0;
}
