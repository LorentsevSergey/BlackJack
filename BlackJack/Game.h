#pragma once
#include "Global.h"
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "main_window.h"

class main_window;

class Game
{
	main_window* _window = nullptr;
	bool _continue = false;
	std::vector<User*> _users;
	Deck _deck;

public:
	// playerCash should be in range [Player::minCash ... Player::maxCash]
	Game(unsigned playerCash);
	virtual ~Game();

	virtual void SetupUi(main_window* window);
	virtual void Start();
	virtual void End();

	virtual void PlayerHit();
	virtual void Stand();
	virtual void DealerHit();

	// Calculate the cards score
	virtual int CheckScore(std::vector<Card>) const;
};

