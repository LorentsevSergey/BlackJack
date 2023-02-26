#pragma once
#include "Global.h"
#include "Card.h"

class Deck
{
	std::vector<Card> _cards;
public:
	Deck(const std::string);
	const Card RandCard() const;
};


