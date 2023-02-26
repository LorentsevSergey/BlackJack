#pragma once
#include "Player.h"

Player::Player(unsigned cash) : 
	User(player)
{
#ifdef DEBUG
	assert(cash > 0 && cash < 10001 && "Player start cash out of a range.");
#endif // DEBUG

	_cash = cash;
}

unsigned Player::GetCash() const
{
	return _cash;
}

void Player::SetCash(unsigned cash)
{
#ifdef DEBUG
	assert(cash > 0 && cash < 10001 && "Player set cash out of a range.");
#endif // DEBUG

	_cash = cash;
}