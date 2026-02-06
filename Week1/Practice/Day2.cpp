#include "Day2.h"
#include <string>
#include <Console.h>
#include <Input.h>
#include "Player.h"

//
// Part B-1.2: Add a method definition for GetLights
//

void Day2::GetLights(std::vector<Target>& lightGrid)
{
	const int numberOfColumns = 48;
	const int numberOfRows = 48;
	for (int row = 0; row < numberOfRows; row++)
	{
		for (int col = 0; col < numberOfColumns; col++)
		{
			Target target;

			target.col = col;
			target.row = row;
			target.red = rand() % 256;
			target.green = 0;// rand() % 256;
			target.blue = 0;// rand() % 256;

			lightGrid.push_back(target);
		}
	}
}



//
// Part B-2.2: Add a method definition for DrawLights
//
void Day2::DrawLights(const std::vector<Target>& lights, const Map& map) const
{
	for (int i = 0; i < lights.size(); i++)
	{
		const Target& target = lights[i];
		map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
	}

	for (auto& target : lights)
	{
		map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
	}

	for (std::vector<Target>::const_iterator iter = lights.begin(); iter != lights.end(); iter++)
	{
		map.DrawCell(iter->col, iter->row, iter->red, iter->green, iter->blue);
	}

}

//
// Part B-3.2: Add a method definition for EraseLights
//
void Day2::EraseLights(std::vector<Target>& lights) const
{
	//subtract from the loop variable after erasing
	for (int i = 0; i < lights.size(); i++)
	{
		if (lights[i].red < 100)
		{
			lights.erase(lights.begin() + i);
			--i;
		}
	}

	////ONLY increment the loop if you don't erase
	//
	//for (int i = 0; i < lights.size(); )
	//{
	//	if (lights[i].red < 100)
	//	{
	//		lights.erase(lights.begin() + i);
	//	}
	//	else
	//		i++;
	//}

	////reverse for loop
	//for (int i = lights.size() - 1; i >= 0; i--)
	//{
	//	if (lights[i].red < 100)
	//	{
	//		lights.erase(lights.begin() + i);
	//	}
	//}

	//for (std::vector<Target>::iterator iter = lights.begin(); iter != lights.end(); )
	//{
	//	if (iter->red < 100)
	//	{
	//		iter = lights.erase(iter);
	//	}
	//	else
	//		iter++;
	//}

}


void Day2::PartB_1()
{
	day2Name = "Day2_PG2_2602";

	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-1"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-1 Goal: Pass by reference", ConsoleColor::Green);
		Console::WriteLine("Write a method called GetLights to fill the vector with Target objects.");
		Console::WriteLine("\t there should be 48 rows with 48 Target objects per row.");
		Console::WriteLine("\t Give each target a random color.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);


		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			for (auto& target : lights)
			{
				map.DrawCell(target.col, target.row, target.red, target.green, target.blue);
			}

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day2::PartB_2()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-2"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-2 Goal: const parameters", ConsoleColor::Green);
		Console::WriteLine("Write a method called DrawLights to call DrawCell for each Target.");
		Console::WriteLine("\t NOTE: pass the vector and engine by reference AND as const.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);

		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			//
			// Part B-2.3: call DrawLights
			//
			DrawLights(lights, map);

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}

void Day2::PartB_3()
{
	//Screen dimension constants
	const int SCREEN_WIDTH = 480;
	const int SCREEN_HEIGHT = 480;

	srand(static_cast<unsigned int>(time(NULL)));

	PG2Graphics engine(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!engine.Init("Part B-3"))
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		Console::WriteLine("Part B-3 Goal: erasing in a loop", ConsoleColor::Green);
		Console::WriteLine("Write a method called EraseLights. Pass the 'lights' variable to it.");
		Console::WriteLine("\tInside the method, erase any light whose red value is less than 100.");

		std::vector<Target> lights;
		//
		// Part B-1.3: call GetLights
		//
		GetLights(lights);

		//
		// Part B-3.3: call EraseLights
		//
		EraseLights(lights);


		Map map(engine.Renderer(), 10);

		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

			engine.ClearScreen(0, 0, 0, 0xFF);

			//
			// Part B-2.3: call DrawLights
			//
			DrawLights(lights, map);

			//Update screen
			engine.Present();
		}
	}
	engine.Close();
}
