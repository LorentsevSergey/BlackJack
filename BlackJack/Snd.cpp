#pragma once
#include "Snd.h"
#include "Global.h"

Snd::Snd() :
    backgroundPlayer({ 
        "D:/Projects/Qt/test/snd/Anthony Vega - Full House.mp3",
        "D:/Projects/Qt/test/snd/Anthony Vega - The Charming Thief.mp3",
        "D:/Projects/Qt/test/snd/Anthony Vega - The Poker Player.mp3"
        }, BACKGROUND_SOUND_VOLUME),
    cardPlayer({ "D:/Projects/Qt/test/snd/Card.mp3" }),
    setBetPlayer({ "D:/Projects/Qt/test/snd/Bet.mp3" }),
    winBetPlayer({ "D:/Projects/Qt/test/snd/Win Chips.mp3" })
{}

void Snd::PlaySnd(Snd::Track_type track_t)
{
    switch (track_t)
    {
    case Snd::BackgroundMusic: backgroundPlayer.play(); break;
    case Snd::GetCard: cardPlayer.play(); break;
    case Snd::SetBet: setBetPlayer.play(); break;
    case Snd::WinBet: winBetPlayer.play(); break;
    default: break;
    }
    
}

void Snd::NextBackgroundSnd()
{
    backgroundPlayer.next();
}

void Snd::PauseBackgroundSnd()
{
    backgroundPlayer.pause();
}
