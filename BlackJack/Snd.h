#pragma once
#include "mPlayer.h"

class Snd 
{
    mPlayer backgroundPlayer;
    mPlayer cardPlayer;
    mPlayer setBetPlayer;
    mPlayer winBetPlayer;

public:
    Snd();

    enum Track_type{
        BackgroundMusic,
        GetCard,
        SetBet,
        WinBet
    };

    void PlaySnd(Snd::Track_type);
    void NextBackgroundSnd();
    void PauseBackgroundSnd();
};

