#include "Card.h"
#include <iostream>

void Card::Print() const
{
	std::cout << face_ << " " << suit_ << "\n";
}

int Card::Value() const
{
	int value;
	if (face_[0] == 'A') value = 1;
	else if (face_[0] == 'J') value = 11;
	else if (face_[0] == 'Q') value = 12;
	else if (face_[0] == 'K') value = 13;
	else value = std::stoi(face_);
	return value;
}
