#include "date.h"

/******************/
/*** Date Class ***/
/******************/

Date::Date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}

void Date::setDay(int day) {
	this->day = day;

}

void Date::setMonth(int month) {
	this->month = month;

}

void Date::setYear(int year) {
		this->year = year;
}

void Date::showDate() {
	cout << this->day << "/" << this->month << "/" << this->year << endl;
}

void Date::showExtendedDate() {
	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	cout << day << "  " << monthName[month - 1] << "  " << year << endl;
}

/********************************/
/**** InvalidDate exception *****/
/********************************/

InvalidDate::InvalidDate(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

int InvalidDate::getDay() {
	return this->day;
}

int InvalidDate::getMonth() {
	return this->month;
}

int InvalidDate::getYear() {
	return this->year;
}
