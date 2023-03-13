#pragma once
#include "GameUI.h"
#include <iostream>

GameUI::GameUI(Game* game, main_window* window) :
	g (game),
	ui (window)
{
	g->SetupUi(this);
	ui->SetupGame(this);
}


#pragma region CARDS VISUALISATION

void GameUI::ShowDealerSecondCard(int id)
{
	ui->ShowCard(UsrType::dealer, 1, GetCardImgUrl(id));
}

void GameUI::ShowCards(std::vector<Triple<UsrType, int, int>> v, ButtonStatusAfterAnimation status)
{
	//Triple<UsrType, int, const char*> t;
	std::vector<Triple<UsrType, int, std::string>> v_char;

	for (size_t i = 0; i < v.size(); i++)
	{
		v_char.push_back({ v[i].first, v[i].second, GetCardImgUrl(v[i].third) });
		//ui->ShowMsg( ( "LabelID: " + itos(v[i].second) + "\tImgUrl : " + GetCardImgUrl(v[i].third) ).c_str() );
	}
	ui->ShowCardsAnimated(v_char, status);
}

void GameUI::HideCards()
{
	ui->HideCardLabels();
}
#pragma endregion 


#pragma region VISUALISATION

void GameUI::ShowScore(UsrType user, int score)
{
	score ?
		ui->ShowScore(user, itos(score).c_str())
		:
		ui->ShowScore(user);
}

void GameUI::ShowStatus(UsrType user, WinStatus status)
{
	ui->ShowStatus(user, status);
}

void GameUI::ShowBet(int bet)
{
	if(bet)
		ui->ShowBet(itos(bet).c_str());
	else
		ui->ShowBet();
}

void GameUI::ShowCash(int cash)
{
	ui->ShowCash(itos(cash).c_str());
}

void GameUI::ShowGameOver(bool b)
{
	ui->ShowGameOver(b);
}

void GameUI::ShowMsg(const char* msg)
{
	ui->ShowMsg(msg);
}
#pragma endregion


#pragma region BUTTONS CONTROL

void GameUI::DisableHitButton()
{
	ui->DisableHitButton();
}

void GameUI::ShowTurnButtons()
{
	ui->ShowTurnButtons();
}

void GameUI::HideTurnButtons()
{
	ui->HideTurnButtons();
}

void GameUI::DisableAllButtons()
{
	ui->DisableAllButtons();
}
#pragma endregion


#pragma region BUTTONS CLICKED

void GameUI::Hit()
{
	g->PlayerHit();
}

void GameUI::Stand()
{
	g->DealerMove();
}

void GameUI::Restart()
{
	g->Restart();
}

void GameUI::Deck()
{
	NextDeck();

	std::vector<int> v = g->GetCards(UsrType::dealer);
	for(size_t i = 0; i < v.size(); ++i)
		ui->ShowCard(UsrType::dealer, i, GetCardImgUrl(v[i]));

	v = g->GetCards(UsrType::player);
	for (size_t i = 0; i < v.size(); ++i)
		ui->ShowCard(UsrType::player, i, GetCardImgUrl(v[i]));
}
#pragma endregion