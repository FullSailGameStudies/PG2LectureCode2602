#include "SubTexture.h"
#include <sstream>

//load the object data
void SubTexture::DeserializeCSV(const std::string& line, char delim)
{
	std::stringstream lineStream(line);
	std::getline(lineStream, name, delim);

	std::string data;
	std::getline(lineStream, data, delim);
	x = std::stoi(data);

	std::getline(lineStream, data, delim);
	y = std::stoi(data);

	std::getline(lineStream, data, delim);
	width = std::stoi(data);

	std::getline(lineStream, data, delim);
	height = std::stoi(data);
}

//saving an object
void SubTexture::SerializeCSV(std::ofstream& out, char delim) const
{
	out << name << delim << x << delim << y;
	out << delim << width << delim << height;
}
