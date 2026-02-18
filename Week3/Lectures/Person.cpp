#include "Person.h"
#include <iostream>

void Person::WhoAmI()
{
	std::cout << "Hello. I am " << name_;
	std::cout << ". And I am " << age_ << " years old.\n";
}
