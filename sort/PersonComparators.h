#pragma once

#include "Person.h"

namespace PersonComparators
{
	int compare(char lhs, char rhs);
	int compare(std::string lhs, std::string rhs);

#define COMPARATOR(Name)\
	struct Name\
	{\
		bool operator () (const Person& lhs, const Person& rhs) const;\
	};

	COMPARATOR(ID);
	COMPARATOR(FirstName);
	COMPARATOR(SecondName);
	COMPARATOR(Birth);

#undef COMPARATOR
};