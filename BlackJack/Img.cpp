#pragma once
#include "Img.h"

Img::Img() :
    d_id(0)
{
    AddDeckImgs("gangsta_cards");
}

void Img::NextDeck()
{
    if (d_id < d_url.size() - 1) ++d_id;
    else d_id = 0;
}

std::string Img::GetCardImgUrl(int c_id)
{
    assert(c_id >= CARD_ID_BACK && c_id < CARD_ID_END);
    return d_url.at(d_id).at(c_id);        
}

//const char* Img::GetCardBackImg()
//{
//    return d_url.at(d_id).at(CARD_ID_BACK);
//}

void Img::AddDeckImgs(std::string path_name)
{
    std::vector<std::string> v;
    std::string img_url = "img/" + path_name + "/";

    // create an image of back side (shirt)
    v.push_back(img_url + "shirt.png");

    // put the card imgs to the deck
    for (int i = CARD_IMG_NUM_START; i < CARD_IMG_NUM_END; ++i)
    {
        v.push_back( img_url + itos(i) + "_of_club.png" );
        v.push_back( img_url + itos(i) + "_of_diamond.png" );
        v.push_back( img_url + itos(i) + "_of_heart.png" );
        v.push_back( img_url + itos(i) + "_of_spade.png" );
    }
    
    AddDeckImgs(v);
}

void Img::AddDeckImgs(std::vector<std::string> deck_url)
{
	d_url.push_back(deck_url);
    d_id = d_url.size() - 1;
}
