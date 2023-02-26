#pragma once
#include "Global.h"
#include "User.h"

class Player :
    public User
{
    unsigned _cash = 0;
public:
    Player(unsigned);
    unsigned GetCash() const;
    void SetCash(unsigned);
};

