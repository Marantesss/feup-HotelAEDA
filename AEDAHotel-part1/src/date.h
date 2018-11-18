#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Date Class
class Date {
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	~Date(){}
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void showDate();
	void showExtendedDate();
	string getInfo() const;

};

// InvalidDate exception
class InvalidDate {
	int day;
	int month;
	int year;
public:
	InvalidDate(int day, int month, int year);
	int getDay();
	int getMonth();
	int getYear();
};

#endif /* DATE_H_ */
