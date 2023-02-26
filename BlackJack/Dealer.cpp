#pragma once
#include "Dealer.h"

void Dealer::TurnOverShirtCard()
{
	if(_my_cards.size() >= 2)
		_my_cards[1].TurnOver();
}
