#pragma once
#include "Deck.h"

Deck::Deck(const std::string deck_path)
{
#ifdef DEBUG
    assert(deck_path.size() && "Path name with the card images shouldn`t be empty.");
#endif
    std::string img_url = "img/" + deck_path + "/";

    //create an image of back side
    std::shared_ptr<std::string> shirt_img_url( new std::string( img_url + "shirt.png" ) );

    //create and put the cards into the deck
    for (int i = CARD_ID_START; i < CARD_ID_END; ++i)
    {
        _cards.push_back({ img_url + itos(i) + "_of_club.png", shirt_img_url, Suit::club, Value(i)});
        _cards.push_back({ img_url + itos(i) + "_of_diamond.png", shirt_img_url, Suit::diamond, Value(i) });
        _cards.push_back({ img_url + itos(i) + "_of_heart.png", shirt_img_url, Suit::heart, Value(i) });
        _cards.push_back({ img_url + itos(i) + "_of_spade.png", shirt_img_url, Suit::spade, Value(i) });
    }
}

const Card Deck::RandCard()
{
#ifdef DEBUG
    assert(_cards.size() && "Empty deck - can`t take a card.");
#endif
    int i = rand() % _cards.size();
    Card rCard = _cards[i];
    _cards.erase(std::remove(_cards.begin(), _cards.end(), _cards[i]), _cards.end());
    return rCard;
}

void Deck::AddCard(const Card& card)
{
    _cards.push_back(card);
}
