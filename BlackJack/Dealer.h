#pragma once
#include "User.h"

class Dealer :
    public User
{
public:
    Dealer() : User(dealer) {};
    // 0 - shirt; 1 - face
    void TurnOverShirtCard(bool side);
    int GetSecondCardID();
};

