#pragma once
#include "Card.h"
//  is-a relationship
//  BlackjackCard IS-A Card
class BlackjackCard : public Card
{
public:
	BlackjackCard(const std::string& face, const std::string& suit) :
		Card(face,suit)
	{

	}
};

