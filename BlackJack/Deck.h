#pragma once
#include <list>
#include "Card.h"

class Deck
{
public:
	std::vector<Card> _cards;

	Deck(const std::string);

	std::list<Card*> GetCards();
};


