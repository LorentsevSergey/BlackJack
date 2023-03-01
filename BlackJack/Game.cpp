#pragma once
#include "Game.h"

#pragma region Game/~Game/Setup

Game::Game(int playerCash) :
	_deck("gangsta_cards"),
	_users{
		new Dealer(),// create a dealer
		new Player(playerCash)// create a player
	}
{}

Game::~Game()
{
	for(User* u : _users) delete u;
}

void Game::SetupUi(main_window* window)
{
#ifdef DEBUG
	assert(window != 0 && _window != window && "Pointer to the window in the Game class == 0 or == itself.");
#endif
	
	_window = window;
	Start();
}

#pragma endregion


#pragma region Start/End

// Start the game
void Game::Start()
{
#ifdef DEBUG
	assert(_continue == false && _window && "Game should be stopped, _window should be initialised by SetupUi().");
#endif
	_continue = true;

	// hide "game over" label
	_window->ShowGameOver(false);

	// 2 cards for each
	{
		// dealer 2 cards
		_users[0]->AddCard(_deck.RandCard());
		Card d_shirt_card(_deck.RandCard());
		// turn over the dealer second card for showing shirt first time
		d_shirt_card.TurnOver();
		_users[0]->AddCard(d_shirt_card);

		// player 2 cards
		_users[1]->AddCard(_deck.RandCard());
		_users[1]->AddCard(_deck.RandCard());

		// show cards in UI
		_window->ShowDealerCards(_users[0]->GetImgsUrl());
		_window->ShowPlayerCards(_users[1]->GetImgsUrl());

		// turn over the dealer second card for showing face next time
		static_cast<Dealer*>(_users[0])->TurnOverShirtCard();
	}

	// scores and statuses
	{
		// get player score
		int PlayerScore = CalculateScore(_users[1]);

		// show player score
		_window->ShowScore(1, itos(PlayerScore).c_str());

		// clear dealer score
		_window->ShowScore(0);

		// clear statuses
		_window->ShowDealerStatus("");
		_window->ShowPlayerStatus("");
	}

	// cash and bet
	{
		_window->ShowBet(static_cast<Player*>(_users[1])->Bet(BET));
		_window->ShowCash(static_cast<Player*>(_users[1])->GetCash());
	}

}

void Game::Restart()
{
#ifdef DEBUG
	assert(_continue == true && _window && "Game should be runned, _window should be initialised by SetupUi().");
#endif
	_continue = false;

	// put cards back to the deck
	for (User* u : _users)
	{
		std::vector<Card> userCards(u->GetCards());
		for(Card c : userCards)	_deck.AddCard(c);
		u->DelCards();
	}

	Start();
}

#pragma endregion


#pragma region Game logic

// Player moove
void Game::PlayerHit()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif
	// player score
	int score = CalculateScore(_users[1]);

	// take 1 card
	if (_users[1]->GetCards().size() < MAX_HAND_CARDS &&
		score < MAX_SCORE)
	{
		_users[1]->AddCard(_deck.RandCard());
		_window->ShowPlayerCards(_users[1]->GetImgsUrl());
		score = CalculateScore(_users[1]);
	}

	// show player score
	_window->ShowScore(1, itos(score).c_str());

	// when payer have 21 score or more - dealer moove, than chek who win
	if (score >= MAX_SCORE) Stand();
}

// Dealer moove when player stand
void Game::Stand()
{
	_window->DisableTurnButtons();

	// show all dealer cards in UI (with open second card)
	_window->ShowDealerCards(_users[0]->GetImgsUrl());

	// calculate dealer score
	int score = CalculateScore(_users[0]);

	// show dealer score
	_window->ShowScore(0, itos(score).c_str());

	// dealer move
	while (_users[0]->GetCards().size() < MAX_HAND_CARDS
		&& score < MIN_DEALER_SCORE)
	{
		DealerHit();

		// calculate new score after DealerHit()
		score = CalculateScore(_users[0]);

		// show dealer score
		_window->ShowScore(0, itos(score).c_str());
	}
	// who win?
	GameResult();
}

// Dealer take 1 card
void Game::DealerHit()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif
	_users[0]->AddCard(_deck.RandCard());
	_window->ShowDealerCards(_users[0]->GetImgsUrl());
}

// Game score rules
int Game::CalculateScore(User* user)
{
	user->CalcScore([](int& score, std::vector<Card> cards)
		{
			score = 0;

			std::sort(cards.begin(), cards.end(), [](Card a, Card b)
				{
					return a.operator Value() < b.operator Value();
				});

			for (Card c : cards)
			{
				if (c >= Value::two && c < Value::ten)
					score += c.operator Value();
				else if (c >= Value::ten && c < Value::ace)
					score += 10;
				else if (c == Value::ace && score <= 10)
					score += 11;
				else if (c == Value::ace && score > 10)
					score += 1;
			}
		});

	return user->GetScore();
}

// Who win?
void Game::GameResult()
{
	// Users
	Dealer* dealer = static_cast<Dealer*>(_users[0]);
	Player* player = static_cast<Player*>(_users[1]);

	// Scores and cards
	int d_score = dealer->GetScore();
	int p_score = player->GetScore();
	std::vector<Card> p_cards = player->GetCards();

	//	Player win in case:
	//		1. Player score <= 21 and dealer score > 21
	//		2. Player score <= 21 and dealer score < player score
	//		3. Player have blackjack
	if (( p_score <= MAX_SCORE && d_score > MAX_SCORE ) 
		||
		( p_score <= MAX_SCORE && d_score < p_score )
		||
		(p_score == MAX_SCORE && p_cards.size() == 2 &&
		(p_cards[0] == Value::ace || p_cards[1] == Value::ace)) )
	{
		_window->ShowDealerStatus("BUST");
		_window->ShowPlayerStatus("WIN");
		player->Win();
	}
	else // Player loose
	{
		_window->ShowDealerStatus("WIN");
		_window->ShowPlayerStatus("BUST");
		player->Loose();
		
		// GAME OVER
		if (player->GetCash() <= 0)
		{
			_window->ShowGameOver();
			_window->DisableAllButtons();
		}
	}

	// show cash and bet
	{
		_window->ShowBet(player->Bet());
		_window->ShowCash(player->GetCash());
	}
}

#pragma endregion
