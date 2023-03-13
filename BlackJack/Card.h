#pragma once
#include "Global.h"

class Card
{
	int face_img_id;
	Suit suit;
	Value value;
	bool is_face{ true };

public:
	// id of img url in Img object
	// Suit: spade, heart, diamond, club, noSuit
	// Value: 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king, ace, joker, noValue
	Card(int = 0, Suit = noSuit, Value = noValue);

	//explicit operator int() const;
	operator Suit() const;
	operator Value() const;

	int ImgID() const;

	// false - shirt
	// true - face
	void TurnOver(bool side);

	bool operator>(const Card& other) const;
	//bool operator<(const Card& other) const;

	bool operator==(const Card& other) const;
	Card& operator=(const Card& copy);

private:
	friend bool operator==(const Card& card, Value val);
};

