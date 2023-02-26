#pragma once
#include "Card.h"

Card::Card(std::string front_img_url,
	std::shared_ptr<std::string> p_back_img_url,
	const Suit suit,
	Value value)
	:
	_front_img_url(front_img_url),
	_p_back_img_url(p_back_img_url),
	_suit(suit),
	_value(value)
{}

//Card::Card(const std::string& front_img_url,
//	std::shared_ptr<QPixmap>& back_img,
//	const Card::Suit& suit,
//	const int cost)
//	:
//	_front_img(front_img_url.c_str()),
//	_p_back_img(back_img),
//	_suit(suit),
//	_cost(cost)
//{};
//
//const Card::Suit& Card::MySuit() const
//{
//	return _suit;
//}
//
//const Card::Value& Card::Val() const
//{
//	return _value;
//}

Card::operator Suit() const
{
	return _suit;
}

Card::operator Value() const
{
	return _value;
}

const char* Card::ImgUrl() const
{
#ifdef DEBUG
	assert(_front_img_url.size() && "Empty adress of card image.");
#endif

	return (_is_front_side ? _front_img_url : *_p_back_img_url).c_str();
}

void Card::TurnOver()
{
	_is_front_side = !_is_front_side;
}
