#pragma once

#include <string>
#include <ostream>
#include "Date.h"

struct Person final
{
	size_t id;
	std::string firstName;
	std::string secondName;
	Date birth;

	Person(size_t id, std::string firstName, std::string secondName, Date birth);

	friend std::ostream& operator << (std::ostream& os, const Person& person);
};