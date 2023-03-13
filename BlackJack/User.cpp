#pragma once
#include "User.h"

User::User(UsrType type) : _type(type) {}

int User::GetCardsCount() const
{
	return _my_cards.size();
}

void User::AddCard(Card card)
{
	_my_cards.push_back(card);
}

std::vector<Card> User::GetCards() const
{
	return _my_cards;
}

//std::vector<int> User::GetImgsID() const
//{
//	std::vector<int> imgs_url;
//	for (size_t i = 0; i < _my_cards.size(); ++i)
//		imgs_url.push_back(_my_cards[i].ImgID());		
//	return imgs_url;
//}

void User::DelCards()
{
	std::vector<Card> empty;
	_my_cards.swap(empty);
}


int User::GetScore() const
{
	return _score;
}

void User::CalcScore(std::function<void(int&, std::vector<Card>)> foo) 
{
	foo(_score, _my_cards);
}

void User::SetScore(int score)
{
	_score = score;
}


User::operator UsrType() const
{
	return _type;
}

