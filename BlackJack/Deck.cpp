#pragma once
#include "Deck.h"
#include <string>

Deck::Deck(const std::string deck_path) /*: _deck_path(deck_path)*/
{
    //_cards.push_back("img/" + _deck_path + "/back.png", card::suit::);

    std::string img_url = "img/" + deck_path + "/";

    
    //create and put the cards into the deck

    //jokers
    _cards.push_back({ img_url + "joker_red.png", Card::Suit::nosuit, 0});
    _cards.push_back({ img_url + "joker_black.png", Card::Suit::nosuit, 0});

    //clubs
    _cards.push_back({ img_url + "2_of_club.png", Card::Suit::club, 2 });
    _cards.push_back({ img_url + "3_of_club.png", Card::Suit::club, 3 });
    _cards.push_back({ img_url + "4_of_club.png", Card::Suit::club, 4 });
    _cards.push_back({ img_url + "5_of_club.png", Card::Suit::club, 5 });
    _cards.push_back({ img_url + "6_of_club.png", Card::Suit::club, 6 });
    _cards.push_back({ img_url + "7_of_club.png", Card::Suit::club, 7 });
    _cards.push_back({ img_url + "8_of_club.png", Card::Suit::club, 8 });
    _cards.push_back({ img_url + "9_of_club.png", Card::Suit::club, 9 });
    _cards.push_back({ img_url + "10_of_club.png", Card::Suit::club, 10 });
    _cards.push_back({ img_url + "jack_of_club.png", Card::Suit::club, 10 });
    _cards.push_back({ img_url + "queen_of_club.png", Card::Suit::club, 10 });
    _cards.push_back({ img_url + "king_of_club.png", Card::Suit::club, 10 });
    _cards.push_back({ img_url + "ace_of_club.png", Card::Suit::club, 11 });

    //diamonds
    _cards.push_back({ img_url + "2_of_diamond.png", Card::Suit::diamond, 2 });
    _cards.push_back({ img_url + "3_of_diamond.png", Card::Suit::diamond, 3 });
    _cards.push_back({ img_url + "4_of_diamond.png", Card::Suit::diamond, 4 });
    _cards.push_back({ img_url + "5_of_diamond.png", Card::Suit::diamond, 5 });
    _cards.push_back({ img_url + "6_of_diamond.png", Card::Suit::diamond, 6 });
    _cards.push_back({ img_url + "7_of_diamond.png", Card::Suit::diamond, 7 });
    _cards.push_back({ img_url + "8_of_diamond.png", Card::Suit::diamond, 8 });
    _cards.push_back({ img_url + "9_of_diamond.png", Card::Suit::diamond, 9 });
    _cards.push_back({ img_url + "10_of_diamond.png", Card::Suit::diamond, 10 });
    _cards.push_back({ img_url + "jack_of_diamond.png", Card::Suit::diamond, 10 });
    _cards.push_back({ img_url + "queen_of_diamond.png", Card::Suit::diamond, 10 });
    _cards.push_back({ img_url + "king_of_diamond.png", Card::Suit::diamond, 10 });
    _cards.push_back({ img_url + "ace_of_diamond.png", Card::Suit::diamond, 11 });

    //hearts
    _cards.push_back({ img_url + "2_of_heart.png", Card::Suit::heart, 2 });
    _cards.push_back({ img_url + "3_of_heart.png", Card::Suit::heart, 3 });
    _cards.push_back({ img_url + "4_of_heart.png", Card::Suit::heart, 4 });
    _cards.push_back({ img_url + "5_of_heart.png", Card::Suit::heart, 5 });
    _cards.push_back({ img_url + "6_of_heart.png", Card::Suit::heart, 6 });
    _cards.push_back({ img_url + "7_of_heart.png", Card::Suit::heart, 7 });
    _cards.push_back({ img_url + "8_of_heart.png", Card::Suit::heart, 8 });
    _cards.push_back({ img_url + "9_of_heart.png", Card::Suit::heart, 9 });
    _cards.push_back({ img_url + "10_of_heart.png", Card::Suit::heart, 10 });
    _cards.push_back({ img_url + "jack_of_heart.png", Card::Suit::heart, 10 });
    _cards.push_back({ img_url + "queen_of_heart.png", Card::Suit::heart, 10 });
    _cards.push_back({ img_url + "king_of_heart.png", Card::Suit::heart, 10 });
    _cards.push_back({ img_url + "ace_of_heart.png", Card::Suit::heart, 11 });

    //spades
    _cards.push_back({ img_url + "2_of_spade.png", Card::Suit::spade, 2 });
    _cards.push_back({ img_url + "3_of_spade.png", Card::Suit::spade, 3 });
    _cards.push_back({ img_url + "4_of_spade.png", Card::Suit::spade, 4 });
    _cards.push_back({ img_url + "5_of_spade.png", Card::Suit::spade, 5 });
    _cards.push_back({ img_url + "6_of_spade.png", Card::Suit::spade, 6 });
    _cards.push_back({ img_url + "7_of_spade.png", Card::Suit::spade, 7 });
    _cards.push_back({ img_url + "8_of_spade.png", Card::Suit::spade, 8 });
    _cards.push_back({ img_url + "9_of_spade.png", Card::Suit::spade, 9 });
    _cards.push_back({ img_url + "10_of_spade.png", Card::Suit::spade, 10 });
    _cards.push_back({ img_url + "jack_of_spade.png", Card::Suit::spade, 10 });
    _cards.push_back({ img_url + "queen_of_spade.png", Card::Suit::spade, 10 });
    _cards.push_back({ img_url + "king_of_spade.png", Card::Suit::spade, 10 });
    _cards.push_back({ img_url + "ace_of_spade.png", Card::Suit::spade, 11 });

}

const Deck::Card Deck::take_card()
{
    const Deck::Card card (*_cards.cbegin());
    _cards.pop_front();
    return card;
}

void Deck::put_card(const Deck::Card card)
{
    _cards.push_back(card);
}
