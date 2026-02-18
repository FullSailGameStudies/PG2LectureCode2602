#pragma once
#include <string>
class Card
{
public:

	Card(const std::string& face, const std::string& suit)
		: face_(face), suit_(suit)
	{
	}

	void Print() const;
	int Value() const;

	const std::string& Face() const { return face_; }
	void Face(const std::string& face) {
		face_ = face;
	}
	const std::string& Suit() const { return suit_; }
	void Suit(const std::string& suit) {
		suit_ = suit;
	}

private:
	//
	// Card HAS-A face and suit
	// Composition of the class
	std::string face_, suit_;
};

