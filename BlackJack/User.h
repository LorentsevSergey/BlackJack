#pragma once
#include "Global.h"
#include "Card.h"

class User
{
	UsrType _type;

protected:
	std::vector<Card> _my_cards;

public:
	User(UsrType);

	void AddCard(Card);
	std::vector<Card> GetCards() const;
	std::vector<const char*> GetImgsUrl() const;
	void DelCards();

};

