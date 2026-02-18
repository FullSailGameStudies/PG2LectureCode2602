#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
	int value;
	if (face_[0] == 'A') value = 1;
	else if (face_[0] == 'J' or face_[0] == 'Q' or face_[0] == 'K') value = 10;
	else value = std::stoi(face_);
	return value;
}
