#pragma once
#include <qpixmap.h>

class Card
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
	const QPixmap _front_img;
	std::shared_ptr<QPixmap> _p_back_img;
	const Suit _suit;
	const int _cost;
	bool is_front_side{ true };

public:
	// img_url - the adress of image in resources.qrc
	// back_img - shared pointer to the back image (one image for all deck)
	// suit - spade = 0, heart = 1, diamond = 2, club = 3, nosuit = 4
	// cost - score for the card
	Card(const std::string& front_img_url,
		std::shared_ptr<QPixmap>& back_img,
		const Card::Suit& suit = nosuit,
		const int cost = 0);

	Card::Suit suit() const;
	int cost() const;

	operator QPixmap() const;

	void turn_over();
};

