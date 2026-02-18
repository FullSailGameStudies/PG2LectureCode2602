#include "Deck.h"

Deck::~Deck()
{
	Cleanup();
}

bool Deck::HasCards() const
{
	return not cards_.empty();
}

Card Deck::DealCard()
{
	if (!HasCards())
		MakeCards();

	Card card = cards_.back();
	cards_.pop_back();
	return card;
}

void Deck::Cleanup()
{
	//for (int i = 0; i < cards_.size(); i++)
	//{
	//	delete cards_[i];
	//}
	cards_.clear();
}

void Deck::MakeCards()
{
	Cleanup();

	//create the 13 cards for 4 suits
	std::vector<std::string> suits{ "Hearts", "Clubs", "Diamonds", "Spades" };
	std::vector<std::string> faces{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	for (auto& suit : suits)
	{
		for (auto& face : faces)
		{
			cards_.push_back(Card(face, suit));
		}
	}
}

void Deck::Shuffle()
{
	if (!HasCards())
		MakeCards();

	//shuffle the vector of cards
	int index1 = 0, index2 = 0;
	int numberOfSwaps = static_cast<int>(cards_.size() * 3);
	for (size_t i = 0; i < numberOfSwaps; i++)
	{
		index1 = rand() % cards_.size();
		do
		{
			index2 = rand() % cards_.size();
		} while (index2 == index1);
		std::swap(cards_[index1], cards_[index2]);
	}
}
