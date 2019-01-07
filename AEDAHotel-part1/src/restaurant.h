#ifndef RESTAURANT_H_
#define RESTAURANT_H_

#include <iostream>
#include <string>

using namespace std;

class Restaurant {
	string name;
	string type;
	int distance;
public:
	Restaurant();
	Restaurant(string name, string type, int distance);
	string getName();
	string getType();
	int getDistance();
	void setName(string name);
	void setType(string type);
	void setDistance(int distance);
	//bool operator < (Restaurant c);
};


#endif /* CLIENT_H_ */