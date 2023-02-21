#pragma once
#include "Card.h"

Card::Card(const std::string& front_img_url,
	std::shared_ptr<QPixmap>& back_img,
	const Card::Suit& suit,
	const int cost)
	:
	_front_img(front_img_url.c_str()),
	_p_back_img(back_img),
	_suit(suit),
	_cost(cost)
{};

Card::Suit Card::MySuit() const
{
	return _suit;
}

int Card::Cost() const
{
	return _cost;
}

Card::operator QPixmap() const
{
	return is_front_side ? _front_img : *_p_back_img;
}

void Card::TurnOver()
{
	is_front_side = !is_front_side;
}
