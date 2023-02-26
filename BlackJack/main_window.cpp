#pragma once
#include "main_window.h"

main_window::main_window(Game* game, QWidget *parent)
    : QMainWindow(parent),
    _game(game)
{
    _ui.setupUi(this);

    // group the player labels for the future iterating
    _p_cards[0] = _ui.player_card_1;
    _p_cards[1] = _ui.player_card_2;
    _p_cards[2] = _ui.player_card_3;
    _p_cards[3] = _ui.player_card_4;
    _p_cards[4] = _ui.player_card_5;

    // group the dealer labels for the future iterating
    _d_cards[0] = _ui.dealer_card_1;
    _d_cards[1] = _ui.dealer_card_2;
    _d_cards[2] = _ui.dealer_card_3;
    _d_cards[3] = _ui.dealer_card_4;
    _d_cards[4] = _ui.dealer_card_5;

    // connect UI to the game
    _game->SetupUi(this);

    // fill the QPixmap for the next cleaning processes
    _clr_map.fill(Qt::transparent);
}

void main_window::ShowDealerCards(std::vector<const char*> v_img_url)
{
    //load a new image from v_img_url
    for (int i = 0; i < v_img_url.size() && i < maxCards; ++i)
        _d_cards[i]->setPixmap({ v_img_url[i] });
}

void main_window::ShowPlayerCards(std::vector<const char*> v_img_url)
{
    //load a new image from v_img_url
    for (int i = 0; i < v_img_url.size() && i < maxCards; ++i)
        _p_cards[i]->setPixmap({ v_img_url[i] });
}

void main_window::StatusBarMsg(const char* msg)
{
    _ui.statusBar->showMessage(msg);
}

void main_window::ClrCardLabels()
{
    for (int i = 0; i < maxCards; ++i)
    {
        _p_cards[i]->setPixmap(_clr_map);
        _d_cards[i]->setPixmap(_clr_map);
    }
}

void main_window::on_hit_button_clicked()
{
    _game->Hit();
}

void main_window::on_stand_button_clicked()
{
    _game->Stand();
}

void main_window::on_restart_button_clicked()
{
    _game->End();
    ClrCardLabels();
    _game->Start();
}