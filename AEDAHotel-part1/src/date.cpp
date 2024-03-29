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

string calculateWeekday(int day, int month, int year) {
	int s = year / 100; // two first digits of the year
	int a = year % 100; // two last digits of the year
	int c = getCCode(month, isLeap(year));
	switch ((((5 * a) / 4) + c + day - (2 * (s % 4)) + 7) % 7) {
	case 0:
		return "Saturday";
		break;
	case 1:
		return "Sunday";
		break;
	case 2:
		return "Monday";
		break;
	case 3:
		return "Tuesday";
		break;
	case 4:
		return "Wednesday";
		break;
	case 5:
		return "Thursday";
		break;
	case 6:
		return "Friday";
		break;
	}
	return NULL;
}

bool validDate(int day, int month, int year) {
	if (month < 1 || month > 12) return false;
	if (year < 1900) return false;
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
		this->weekday = calculateWeekday(day, month, year);
	}
}

// get

void Date::getCurrentDate() {
	/* current date/time based on current system */
	/* LocalTime for MinGW compiler */
	time_t now = time(0);
	tm* ltm = localtime(&now);

	/* LocalTime for Microsoft Visual Studio compiler */
	/*time_t now = time(0);
	tm *ltm = new tm() ;
	localtime_s(ltm,&now);*/

	Date currentDate = Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
	(*this) = currentDate;

}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

string Date::getSeason() const {
	return this->season;
}

string Date::getWeekday() const {
	return this->weekday;
}

string Date::getInfo() const {
	stringstream ss;
	ss << day << "/" << month << "/" << year << " - " << weekday;
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

void Date::setDate(string &date) { // (D M Y)
	string delimiter = " ";
	int data[3], counter = 0;
	size_t pos = 0;
	string token;
	while ((pos = date.find(delimiter)) != string::npos) {
		token = date.substr(0, pos);
		data[counter] = atoi(token.c_str());
		counter++;
		date.erase(0, pos + delimiter.length());
	}
	this->setDay(data[0]);
	this->setMonth(data[1]);
	this->setYear(data[2]);
}

void Date::setSeason(string season) {
	this->season = season;
}

void Date::setWeekday(string weekday) {
	this->weekday = weekday;
}

string Date::getExtendedDate() const {
	stringstream ss;
	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	ss << this->day << " " << monthName[this->month - 1] << " " << this->year << " - " << this->weekday;
	return ss.str();
}

// calculating adjacent dates
void nextDate(Date &d) {
	int day = d.getDay();
	int month = d.getMonth();
	int year = d.getYear();

	// Adding one day
	if (validDate(day + 1, month, year)) {
		d.setDay(day + 1);
		d.setWeekday(calculateWeekday(d.getDay(), d.getMonth(), d.getYear()));
		return;
	}
	// Adding one month
	if (validDate(1, month + 1, year)) {
		d.setDay(1);
		d.setMonth(month + 1);
		d.setWeekday(calculateWeekday(d.getDay(), d.getMonth(), d.getYear()));
		return;
	}
	// Adding one year
	if (validDate(1, 1, year + 1)) {
		d.setDay(1);
		d.setMonth(1);
		d.setYear(year + 1);
		d.setWeekday(calculateWeekday(d.getDay(), d.getMonth(), d.getYear()));
		return;
	}
}

void previousDate(Date &d){
	int day = d.getDay();
	int month = d.getMonth();
	int year = d.getYear();

	// Minus one day
	if (validDate(day - 1, month, year)) {
		d.setDay(day - 1);
		return;
	}
	// minus one month
	if (validDate(31, month + 1, year)) {
		d.setDay(31);
		d.setMonth(month - 1);
		return;
	}
	else if (validDate(30, month + 1, year)) {
		d.setDay(30);
		d.setMonth(month - 1);
		return;
	}
	else if (validDate(29, month + 1, year)) {
		d.setDay(29);
		d.setMonth(month - 1);
		return;
	}
	else if (validDate(28, month + 1, year)) {
		d.setDay(28);
		d.setMonth(month - 1);
		return;
	}
	// Minus one year
	if (validDate(31, 12, year - 1)) {
		d.setDay(31);
		d.setMonth(12);
		d.setYear(year - 1);
		return;
	}
}


// Operators
Date Date::operator ++() { // prefix
	nextDate(*this);
	return *this;
}

Date Date::operator ++(int) { // postfix
	Date d = *this;
	nextDate(*this);
	return d;
}

Date Date::operator --() { // prefix
	previousDate(*this);
	return *this;
}

Date Date::operator --(int) { // postfix
	Date d = *this;
	previousDate(*this);
	return d;
}

bool Date::operator ==(Date date) {
	if (this->day == date.day && this->month == date.month && this->year == date.year)
		return true;
	else
		return false;
}

Date Date::operator =(Date date) {
	this->setDay(date.getDay());
	this->setMonth(date.getMonth());
	this->setYear(date.getYear());
	this->setSeason(date.getSeason());
	this->setWeekday(date.getWeekday());
	return *this;
}

bool Date::operator < (Date date) const {
	// check year
	if (this->getYear() < date.getYear()) {
		return true;
	}
	else if (this->getYear() == date.getYear()) {
		// check month
		if (this->getMonth() < date.getMonth()) {
			return true;
		}
		else if (this->getMonth() == date.getMonth()) {
			// check day
			if (this->getDay() < date.getDay())
				return true;
		}
	}
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
