#pragma once
#include "Game.h"

Game::Game(unsigned playerCash)
{
	// create a gangsta_cards deck and save it in global vector
	all_decks.push_back({ "gangsta_cards" });

	// create a dealer
	User* dealer = new Dealer();
	_users.push_back(dealer);

	// create a player
	User* player = new Player(playerCash > 0 ? playerCash : 0);
	_users.push_back(player);
}

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

void Game::Start()
{
#ifdef DEBUG
	assert(_continue == false && _window && "Game should be stopped, _window should be initialised by SetupUi().");
#endif
	_continue = true;

	// dealer 2 cards
	_users[0]->AddCard(all_decks[0].RandCard());
	Card d_shirt_card(all_decks[0].RandCard());
	d_shirt_card.TurnOver();
	_users[0]->AddCard(d_shirt_card);

	// player 2 cards
	_users[1]->AddCard(all_decks[0].RandCard());
	_users[1]->AddCard(all_decks[0].RandCard());

	// show cards in UI
	_window->ShowDealerCards(_users[0]->GetImgsUrl());
	_window->ShowPlayerCards(_users[1]->GetImgsUrl());

	static_cast<Dealer*>(_users[0])->TurnOverShirtCard();
}

void Game::End()
{
#ifdef DEBUG
	assert(_continue == true && _window && "Game should be runned, _window should be initialised by SetupUi().");
#endif
	// turn on a Hit button
	_window;

	_continue = false;
	for (User* u : _users) u->DelCards();
}

void Game::Hit()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif

	Card randCard = all_decks[0].RandCard();
	_users[1]->AddCard(randCard);
	_window->ShowPlayerCards(_users[1]->GetImgsUrl());
}

void Game::Stand()
{
	// teurn off a Hit button
	_window;

	// show all dealer cards in UI (w/ shirt card)
	_window->ShowDealerCards(_users[0]->GetImgsUrl());

	while(_users[0]->GetCards().size() < maxCards)
		DealersTurn();
}

void Game::DealersTurn()
{
#ifdef DEBUG
	assert(_window && "_window should be initialised by SetupUi().");
#endif

	Card randCard = all_decks[0].RandCard();
	_users[0]->AddCard(randCard);
	_window->ShowDealerCards(_users[0]->GetImgsUrl());
}

