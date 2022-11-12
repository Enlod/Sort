#pragma once

#include <ostream>

struct Date final
{
	int year;
	int month;
	int day;

	Date(int year, int month, int day);

	int compare(const Date& rhs) const;
	friend std::ostream& operator << (std::ostream& os, const Date& date);
};

