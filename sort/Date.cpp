#include "Date.h"

Date::Date(int year, int month, int day)
	: year{ year }
	, month{ month }
	, day{ day }
{}

int Date::compare(const Date& rhs) const
{
	if (year != rhs.year) {
		return year < rhs.year ? -1 : 1;
	}
	if (month != rhs.month) {
		return month < rhs.month ? -1 : 1;
	}
	if (day != rhs.day) {
		return day < rhs.day ? -1 : 1;
	}
	return 0;
}

std::ostream& operator << (std::ostream& os, const Date& date)
{
	return os
		<< date.year << "."
		<< date.month << "."
		<< date.day;
}