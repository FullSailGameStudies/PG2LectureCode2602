#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include <Console.h>
#include <Input.h>

//pass by value
//  making a copy of the original

//pass by reference
//	makes an alias (no copy)
void PrintMe(double& dVal)
{
	dVal *= 2;
	std::cout << dVal << "\n";
}

int main(int argc, char* args[])
{
	double dVal = 12.5;
	double& dRef = dVal;//points dRef to dVal
	double dVal2 = 12.3;
	dRef = dVal2;//copies dVal2 to dVal
	PrintMe(dVal);
	std::cout << dVal << "\n";
	PrintMe(dVal2);

	//rand() - 0 to 32767
	//color ranges - 0 to 255
	// x % num - divides x by num and returns the remainder
	int color = rand() % 256;


	Day2 day2;
	day2.SetName("Steev's Code");
	std::cout << day2.GetName() << "\n";
	const Day2 cDay2;
	cDay2.GetName();

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1.0: Calling static methods",
		"2. Part A-1.1: calling non-static methods",
		"3. Part A-1.2: calling non-static methods",
		"4. Part A-1.3: calling non-static methods",
		"5. Part A-1.4: Return Values",
		"6. Part A-1.5: Passing arguments",
		"7. Part A-2: Creating methods\n",
		"8. Part B-1: Pass by reference",
		"9. Part B-2: Const",
		"10. Part B-3: Erasing in a loop\n",
		"11. Part C-1: Default Parameters",
		"12. Part C-2: Copying Vectors\n",
		"13. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			//
			// part A-1.0: calling methods on the Console class to print messages.
			//
			//	Use Console::Write and Console::WriteLine to print several lines of text (whatever you want to say)
			//  Experiment with changing the colors.
			//  Open the Console.h file (look in Misc/Console in Solution Explorer) to see how the methods are declared.
			//
			Console::Write("Hello Pg2: ");
			Console::WriteLine("Day01", ConsoleColor::Cyan);
			break;
		}
		case 2:
		{
			Day1::PartA_1_1();
			break;
		}
		case 3:
		{
			Day1::PartA_1_2();
			break;
		}
		case 4:
		{
			Day1::PartA_1_3();
			break;
		}
		case 5:
		{
			//
			// part A-1.4: Getting return values
			//	Ask the user to enter their name. Print the name.
			// 
			//	Open Lectures.cpp.
			//	Add code before the switch to call Input::GetString.
			//	Store the result in a string variable.
			//	Print the name that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetString is declared.
			//
			std::string name = Input::GetString("What is your name?");
			//std::cout << "You entered " << name << "\n";
			Console::WriteLine("You entered " + name);
			break;
		}
		case 6:
		{
			//
			// part A-1.5: passing arguments
			//	Ask the user for their age. A minimum age would be 0 and a maximum age would be 120.
			// 
			//	Open Lectures.cpp.
			//	Add code before the switch to call Input::GetInteger.
			//	Store the result in an int variable.
			//	Print the age that the user enters.
			//	Open the Input.h file(look in Misc / Input in Solution Explorer) to see how the GetInteger is declared.
			//
			int age = Input::GetInteger("What is your age?", 0, 150);
			//std::cout << "Your age is " << age << "\n";
			Console::WriteLine("Your age is " + std::to_string(age));
			break;
		}
		case 7:
		{
			Day1::PartA_2();
			break;
		}
		case 8:
		{
			day2.PartB_1();
			break;
		}
		case 9:
		{
			day2.PartB_2();
			break;
		}
		case 10:
		{
			day2.PartB_3();
			break;
		}
		case 11:
		{
			Day3::PartC_1();
			break;
		}
		case 12:
		{
			Day3::PartC_2();
			break;
		}
		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}

