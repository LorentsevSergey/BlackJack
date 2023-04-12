#pragma once
#include <memory>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define DEBUG
#ifdef DEBUG
#include <QtDebug>
#endif

// user
#define USER_COUNT 2

// card
#define CARD_IMG_NUM_START 2
#define CARD_IMG_NUM_END 15
#define CARD_ID_BACK 0
#define CARD_ID_START 1
#define CARD_ID_END 53
#define MAX_HAND_CARDS 5
//#define CARDS_COUNT 52

// score
#define MAX_SCORE 21
#define MIN_DEALER_SCORE 17

// cash and bet
#define MIN_PLAYER_CASH 0
#define MAX_PLAYER_CASH 10000
#define PLAYER_START_CASH 500
#define BET 5

// timings
//#define MILLISECONDS_PAUSE 10
#define MSEC_CARD_ANIMATION_DURATION 410

// sound
#define SOUND_VOLUME 70
#define BACKGROUND_SOUND_VOLUME 50


enum Suit
{
	spade = 0,
	heart = 1,
	diamond = 2,
	club = 3,
	noSuit = 4
};

enum Value
{
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack = 11,
	queen = 12,
	king = 13,
	ace = 14,
	joker = 15,
	noValue = 16
};

//enum Result
//{
//	blackjack,
//	twenty_one,
//	bust,
//	stop,
//	proceed
//};

enum UsrType
{
	dealer = 0,
	player = 1
};

//enum WhichTurn
//{
//	dealerTurn,
//	playerTurn
//};

enum WinStatus
{
	loose,
	win,
	clearStatus
};

enum ButtonStatusAfterAnimation
{
	showTurnButtons,
	hideTurnButtons,
	disableHitButton
};

// Three value in one
template <typename T1, typename T2, typename T3>
struct Triple
{
	T1 first;
	T2 second;
	T3 third;
};

// Convert int to string
std::string itos(int val);