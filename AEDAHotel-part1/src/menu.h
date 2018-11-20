#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include "hotel.h"
#include "client.h"
#include "AuxFunctions.h"

using namespace std;

int menu();

int hotelInformationMenu(Hotel *h);

int hotelChangeInformationMenu(Hotel *h);

int clientMenu(Hotel *h);

#endif /* MENU_H_ */
