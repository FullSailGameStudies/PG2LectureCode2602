#pragma once
#include <string>
class Person
{
public:
	Person(const std::string& name, int age)
		: name_(name), age_(age)
	{
	}

	const std::string& Name() const { return name_; }
	void Name(const std::string& name)
	{
		//validation logic
		if (!name.empty() && name.size() < 64)
		{
			name_ = name;
		}
	}

	int Age() const { return age_; }
	void Age(int age)
	{
		if (age >= 0 && age <= 130)
		{
			age_ = age;
		}
	}

private:
	std::string name_;
	int age_;
};

