#pragma once
#include "Deck.h"

Deck::Deck()
{
    //create and put the cards into the deck
    for (int i = CARD_ID_START, v = CARD_IMG_NUM_START; i < CARD_ID_END && v < CARD_IMG_NUM_END; i += 4, ++v)
    {
        cards.push_back({ i,   Suit::club, Value(v) });
        cards.push_back({ i+1, Suit::diamond, Value(v) });
        cards.push_back({ i+2, Suit::heart, Value(v) });
        cards.push_back({ i+3, Suit::spade, Value(v) });
    }
}

const Card Deck::RandCard()
{
#ifdef DEBUG
    assert(cards.size() && "Empty deck - can`t take a card.");
#endif
    int i = rand() % cards.size();
    Card rCard = cards[i];
    cards.erase(std::remove(cards.begin(), cards.end(), cards[i]), cards.end());
    return rCard;
}

void Deck::AddCard(Card& card)
{
    card.TurnOver(true);
    cards.push_back(card);
}

