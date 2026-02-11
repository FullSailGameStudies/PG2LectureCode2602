#include <iostream>
#include "Console.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <Input.h>
#include <map>

//recursive loop
void SomeMethod(int number=0)
{	
	if (number >= 200) return ;//exit condition (base case)
	//if(number < 200)
	{
		std::cout << "Some Method " << number << "\n";
		SomeMethod(number + 1);//recursive
	}
}

int main(int argc, char* args[])
{
	SomeMethod();
	srand(static_cast<unsigned int>(time(NULL)));

	std::map<std::string, float> menu;
	//how to add to a map:
	// 1) easy way. map[key] = value;
	menu["pizza"] = 19.99f;
	menu["pasta"] = 15.99f;
	menu["coffee"] = 5.99f;
	menu["water"] = 4.99f;
	menu["water"] = 6.99f;//overwrite any existing value
	// 2) not-easy way 
	//    map.insert(key-valuepair);
	std::pair<std::string, float> pair;
	pair = std::make_pair("bagel", 4.99f);
	menu.insert(pair);
	//pair objects have 2 parts: first and second
	pair.second += 2;
	std::pair<std::map<std::string,float>::iterator,bool> menuInserted = menu.insert(pair);//does NOT overwrite
	if (menuInserted.second == false)
	{
		std::cout << pair.first << " is already on the menu. Do you want to change the price?\n";
	}

	std::string itemToFind = "Dino Nuggies";
	//find returns an iterator to the key-value pair in the map
	std::map<std::string,float>::iterator findResult = menu.find(itemToFind);
	//what does it return if not found? map.end()
	if (findResult == menu.end())
	{
		std::cout << itemToFind << " is not on the menu. Try McDonald's\n";
	}
	else
	{
		//the first is the key
		//the second is the value
		std::cout << "Price: " << findResult->second << "\n";
	}

	std::cout << "\n\nPG2 Cafe\n";
	for (auto menuIter = menu.begin(); menuIter != menu.end(); menuIter++)
	{
		std::cout << menuIter->first << " " << menuIter->second << "\n";
	}

	std::cout << "\n\nPG2 Cafe\n";
	for (auto& item : menu)
	{
		std::cout << item.first << " " << item.second << "\n";
	}

	std::cout << "\n\nPG2 Cafe\n";
	//structured bindings
	for (auto& [itemName, itemPrice] : menu)
	{
		std::cout << itemName << " " << itemPrice << "\n";
	}


	std::string hello = "Hello Week 2!";
	for (auto& ch : hello)
	{
		Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
	}
	std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Recursion Example\n",
		"2. Part A-1.1: Recursion (Bats)",
		"3. Part A-1.2: Recursion (Reverse Word)",
		"4. Part A-1.3: Recursion (Reverse words in a sentence)\n",
		"5. Part A-2: Sorting\n",
		"6. Part B-1: Linear Search\n",
		"7. Part B-2: Maps",
		"8. Part B-3: Find in Maps",
		"9. Part C-1: Erase from Maps",
		"10. Exit" };


	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Day4::RecursionExample();
			break;
		}
		case 2:
		{
			Day4::PartA_1_1();
			break;
		}
		case 3:
		{
			Day4::PartA_1_2();
			break;
		}
		case 4:
		{
			Day4::PartA_1_3();
			break;
		}
		case 5:
		{
			Day4::PartA_2();
			break;
		}
		case 6:
		{
			Day5::PartB_1();
			break;
		}
		case 7:
		{
			Day5::PartB_2(1);
			break;
		}
		case 8:
		{
			Day5::PartB_2(2);
			break;
		}
		case 9:
		{
			Day6::PartC_1();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}