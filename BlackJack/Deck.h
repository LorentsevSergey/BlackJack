#pragma once
#include <qpixmap.h>
#include <list>

class Deck
{
	//const std::string _deck_path;

public:
	class Card : public QPixmap
	{
	public: enum Suit
		{
			spade = 0,
			heart = 1,
			diamond = 2,
			club = 3,
			nosuit = 4
		};
	private: 
		const Suit _suit;
		const int _cost;

	public: 
		//img_url - the adress of image in resources.qrc
		//suit - the enum [0...4] in card class
		Card(const std::string& img_url, const Card::Suit& suit, const int cost) 
		:
			Card::QPixmap(img_url.c_str()),
			_suit(suit),
			_cost(cost)
		{};
		
		int cost() const { return _cost; }

		operator QPixmap () const { return static_cast<QPixmap>(*this); }
	};

private:
	std::list<Card> _cards;

public:
	Deck(const std::string);

	const Deck::Card take_card();
	void put_card(const Deck::Card);
};


