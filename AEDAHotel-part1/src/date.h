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
	string season;
	string weekday;
public:
	Date();
	Date(int day, int month, int year);
	~Date(){}
	// get
	int getDay();
	int getMonth();
	int getYear();
	string getSeason();
	string getWeekday();
	string getInfo() const;
	// set
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(string &date); // (D M Y)
	void setSeason(string season);
	void setWeekday(string weekday);
	// show
	string showDate();
	string showExtendedDate();
	// Operators
	Date operator ++(); // prefix
	Date operator ++(int); // postfix
	Date operator --(); // prefix
	Date operator --(int); // postfix
	Date operator =(Date date);
	bool operator ==(Date &date);
	bool operator < (Date date);
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
