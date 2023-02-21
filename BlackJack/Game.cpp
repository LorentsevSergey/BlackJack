#pragma once
#include "Game.h"

Game::Game()
{
	// create a gangsta_cards deck and save it in globale vector
	all_decks.push_back({ "gangsta_cards" });


	// create a playing deck from 2 decks placed at 0 index of all_decks vector
	_playing_deck = new PlayingDeck(0, 1);

}

Game::~Game()
{
	delete _playing_deck;
}

void Game::Start()
{
	_continue = true;
}

void Game::End()
{
	_continue = false;
}

PlayingDeck& Game::GetPlayingDeck()
{
	return *_playing_deck;
}
