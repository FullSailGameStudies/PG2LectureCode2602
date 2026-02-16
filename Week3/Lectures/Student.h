#pragma once
#include <string>
class Student
{
public:
	//constructors (ctor)
	// used to initialize the object when you create the object
	// ALL classes have at least 1 ctor
	// can have as many as needed
	// can be public, private, protected
	// ctors are the ONLY way to create an instance of the class
	//  IF you do NOT create a ctor, visual studio will give you 
	//		a default ctor
	//	a default ctor: has NO parameters
	//	IF you create a ctor, VS's ctor is not longer created 
	//  RULES:
	//		MUST be named the same as the class
	//		CANNOT have a return type (not even void)
	//Student(const std::string& name)
	//{
	//	name_ = name;
	//	grade_ = 0;
	//}
	// use the member initialization list to initialize the fields
	Student(const std::string& name, float grade = 0) :
		name_(name),
		grade_(grade)
	{
		name_ = name;
		grade_ = grade;
	}

	//getters (accessors)
	//  normally const (not changing the object)
	//  no params
	//  return type matches the type of the field
	const std::string& GetName() const { return name_; }
	float Grade() const { return grade_; }

	//setters (mutators)
	//  return type is usually void
	//  usually 1 parameter to match the type of the field
	//  can have some validation logic to prevent invalid states
	//  NON-const
	void SetName(const std::string& name)
	{
		//validation logic
		if (!name.empty() && name.size() < 64)
		{
			name_ = name;
		}
	}
	void Grade(float grade)
	{
		if (grade >= 0 && grade <= 100)
			grade_ = grade;
	}

private:
	//fields (data member or member variables)
	std::string name_;
	float grade_;

	//std::string& program_;
};

