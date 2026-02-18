#pragma once
#include <vector>
#include "Card.h"

class Deck
{
public:
	virtual ~Deck();

	bool HasCards() const;
	Card DealCard();
	void Shuffle();

protected:
	std::vector<Card> cards_;

	void Cleanup();
	virtual void MakeCards();
};

