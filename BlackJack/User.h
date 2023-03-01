#pragma once
#include "Global.h"
#include "Card.h"

class User
{
	UsrType _type;
	int _score{ 0 };

protected:
	std::vector<Card> _my_cards;

public:
	User(UsrType);

	void AddCard(Card);
	std::vector<Card> GetCards() const;
	std::vector<const char*> GetImgsUrl() const;
	void DelCards();

	int GetScore() const;
	void CalcScore(std::function<void(int&, std::vector<Card>)>);
	void SetScore(int);
};

