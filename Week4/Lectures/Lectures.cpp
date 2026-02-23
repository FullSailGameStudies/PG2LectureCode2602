#include <iostream>
#include "Console.h"
#include "Day10.h"
#include "Day11.h"
#include "Input.h"
#include <fstream> //for ifstream, ofstream
#include <sstream> //for stringstream


int main(int argc, char* args[])
{
	std::string fileName = "2602.csv";
	std::string path = "C:/temp/2602/";
	std::string finalPath = path + fileName;
	//1. open the file
	//	check if the file is open
	std::ofstream outFile(finalPath);
	char delimiter = '$';
	if (outFile.is_open())
	{
		//2. write to the file
		//  << insertion operator
		outFile << "Batman rules!" << delimiter;
		outFile << 12 << delimiter << 5.371 << delimiter << true;
		outFile << delimiter << "Aquaman smells.";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3. CLOSE the file
	//	good programming practice: close the file ASAP!
	outFile.close();

	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		//check the inFile.eof()
		// eof - end of file
		// 
		//2. read from the file
		//  << insertion operator
		// 	
		std::string line;
		//reads the infile UNTIL it reaches 
		// a newline OR the end of the file
		std::getline(inFile, line);
		std::cout << line << "\n";
		//parse the string
		std::string data;
		std::stringstream lineStream(line);
		//reads the stream UNTIL it reaches 
		// a delimiter OR the end of the stream
		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		std::getline(lineStream, data, delimiter);
		int iData = std::stoi(data);
		std::cout << iData << "\n";

		std::getline(lineStream, data, delimiter);
		double dData = std::stod(data);
		std::cout << dData << "\n";

		try
		{
			std::getline(lineStream, data, delimiter);
			bool bData = std::stoi(data);
			std::cout << bData << "\n";
		}
		catch (const std::exception& ex)
		{
			std::cout << "Error processing the boolean\n";
			std::cout << "DATA: " << data << "\n";
			std::cout << ex.what() << "\n";
		}		//try-catch

		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3. CLOSE the file
	//	good programming practice: close the file ASAP!
	inFile.close();


    std::string hello = "Hello Week 4!";
    for (auto& ch : hello)
    {
        Console::Write(ch, (ConsoleColor)(rand() % 7 + 1));
    }
    std::cout << "\n";

	int menuSelection = 0;
	std::vector<std::string> menuOptions{
		"1. Part A-1: Read CSV file",
		"2. Part A-2: Write CSV file",
		"3. Part B: Serialize/Deserialize objects",
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
			Day10::PartA_1();
			break;
		}
		case 2:
		{
			Day10::PartA_2();
			break;
		}
		case 3:
		{
			Day11::PartB();
			break;
		}

		}

		Input::PressEnter();
	} while (menuSelection != menuOptions.size());

	return 0;
}