#pragma once
#include "User.h"

class Dealer :
    public User
{
public:
    Dealer() : User(dealer) {};

    void TurnOverShirtCard();
};

