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
	int GetCardsCount() const;
	std::vector<Card> GetCards() const;
	//std::vector<int> GetImgsID() const;
	void DelCards();

	int GetScore() const;
	void CalcScore(std::function<void(int&, std::vector<Card>)>);
	void SetScore(int);

	operator UsrType() const;
};

