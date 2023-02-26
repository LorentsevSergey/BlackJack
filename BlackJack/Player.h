#pragma once
#include "User.h"

class Player :
    public User
{
    static const unsigned minCash = 100;
    static const unsigned maxCash = 10000;
    unsigned _cash = 0;

public:
    Player(unsigned);
    unsigned GetCash() const;
    void SetCash(unsigned);
};

