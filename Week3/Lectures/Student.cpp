#include "Student.h"
#include <iostream>

void Student::WhoAmI()
{
	//what level to override?
	//FULL override:
	//	all new behavior (don't call the base)
	// 
	//EXTENSION override:
	//	add on to the base behavior (call the base)
	Person::WhoAmI();

	std::cout << "\tAnd my GPA is " << GPA_ << "\n";

}
