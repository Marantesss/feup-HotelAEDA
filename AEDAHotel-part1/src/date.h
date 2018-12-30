#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Date Class
/**
 *  A class used to represent a date.
 *
 *  Each date object has a day, a month a year a season and a weekday.
 */
class Date {

	/**
	 * int day The date's day
	 */
	int day;

	/**
	 * int month The date's month
	 */
	int month;

	/**
	 * int year The date's year
	 */
	int year;

	/**
	 * string season The date's season
	 */
	string season;

	/**
	 * string weekday The date's weekday
	 */
	string weekday;

public:
	/**
	 * @brief Default constructor.
	 */
	Date();

	/**
	 * @brief Constructor.
	 *
	 * The constructor creates an Employee object with the data passed as argument.
	 *
	 * @param day The date's day.
	 *
	 * @param month The date's month.
	 *
	 * @param year The date's year.
	 */
	Date(int day, int month, int year);

	/**
	 * @brief Default destructor.
	 */
	~Date(){}

	/**
	 * @brief Member function to get the date's day.
	 *
	 * @return The date's day.
	 */
	int getDay() const;

	/**
	 * @brief Member function to get the date's month.
	 *
	 * @return The date's month.
	 */
	int getMonth() const;

	/**
	 * @brief Member function to get the date's year.
	 *
	 * @return The date's year.
	 */
	int getYear() const;

	/**
	 * @brief Member function to get the date's season.
	 *
	 * @return The date's season.
	 */
	string getSeason() const;

	/**
	 * @brief Member function to get the date's weekday.
	 *
	 * @return The date's weekday.
	 */
	string getWeekday() const;

	/**
	 * @brief Member function to get the date's information.
	 *
	 * @return The date's information.
	 */
	string getInfo() const;
	
	/**
	 * @brief Member function to change the date's day.
	 *
	 * @param day The date's new day.
	 */
	void setDay(int day);

	/**
	* @brief Member function to change the date's month.
	*
	* @param month The date's new month.
	*/
	void setMonth(int month);

	/**
	 * @brief Member function to change the date's year.
	 *
	 * @param year The date's new year.
	 */
	void setYear(int year);

	/**
	 * @brief Member function to change the date's date (D M Y).
	 *
	 * @param date The date's new date (D M Y).
	 */
	void setDate(string &date);

	/**
	 * @brief Member function to change the date's season.
	 *
	 * @param season The date's new season.
	 */
	void setSeason(string season);

	/**
	 * @brief Member function to change the date's weekday.
	 *
	 * @param weekday The date's new weekday.
	 */
	void setWeekday(string weekday);

	/**
	 * @brief Member function to show the date.
	 *
	 * @return The date in format DD/MM/YYYY.
	 */
	string showDate() const;

	/**
	 * @brief Member function to show the date.
	 *
	 * @return The date in format "day month year".
	 */
	string showExtendedDate() const;

	/**
	 * @brief Member function to increment the date.
	 *
	 * @return The incremented date.
	 */
	Date operator ++(); // prefix

	/**
	 * @brief Member function to increment the date.
	 *
	 * @return The initial date.
	 */
	Date operator ++(int); // postfix

	/**
	 * @brief Member function to decrement the date.
	 *
	 * @return The decremented date.
	 */
	Date operator --(); // prefix

	/**
	 * @brief Member function to decrement the date.
	 *
	 * @return The initial date.
	 */
	Date operator --(int); // postfix

	/**
	 * @brief Member function to copy the date.
	 *
	 * @param date The date that is going to be copied
	 *
	 * @return The copied date.
	 */
	Date operator =(Date date);

	/**
	 * @brief Member function to check if two dates are equal.
	 *
	 * @param date The date that is being compared
	 *
	 * @return True if two dates have the same day, month and year, false otherwise.
	 */
	bool operator ==(Date date);

	/**
	 * @brief Member function to check if a date is earlier than another.
	 *
	 * @param date The date that is being compared to
	 *
	 * @return True if the first date is realier than the one passed as an argument, false otherwise.
	 */
	bool operator < (Date date);
};


// InvalidDate exception
/**
 *  A class used to represent an exception.
 *
 *  The exception object contains the invalid date.
 */
class InvalidDate {
	/**
	* int id The InvalidDate's day.
	*/
	int day;

	/**
	 * int id The InvalidDate's month.
	 */
	int month;

	/**
	 * int id The InvalidDate's year.
	 */
	int year;

public:
	/**
	 * @brief Constructor.
	 *
	 * The constructor creates a InvalidDate object with the supplied day, month and year.
	 *
	 * @param day The day of the InvalidDate.
	 *
	 * @param month The month of the InvalidDate.
	 *
	 * @param year The year of the InvalidDate.
	 */
	InvalidDate(int day, int month, int year);

	/**
	 * @brief Member function to get the object's day.
	 *
	 * @return The day that originated the creation of this object.
	 */
	int getDay();

	/**
	 * @brief Member function to get the object's month.
	 *
	 * @return The month that originated the creation of this object.
	 */
	int getMonth();

	/**
	 * @brief Member function to get the object's year.
	 *
	 * @return The year that originated the creation of this object.
	 */
	int getYear();
};

#endif /* DATE_H_ */
