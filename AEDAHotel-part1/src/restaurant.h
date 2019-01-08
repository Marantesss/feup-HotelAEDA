#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Restaurant {
	string name;
	string type;
	int distance;
public:
	Restaurant();
	Restaurant(string name, string type, int distance);
	string getName() const;
	string getType() const;
	int getDistance() const;
	void setName(string name);
	void setType(string type);
	void setDistance(int distance);
	string getInfo() const;
	bool operator < (const Restaurant &r) const;
	bool operator == (const Restaurant &r) const;
};

class NonExistingRestaurant {
	string name;
public:
	NonExistingRestaurant(string name);
	string getName();
};

class ExistingRestaurant {
	string name;
public:
	ExistingRestaurant(string name);
	string getName();
};


#endif /* CLIENT_H_ */