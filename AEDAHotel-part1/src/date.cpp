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
Date *nextDate(Date *d) {
	Date *newDate = new Date();
	// day 31
	if (d->getDay() == 31 && (d->getMonth() == 1 || d->getMonth() == 3 || d->getMonth() == 5 || d->getMonth() == 7 || d->getMonth() == 8 || d->getMonth() == 10 || d->getMonth() == 12)) {
		newDate->setDay(1);
		// month 12
		if (d->getMonth() == 12) {
			newDate->setMonth(1);
			newDate->setYear(d->getYear() + 1);
		}
		else {
			newDate->setMonth(d->getMonth() + 1);
			newDate->setYear(d->getYear());
		}
	}
	//day 30
	else if (d->getDay() == 30 && (d->getMonth() == 4 || d->getMonth() == 6 || d->getMonth() == 9 || d->getMonth() == 11)) {
		newDate->setDay(1);
		newDate->setMonth(d->getMonth() + 1);
		newDate->setYear(d->getYear());
	}
	// February
	else if (d->getMonth() == 2 && d->getDay() >= 28) {
		if(isLeap(d->getYear())) {
			if (d->getDay() == 28) {
				newDate->setDay(29);
				newDate->setMonth(2);
				newDate->setYear(d->getYear());
			}
			else if (d->getDay() == 29) {
				newDate->setDay(1);
				newDate->setMonth(3);
				newDate->setYear(d->getYear());
			}
		}
		else {
			newDate->setDay(1);
			newDate->setMonth(3);
			newDate->setYear(d->getYear());
		}
	}
	// generic case
	else {
		newDate->setDay(d->getDay() + 1);
		newDate->setMonth(d->getMonth());
		newDate->setYear(d->getYear());
	}

	return newDate;
}

Date *previousDate(Date *d){
	Date *newDate = new Date();
	// day 1
	if (d->getDay() == 1) {
		// month 1
		if (d->getMonth() == 1) {
			newDate->setDay(31);
			newDate->setMonth(12);
			newDate->setYear(d->getYear() - 1);
		}
		else {
			// month 3
			if (d->getMonth() == 3) {
				if (isLeap(d->getYear()))
					newDate->setDay(29);
				else
					newDate->setDay(28);
			}
			else if (d->getMonth() == 5 || d->getMonth() == 7 || d->getMonth() == 10 || d->getMonth() == 12) {
				d->setDay(30);
			}
			else if (d->getMonth() == 4 || d->getMonth() == 6 || d->getMonth() == 8 || d->getMonth() == 9 || d->getMonth() == 11) {
				d->setDay(31);
			}
		}
		newDate->setMonth(d->getMonth() - 1);
		newDate->setYear(d->getYear());
	}
	else {
		newDate->setDay(d->getDay() - 1);
		newDate->setMonth(d->getMonth());
		newDate->setYear(d->getYear());
	}

	return newDate;
}


// Operators
/*
Date *Date::operator ++() { // prefix
	this = nextDate(this);
	return this;
}

Date *Date::operator ++(int) { // postfix
	Date *d = this;
	this = nextDate(d);
	return d;
}

Date *Date::operator --() { // prefix

}

Date *Date::operator --(int) { // postfix

}
*/

bool Date::operator ==(Date *date) {
	if (this->day == date->day && this->month == date->month && this->year == date->year)
		return true;
	else
		return false;
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
