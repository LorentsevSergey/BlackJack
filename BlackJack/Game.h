#pragma once
#include "Global.h"
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "main_window.h"

// global container for keeping all decks
extern std::vector<Deck> all_decks;
class main_window;

class Game
{
	main_window* _window = nullptr;
	bool _continue = false;
	std::vector<User*> _users;

public:
	Game(unsigned playerCash);
	virtual ~Game();

	void SetupUi(main_window* window);
	void Start();
	void End();

	void Hit();
	void Stand();
	void DealersTurn();
};

