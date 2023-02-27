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


#pragma region Operators > < == =
bool Card::operator>(const Card& other) const
{
	return _value > other._value;
}

bool Card::operator<(const Card& other) const
{
	return _value < other._value;
}

bool Card::operator==(const Card& other) const
{
	return _front_img_url == other._front_img_url
		&& _p_back_img_url == other._p_back_img_url
		&& _suit == other._suit
		&& _value == other._value
		&& _is_front_side == other._is_front_side;
}

Card& Card::operator=(const Card& copy)
{
	_front_img_url = copy._front_img_url;
	_p_back_img_url = copy._p_back_img_url;
	_suit = copy._suit;
	_value = copy._value;
	_is_front_side = copy._is_front_side;
	return *this;
}
#pragma endregion