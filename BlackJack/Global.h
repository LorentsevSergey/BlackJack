#pragma once
#include <memory>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

#define DEBUG
#define CARD_ID_START (2)
#define CARD_ID_END (15)

enum Suit
{
	spade = 0,
	heart = 1,
	diamond = 2,
	club = 3,
	noSuit = 4
};

enum Value
{
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack = 11,
	queen = 12,
	king = 13,
	ace = 14,
	joker = 15,
	noValue = 16
};

enum UsrType
{
	dealer,
	player
};

// Convert int to string
std::string itos(int val);