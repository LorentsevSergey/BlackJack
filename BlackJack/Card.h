#pragma once
#include "Global.h"

class Card
{
	std::string _front_img_url;
	std::shared_ptr<std::string> _p_back_img_url;
	Suit _suit;
	Value _value;
	bool _is_front_side{ true };

public:
	// string: url to the front image in recource file
	// shared_ptr<string>: pointer to the back image url (one image for all cards in the deck)
	// Suit: spade = 0, heart = 1, diamond = 2, club = 3, noSuit = 4
	// Value: 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king, ace, joker, noValue
	Card(std::string,
		std::shared_ptr<std::string> = nullptr,
		const Suit = noSuit,
		Value = noValue);

	//Card(const std::string& front_img_url,
	//	std::shared_ptr<QPixmap>& back_img,
	//	const Card::Suit& suit = nosuit,
	//	const int cost = 0);
	//
	//const Suit& MySuit() const;
	//const Value& Val() const;

	operator Suit() const;
	operator Value() const;

	const char* ImgUrl() const;
	void TurnOver();

	bool operator==(const Card& other) const;
	Card& operator=(const Card& copy);
};

