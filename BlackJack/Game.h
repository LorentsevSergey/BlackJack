// Start the game:
// If the player have a blackjack - his win
// 
// Players move:
// Player get a card. 
// If he have score more than 21 - he loose.
// If he have 21 score or 5 cards - dealers move.
// Else player keep moving.
// 
// Dealers move:
// Dealer take the cards until he`l have 17 score or 5 cards.
// After that check the game result.
// 
// Game result:
// If dealer score less than player score - player win.
// If dealer score more than 21 - player win.
// In other case - player loose.

#pragma once
#include "Global.h"
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "GameUI.h"
class GameUI;

class Game
{
	GameUI* ui = nullptr;
	Player player;
	Dealer dealer;
	Deck deck;
public:
	Game(int playerCash);
	virtual void SetupUi(GameUI* ui);


// START / RESTART

	virtual void Start();
	virtual void Restart();


// MOVES

	virtual void PlayerHit();
	virtual void DealerMove();


// CARDS

	std::vector<int> GetCards(UsrType);


// RESULTS
private:
	int CalculateScore(User*);
	void GameResult();

	void PlayerWin();
	void PlayerLoose();
};

