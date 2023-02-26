#pragma once
#include "Card.h"

class Deck
{
	std::vector<Card> _cards;
public:
	Deck() = delete;
	Deck(const std::string);
	const Card RandCard();
	void AddCard(const Card&);
};


