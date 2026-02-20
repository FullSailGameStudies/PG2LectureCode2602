#pragma once
#include "Person.h"
class Employee : public Person
{
public:
	Employee(const std::string& name, int age, const std::string& role) :
		Person(name,age),
		role_(role)
	{

	}
	void WhoAmI() ;
private:
	std::string role_;
};

