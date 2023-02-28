#pragma once
#include "Game.h"

#pragma region Game/~Game/Setup
Game::Game(unsigned playerCash) :
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
void Game::Start()
{
#ifdef DEBUG
	assert(_continue == false && _window && "Game should be stopped, _window should be initialised by SetupUi().");
#endif
	_continue = true;

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

	// get player score
	int PlayerScore = CheckScore(_users[1]->GetCards());
	// show player score
	_window->ShowScore(1, itos(PlayerScore).c_str());
	// clear dealer score
	_window->ShowScore(0);
	_window->ShowWinner();
}

void Game::End()
{
#ifdef DEBUG
	assert(_continue == true && _window && "Game should be runned, _window should be initialised by SetupUi().");
#endif
	for (User* u : _users)
	{
		std::vector<Card> userCards(u->GetCards());
		for(Card c : userCards)	_deck.AddCard(c);
		u->DelCards();
	}
	_continue = false;
	for (User* u : _users) u->DelCards();

	//if() _window->ShowWinner(0);
	//else if() _window->ShowWinner(1);
}
#pragma endregion

#pragma region Game logic
void Game::PlayerHit()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif
	int score = CheckScore(_users[1]->GetCards());

	if (_users[1]->GetCards().size() < MAX_HAND_CARDS &&
		score < MAX_SCORE)
	{
		_users[1]->AddCard(_deck.RandCard());
		_window->ShowPlayerCards(_users[1]->GetImgsUrl());
		score = CheckScore(_users[1]->GetCards());
	}

	// show player score
	_window->ShowScore(1, itos(score).c_str());

	/*if (score > MAX_SCORE)
	{
		_window->StatusBarMsg("You loose");
		End();
	}*/
}

void Game::Stand()
{
	// show all dealer cards in UI (for open shirt-card)
	_window->ShowDealerCards(_users[0]->GetImgsUrl());

	int score = CheckScore(_users[0]->GetCards());
	// show dealer score
	_window->ShowScore(0, itos(score).c_str());

	// dealer move
	while (_users[0]->GetCards().size() < MAX_HAND_CARDS &&
		score < MIN_DEALER_SCORE)
	{
		DealerHit();

		// calculate new score after DealerHit()
		score = CheckScore(_users[0]->GetCards());

		// show dealer score
		_window->ShowScore(0, itos(score).c_str());
	}
}

void Game::DealerHit()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif
	_users[0]->AddCard(_deck.RandCard());
	_window->ShowDealerCards(_users[0]->GetImgsUrl());
}

int Game::CheckScore(std::vector<Card> cards) const
{
	int res{ 0 };

	std::sort(cards.begin(), cards.end(), [](Card a, Card b)
		{
			return a.operator Value() < b.operator Value();
		});

	for (Card c : cards)
	{
		if (c >= Value::two && c < Value::ten)
			res += c.operator Value();
		else if (c >= Value::ten && c < Value::ace)
			res += 10;
		else if (c == Value::ace && res <= 10)
			res += 11;
		else if (c == Value::ace && res > 10)
			res += 1;
	}

	return res;
}

#pragma endregion
