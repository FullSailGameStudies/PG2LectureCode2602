#pragma once
#include <string>
#include <fstream>

struct SubTexture
{
	std::string name;
	int x, y, width, height;

	SubTexture(const std::string& csv, char delim)
	{
		DeserializeCSV(csv, delim);
	}
	//add a Deserialize method to load a subtexture
	void DeserializeCSV(const std::string& csv, char delim);

	//add a Serialize method to save a subtexture
	void SerializeCSV(std::ofstream& out, char delim) const;
};