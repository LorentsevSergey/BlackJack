#pragma once
#include "Player.h"

Player::Player(int cash) :
	User(player)
{
		_cash = cash;
}

int Player::GetCash() const
{
	return _cash;
}

//void Player::SetCash(int cash)
//{
//#ifdef DEBUG
//	assert(cash > MIN_PLAYER_CASH && cash < MAX_PLAYER_CASH && "Player set cash out of a range.");
//#endif
//	_cash = cash;
//}

int Player::GetBet()
{
	return _bet;
}

int Player::SetBet(int bet)
{
	if(bet && bet <= _cash && !_bet)
	{
		_bet = bet;
		_cash -= bet;
	}
	return _bet;
}

void Player::Win()
{
	_cash += _bet * 2;
	_bet = 0;
}

void Player::Loose()
{
	_bet = 0;
}
