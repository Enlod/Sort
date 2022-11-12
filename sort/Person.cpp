#include "Person.h"

Person::Person(size_t id, std::string firstName, std::string secondName, Date birth)
	: id{ id }
	, firstName{ std::move(firstName) }
	, secondName{ std::move(secondName) }
	, birth{ birth }
{}

std::ostream& operator << (std::ostream& os, const Person& person)
{
	return os
		<< person.id << " "
		<< person.firstName << " "
		<< person.secondName << " "
		<< person.birth;
}