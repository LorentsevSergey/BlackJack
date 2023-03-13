#pragma once
#include "Card.h"

class Deck
{
	std::vector<Card> cards;
public:
	Deck();

	const Card RandCard();
	void AddCard(Card&);
};


