#pragma once
#include "Person.h"
class Student : public Person
{
public:
	//my ctor MUST call a base CTOR using the
	// member initialization list
	Student(const std::string& name, int age, float gpa) :
		Person(name,age),
		GPA_(gpa)
	{

	}

	//2. add a new method with the same signature
	//		as the base method
	//	OPTIONAL: add the 'override' keyword
	void WhoAmI();

	float GPA() const { return GPA_; }
	void GPA(float gpa)
	{
		if (gpa >= 0 && gpa <= 4.0)
			GPA_ = gpa;
	}
private:
	float GPA_;
};

