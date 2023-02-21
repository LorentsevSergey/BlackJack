#pragma once
#include "main_window.h"

main_window::main_window(Game* game, QWidget *parent)
    : QMainWindow(parent),
    _game(game)
{
    _ui.setupUi(this);
    _game->Start();
}

main_window::~main_window()
{
    delete _game;
}

void main_window::on_hit_button_clicked()
{

}

void main_window::on_stand_button_clicked()
{
}

void main_window::on_restart_button_clicked()
{
    _ui.dealer_card_1->setPixmap(*_game->GetPlayingDeck().TakeCard());
    Card* dealer_card_2 (_game->GetPlayingDeck().TakeCard());
    // turn over the card
    dealer_card_2->TurnOver();
    _ui.dealer_card_2->setPixmap(*dealer_card_2);

    _ui.player1_card_1->setPixmap(*_game->GetPlayingDeck().TakeCard());
    _ui.player1_card_2->setPixmap(*_game->GetPlayingDeck().TakeCard());

    _ui.player2_card_1->setPixmap(*_game->GetPlayingDeck().TakeCard());
    _ui.player2_card_2->setPixmap(*_game->GetPlayingDeck().TakeCard());
}