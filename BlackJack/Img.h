#pragma once
#include "Global.h"

class Img
{
	std::vector<std::vector<std::string>> d_url;
	int d_id;
public:
	Img();

protected:
	virtual void NextDeck();
	std::string GetCardImgUrl(int card_id);

	virtual void AddDeckImgs(std::string path_name);
	virtual void AddDeckImgs(std::vector<std::string> deck_urls);
};