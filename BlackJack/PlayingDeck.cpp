#pragma once
#include <cassert>
#include "PlayingDeck.h"



PlayingDeck::PlayingDeck(const int deck_id, unsigned count)
{
    assert(deck_id >= 0 && deck_id < all_decks.size() && "Id of deck in the vector all_decks out of the range.");
    assert(count > 0 && count < 9 && "Count of decks must be in range (0...9).");

    while (count--)
    {
        std::list<Card*> cards_ptrs_from_deck(all_decks.at(deck_id).GetCards());
        _cards.merge(cards_ptrs_from_deck);
    }
}

void PlayingDeck::MixCards()
{
}

Card* PlayingDeck::TakeCard()
{
    assert(_cards.size() && "No cards in playing deck. Size of card list must be more than 0.");

    Card* p(*_cards.cbegin());
    _cards.pop_front();
    return p;
}

void PlayingDeck::PutCard(Card* p_card)
{
    assert(p_card && "Pointer to the card should be not nullptr for adding it list of cards");

    _cards.push_back(p_card);
}