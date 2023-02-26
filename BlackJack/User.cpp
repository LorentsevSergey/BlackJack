#pragma once
#include "User.h"

User::User(UsrType type) : 
	_type(type) {}

void User::AddCard(Card card)
{
	_my_cards.push_back(card);
}

std::vector<Card> User::GetCards() const
{
	return _my_cards;
}

std::vector<const char*> User::GetImgsUrl() const
{
	std::vector<const char*> imgs_url;
	for (size_t i = 0; i < _my_cards.size(); ++i)
		imgs_url.push_back(_my_cards[i].ImgUrl());		
	return imgs_url;
}

void User::DelCards()
{
	std::vector<Card> empty;
	_my_cards.swap(empty);
}

