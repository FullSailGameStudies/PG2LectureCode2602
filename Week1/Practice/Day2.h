#pragma once
#include <vector>
#include "Target.h"
#include "Map.h"
#include <string>

class Day2
{
public:
	void PartB_1();
	void PartB_2();
	void PartB_3();

	const std::string& GetName() const
	{
		std::string otherName = "Bruce Wayne";
		otherName = "Batman";
		return day2Name;
	}
	void SetName(const std::string& name)
	{
		day2Name = name;
	}

private:
	std::string day2Name;
	//
	// Part B-1.1: Add a method declaration for GetLights
	//
	void GetLights(std::vector<Target>& lights);

	//
	// Part B-2.1: Add a method declaration for DrawLights
	//
	void DrawLights(const std::vector<Target>& lights,const Map& map) const;

	//
	// Part B-3.1: Add a method declaration for EraseLights
	//

};

