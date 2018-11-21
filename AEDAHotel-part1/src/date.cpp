#include "date.h"

// Calculating weekday
int getCCode(int month, bool leap) {
	switch(month) {
	case 1: // January
		if (leap) {return 6;} else {return 0;}
		break;
	case 2: // February
		if (leap) {return 2;} else {return 3;}
		break;
	case 3: // March
		return 3;
		break;
	case 4: // April
		return 6;
		break;
	case 5: // May
		return 1;
		break;
	case 6: // June
		return 4;
		break;
	case 7: // July
		return 6;
		break;
	case 8: // August
		return 2;
		break;
	case 9: // September
		return 5;
		break;
	case 10: // October
		return 6;
		break;
	case 11: // November
		return 3;
		break;
	case 12: // December
		return 5;
		break;
	}
	return 0;
}

bool isLeap(int year) {
	if (year % 400 == 0) {
		return true;
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else
		return false;
}

int calculateWeekday(int day, int month, int year) {
	int s = year / 100; // two first digits of the year
	int a = year % 100; // two last digits of the year
	int c = getCCode(month, isLeap(year));
	return (((5*a)/4) + c + day - (2*(s%4)) + 7) % 7;
}

bool validDate(int day, int month, int year) {
	if (month < 1 || month > 12) return false;
	if (year < 2018) return false;
	switch(month) {
		case 1: // January
			if (day < 0 || day > 31) return false;
			break;
		case 2: // February
			if (isLeap(year) && (day < 0 || day > 29)) return false;
			else if (!isLeap(year) && (day < 0 || day > 28)) return false;
			break;
		case 3: // March
			if (day < 0 || day > 31) return false;
			break;
		case 4: // April
			if (day < 0 || day > 30) return false;
			break;
		case 5: // May
			if (day < 0 || day > 31) return false;
			break;
		case 6: // June
			if (day < 0 || day > 30) return false;
			break;
		case 7: // July
			if (day < 0 || day > 31) return false;
			break;
		case 8: // August
			if (day < 0 || day > 31) return false;
			break;
		case 9: // September
			if (day < 0 || day > 30) return false;
			break;
		case 10: // October
			if (day < 0 || day > 31) return false;
			break;
		case 11: // November
			if (day < 0 || day > 30) return false;
			break;
		case 12: // December
			if (day < 0 || day > 31) return false;
			break;
		}
	return true;
}


/******************/
/*** Date Class ***/
/******************/

Date::Date() {
	this->day = 0;
	this->month = 0;
	this->year = 0;
}

/*
 * Spring - March 1 to May 31;
 * Summer - June 1 to August 31;
 * Autumn - September 1 to November 30
 * Winter - December 1 to February 28 (February 29 in a leap year).
 */

Date::Date(int day, int month, int year) {
	if (!validDate(day, month, year)) {
		throw (InvalidDate(day, month, year));
	}
	else {
		this->day = day;
		this->month = month;
		this->year = year;
		// Calculating season
		if (month >= 3 && month <= 5)
			this->season = "Spring";
		else if (month >= 6 && month <= 8)
			this->season = "Summer";
		else if (month >= 9 && month <= 11)
			this->season = "Autumn";
		else
			this->season = "Winter";
		// Calculating weekday
		switch(calculateWeekday(day, month, year)) {
		case 0:
			this->weekday = "Saturday";
			break;
		case 1:
			this->weekday = "Sunday";
			break;
		case 2:
			this->weekday = "Monday";
			break;
		case 3:
			this->weekday = "Tuesday";
			break;
		case 4:
			this->weekday = "Wednesday";
			break;
		case 5:
			this->weekday = "Thursday";
			break;
		case 6:
			this->weekday = "Friday";
			break;
		}
	}
}

// get
int Date::getDay() {
	return this->day;
}

int Date::getMonth() {
	return this->month;
}

int Date::getYear() {
	return this->year;
}

string Date::getSeason() {
	return this->season;
}

string Date::getWeekday() {
	return this->weekday;
}

string Date::getInfo() const {
	stringstream ss;
	ss << day << "/" << month << "/" << year;
	return ss.str();
}

// set
void Date::setDay(int day) {
	this->day = day;

}

void Date::setMonth(int month) {
	this->month = month;

}

void Date::setYear(int year) {
	this->year = year;
}

void Date::setSeason(string season) {
	this->season = season;
}

void Date::setWeekday(string weekday) {
	this->weekday = weekday;
}

string Date::showDate() {
	stringstream ss;
	ss << this->day << "/" << this->month << "/" << this->year << endl;
	return ss.str();
}

string Date::showExtendedDate() {
	stringstream ss;
	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	ss << this->day << "  " << monthName[this->month - 1] << "  " << this->year << endl;
	return ss.str();
}

// calculating adjacent dates
void nextDate(Date *d) {
	int day = d->getDay();
	int month = d->getMonth();
	int year = d->getYear();

	// day 31
	if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
		d->setDay(1);
		// month 12
		if (month == 12) {
			d->setMonth(1);
			d->setYear(year + 1);
		}
		else {
			d->setMonth(month + 1);
			d->setYear(year);
		}
	}
	//day 30
	else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		d->setDay(1);
		d->setMonth(month + 1);
		d->setYear(year);
	}
	// February
	else if (month == 2 && day >= 28) {
		if(isLeap(year)) {
			if (day == 28) {
				d->setDay(29);
				d->setMonth(2);
				d->setYear(year);
			}
			else if (day == 29) {
				d->setDay(1);
				d->setMonth(3);
				d->setYear(year);
			}
		}
		else {
			d->setDay(1);
			d->setMonth(3);
			d->setYear(year);
		}
	}
	// generic case
	else {
		d->setDay(day + 1);
		d->setMonth(month);
		d->setYear(year);
	}
}

void previousDate(Date *d){
	int day = d->getDay();
	int month = d->getMonth();
	int year = d->getYear();

	// day 1
	if (d->getDay() == 1) {
		// month 1
		if (month == 1) {
			d->setDay(31);
			d->setMonth(12);
			d->setYear(year - 1);
		}
		else {
			// month 3
			if (month == 3) {
				if (isLeap(year))
					d->setDay(29);
				else
					d->setDay(28);
			}
			else if (month == 5 || month == 7 || month == 10 || month == 12) {
				d->setDay(30);
			}
			else if (month == 4 || month == 6 || month == 8 || month == 9 || month == 11) {
				d->setDay(31);
			}
		}
		d->setMonth(month - 1);
		d->setYear(year);
	}
	else {
		d->setDay(day - 1);
		d->setMonth(month);
		d->setYear(year);
	}
}


// Operators
Date *Date::operator ++() { // prefix
	nextDate(this);
	return this;
}

Date *Date::operator ++(int) { // postfix
	Date *d = new Date();
	nextDate(this);
	return d;
}

Date *Date::operator --() { // prefix
	previousDate(this);
	return this;
}

Date *Date::operator --(int) { // postfix
	Date *d = new Date();
	previousDate(this);
	return d;
}

bool Date::operator ==(Date *date) {
	if (this->day == date->day && this->month == date->month && this->year == date->year)
		return true;
	else
		return false;
}

Date *Date::operator =(Date *date) {
	this->setDay(date->getDay());
	this->setMonth(date->getMonth());
	this->setYear(date->getYear());
	this->setSeason(date->getSeason());
	this->setWeekday(date->getWeekday());
	return this;
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
