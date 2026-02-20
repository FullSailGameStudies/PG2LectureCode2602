#include "Employee.h"
#include <iostream>
void Employee::WhoAmI()
{
	Person::WhoAmI();

	std::cout << "\tAnd my job is " << role_ << "\n";

}