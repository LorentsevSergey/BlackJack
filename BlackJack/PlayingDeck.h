#pragma once
#include "Deck.h"

// global container for keeping all decks
extern std::vector<Deck> all_decks;

class PlayingDeck
{
	//list of pointers to the cards added to the PlaingDeck object from global vector all_decks
	std::list<Card*> _cards;
public:
	PlayingDeck(const int deck_id, unsigned count);
	void MixCards();
	Card* TakeCard();
	void PutCard(Card*);
};

