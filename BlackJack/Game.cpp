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
	d_shirt_card.TurnOver();
	_users[0]->AddCard(d_shirt_card);

	// player 2 cards
	_users[1]->AddCard(_deck.RandCard());
	_users[1]->AddCard(_deck.RandCard());

	// show cards in UI
	_window->ShowDealerCards(_users[0]->GetImgsUrl());
	_window->ShowPlayerCards(_users[1]->GetImgsUrl());

	static_cast<Dealer*>(_users[0])->TurnOverShirtCard();

	CheckScore(_users[1]->GetCards());
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
}
#pragma endregion

#pragma region Game logic
void Game::Hit()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif
	if (_users[1]->GetCards().size() < maxCards)
	{
		Card randCard = _deck.RandCard();
		_users[1]->AddCard(randCard);
		_window->ShowPlayerCards(_users[1]->GetImgsUrl());
		CheckScore(_users[1]->GetCards());
	}
}

void Game::Stand()
{
	// show all dealer cards in UI (for open shirt-card)
	_window->ShowDealerCards(_users[0]->GetImgsUrl());

	while(_users[0]->GetCards().size() < maxCards)
		DealerMove();
}

void Game::DealerMove()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif

	Card randCard = _deck.RandCard();
	_users[0]->AddCard(randCard);
	_window->ShowDealerCards(_users[0]->GetImgsUrl());
}

int Game::CheckScore(std::vector<Card> cards) const
{
	int res{ 0 };

	std::sort(cards.begin(), cards.end());

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

	_window->StatusBarMsg(itos(res).c_str());
	return res;
}

#pragma endregion
