#pragma once
#include "Dealer.h"

void Dealer::TurnOverShirtCard(bool side)
{
	if(_my_cards.size() >= 2)
		_my_cards[1].TurnOver(side);
}

int Dealer::GetSecondCardID()
{
	return _my_cards[1].ImgID();
}
