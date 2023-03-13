#pragma once
#include "Card.h"

Card::Card(int f_img_id, Suit suit, Value value)
	:
	face_img_id(f_img_id),
	suit(suit),
	value(value)
{}


Card::operator Suit() const
{
#ifdef DEBUG
	assert(face_img_id && "Empty card.");
#endif
	return suit;
}

Card::operator Value() const
{
#ifdef DEBUG
	assert(face_img_id && "Empty card.");
#endif
	return value;
}

//Card::operator int() const
//{
//#ifdef DEBUG
//	assert(face_img_id && "Empty card.");
//#endif
//	return is_face ? face_img_id : CARD_ID_BACK;
//}

int Card::ImgID() const
{
#ifdef DEBUG
	assert(face_img_id && "Empty card.");
#endif

	return is_face ? face_img_id : CARD_ID_BACK;
}

void Card::TurnOver(bool side)
{
	is_face = side;
}


#pragma region OPERATORS
bool Card::operator>(const Card& other) const
{
	return value > other.value;
}

//bool Card::operator<(const Card& other) const
//{
//	return value < other.value;
//}

bool Card::operator==(const Card& other) const
{
	return face_img_id == other.face_img_id
		&& suit == other.suit
		&& value == other.value
		&& is_face == other.is_face;
}

Card& Card::operator=(const Card& copy)
{
	face_img_id = copy.face_img_id;
	suit = copy.suit;
	value = copy.value;
	is_face = copy.is_face;
	return *this;
}
#pragma endregion

bool operator==(const Card& card, Value val)
{
	return  card.value == val;
}
