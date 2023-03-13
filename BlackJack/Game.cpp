#pragma once
#include "Game.h"

#pragma region CONSTRUCT and SETUP

Game::Game(int playerCash) :
	player(playerCash)
{}

void Game::SetupUi(GameUI* game_ui)
{
#ifdef DEBUG
	assert(game_ui != nullptr);
#endif
	ui = game_ui;

	// hide "game over" label
	ui->ShowGameOver(false);
	Start();
}
#pragma endregion


#pragma region START / RESTART

void Game::Start()
{
#ifdef DEBUG
	assert(ui && "ui should be initialised by SetupUi().");
#endif

	// cash and bet
	player.SetBet(BET);
	ui->ShowBet(player.GetBet());
	ui->ShowCash(player.GetCash());

	// 2 cards for each
	Card d_card_0 = deck.RandCard();
	Card d_card_1 = deck.RandCard();
	Card p_card_0 = deck.RandCard();
	Card p_card_1 = deck.RandCard();
		
	// turn over the dealer second card for showing shirt first time
	d_card_1.TurnOver(false);

	dealer.AddCard(d_card_0);
	dealer.AddCard(d_card_1);
	player.AddCard(p_card_0);
	player.AddCard(p_card_1);

	// scores and statuses
	int p_score = CalculateScore(&player);
	ui->ShowScore(UsrType::player, p_score);
	ui->ShowScore(UsrType::dealer);
	ui->ShowStatus(UsrType::dealer);
	ui->ShowStatus(UsrType::player);

	ui->HideCards();

	// vector for sending cards in UI
	std::vector<Triple<UsrType, int, int>> cards{
		{ UsrType::player, 0, p_card_0.ImgID() },
		{ UsrType::dealer, 0, d_card_0.ImgID() },
		{ UsrType::player, 1, p_card_1.ImgID() },
		{ UsrType::dealer, 1, d_card_1.ImgID() }
	};

	// player have blackjack
	if ((p_card_0 == Value::ace && p_card_1 == Value::jack) ||
		(p_card_0 == Value::jack && p_card_1 == Value::ace))
	{	// show cards and restart button
		PlayerWin();
		ui->ShowCards(cards, hideTurnButtons);
	}
	else // player have 21, show cards and disable Hit button
		if (p_score == MAX_SCORE)
			ui->ShowCards(cards, disableHitButton);
		else// show cards and buttons to play
			ui->ShowCards(cards, showTurnButtons);
}

void Game::Restart()
{
	// put cards back to the deck
	for (Card c : player.GetCards()) deck.AddCard(c);
	for (Card c : dealer.GetCards()) deck.AddCard(c);

	player.DelCards();
	dealer.DelCards();

	Start();
}
#pragma endregion


#pragma region MOVES

void Game::PlayerHit()
{
	if (player.GetCardsCount() == MAX_HAND_CARDS) return;
	ui->DisableAllButtons();

	// take 1 card
	Card card = deck.RandCard();
	player.AddCard(card);
	// prepare the card for showing
	std::vector<Triple<UsrType, int, int>> v = { { UsrType::player, player.GetCardsCount()-1, card.ImgID() } };

	// player score
	int score = CalculateScore(&player);
	ui->ShowScore(UsrType::player, score);

	if (score > MAX_SCORE)
	{
		PlayerLoose();
		ui->ShowCards(v, hideTurnButtons);
	}
	else if (player.GetCardsCount() == MAX_HAND_CARDS ||
			score == MAX_SCORE)
			ui->ShowCards(v, disableHitButton);
		else 
			ui->ShowCards(v, showTurnButtons);
}

void Game::DealerMove()
{
	ui->DisableAllButtons();

	// turn over and show the dealer second card
	dealer.TurnOverShirtCard(true);
	ui->ShowDealerSecondCard( dealer.GetSecondCardID());

	// calculate and show dealer score
	int score = CalculateScore(&dealer);
	ui->ShowScore(UsrType::dealer, score);

	// vector for sending cards in UI
	std::vector<Triple<UsrType, int, int>> cards;
	
	while (dealer.GetCardsCount() < MAX_HAND_CARDS
		&& score < MIN_DEALER_SCORE)
	{
		Card card = deck.RandCard();
		dealer.AddCard(card);

		// calculate and show score
		score = CalculateScore(&dealer);
		ui->ShowScore(UsrType::dealer, score);

		// collect the cards for showing
		Triple<UsrType, int, int> t = { UsrType::dealer, dealer.GetCardsCount() - 1, card.ImgID() };
		cards.push_back( t );
	}

	ui->ShowCards(cards, hideTurnButtons);
	//if(cards.size()) ui->ShowMsg((  "Size: " + itos(cards.size()) +  "; IMG: " + itos(cards[0].third)  ).c_str());
	GameResult();
}
#pragma endregion


#pragma region CARDS

std::vector<int> Game::GetCards(UsrType user)
{
#if USER_COUNT == 2
	std::vector<Card> cards = (user == dealer ?
		dealer.GetCards()
		:
		player.GetCards());
#endif
	std::vector<int> url_id;

	for (size_t i = 0; i < cards.size(); i++)
		url_id.push_back(cards[i].ImgID());

	return url_id;
}
#pragma endregion


#pragma region RESULTS

int Game::CalculateScore(User* user)
{
	user->CalcScore([](int& score, std::vector<Card> cards)
		{
			score = 0;

			std::sort(cards.begin(), cards.end(), [](Card a, Card b)
				{
					return a.operator Value() < b.operator Value();
				});

			for (Card c : cards)
			{
				if (c >= Value::two && c < Value::ten)
					score += c.operator Value();
				else if (c >= Value::ten && c < Value::ace)
					score += 10;
				else if (c == Value::ace && score <= 10)
					score += 11;
				else if (c == Value::ace && score > 10)
					score += 1;
			}
		});

	return user->GetScore();
}

void Game::GameResult()
{
	int d_score = dealer.GetScore();

	//	Player win in case:
	//  1. Player score <= 21 (checked on hit) and dealer score > 21
	//	2. Player score <= 21 (checked on hit) and dealer score < player score
	if (d_score > MAX_SCORE || d_score < player.GetScore())
		PlayerWin();
	else
	{
		PlayerLoose();
		
		// GAME OVER
		if (player.GetCash() <= 0)
		{
			ui->ShowGameOver();
			ui->DisableAllButtons();
		}
	}

	// show cash and bet
	ui->ShowBet(player.GetBet());
	ui->ShowCash(player.GetCash());
}

void Game::PlayerWin()
{
	player.Win();
	ui->ShowStatus(UsrType::player, win);
	ui->ShowStatus(UsrType::dealer, loose);
}

void Game::PlayerLoose()
{
	player.Loose();
	ui->ShowStatus(UsrType::player, loose);
	ui->ShowStatus(UsrType::dealer, win);
}
#pragma endregion