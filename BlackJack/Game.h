#pragma once
#include <string>
#include "PlayingDeck.h"
#include "Dealer.h"
#include "Player.h"

class Game
{
	bool _continue = false;

	PlayingDeck* _playing_deck;

public:
	Game();
	~Game();

	PlayingDeck& GetPlayingDeck();
	void Start();
	void End();
};

