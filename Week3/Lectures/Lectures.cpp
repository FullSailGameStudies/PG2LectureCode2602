#include "Console.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Input.h"
#include "Person.h"
#include "Student.h"
#include <Color.h>
#include <iostream>
#include <Weapon.h>

void Counter()
{
	static int i = 0;
	std::cout << i << " ";
	i++;
}
int main(int argc, char* args[])
{
	for (int i = 0; i < 20; i++)
	{
		Counter();
	}
	Person steev("Steve Austin", 75);//creating the object is calling a ctor
	//steev.SetName("Steve Austin");
	//steev.Grade(75);
	std::cout << steev.Name() << ": " << steev.Age() << "\n";

	steev.WhoAmI();

	Student carl("Carl Grimes", 15, 3.0);
	carl.WhoAmI();

	//Weapon wpn(100, 50);

	Color clr{ 255,0,0,255 };
	clr.r = 255;
	clr.a = 255;
	clr.g = clr.b = 0;

	std::string hello = "Hello Week 3!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Create Class",//classes + inheritance + override?
		"2. Part B-1: Inheritance, Polymorphism",//no pointers
		"3. Part C-1: Pointers",//pointers
		"4. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day7::PartA_1();
			break;
		}
		case 2:
		{
			Day8::PartB_1();
			break;
		}
		case 3:
		{
			Day9::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());


	return 0;
}