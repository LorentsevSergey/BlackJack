#pragma once
#include <qpixmap.h>
#include <list>
//#include <memory>
#include "Card.h"

class Deck
{
	std::list<Card> _cards;

public:
	Deck(const std::string);

	const Card take_card();
	void put_card(const Card);
};


