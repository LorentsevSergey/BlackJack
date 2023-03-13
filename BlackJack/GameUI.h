// Class GameUI uses for connecting Qt window with game logic.
// Its "know" about bouth of them and also inherits QObject class for using connect() function.
// Class methods uses for simplify game logic and for types conversion.

#pragma once
#include "Global.h"
#include "main_window.h"
#include "Img.h"
#include "Snd.h"
#include "Game.h"


class Game;
class main_window;

class GameUI : 
	public QObject,
	public Img,
	public Snd
{
	Q_OBJECT
private:
	Game* g;
	main_window* ui;

public:
	GameUI() = delete;
	GameUI(Game* game, main_window* window);


// CARDS VISUALISATION (game -> ui)

	virtual void ShowDealerSecondCard(int id);
	// create and start group of card animations from triple values:
	// 1. type of user
	// 2. card label id in UI
	// 3. url id
	virtual void ShowCards(std::vector< Triple<UsrType, int, int> > usrTy_cardLabelID_imgUrlId, ButtonStatusAfterAnimation);
	virtual void HideCards();


// VISUALISATION (game -> ui)

	virtual void ShowScore(UsrType user, int score = 0);
	virtual void ShowStatus(UsrType user, WinStatus status = clearStatus);
	virtual void ShowBet(int = 0);
	virtual void ShowCash(int = 0);
	virtual void ShowGameOver(bool = true);
	virtual void ShowMsg(const char*);


// BUTTONS CONTROL (game -> ui)

	//deck - on
	//hit - off
	//stand - show, on
	//restart - hide
	virtual void DisableHitButton();
	//deck - on
	//hit - on
	//stand - show, on
	//restart - hide
	virtual void ShowTurnButtons();
	//deck - on
	//hit - off
	//stand - hide
	//restart - show, on
	virtual void HideTurnButtons();
	//deck - off
	//hit - off
	//stand - off
	//restart - off
	virtual void DisableAllButtons();


// BUTTONS CLICKED (ui -> game)

	virtual void Hit();
	virtual void Stand();
	virtual void Restart();
	virtual void Deck();

};

