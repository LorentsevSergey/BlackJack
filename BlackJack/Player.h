#pragma once
#include "User.h"

class Player :
    public User
{
    int _cash{ 0 };
    int _bet{ 0 };

public:
    Player(int);

    int GetCash() const;
    //void SetCash(int);

    int GetBet();
    int SetBet(int);
    void Win();
    void Loose();
};

