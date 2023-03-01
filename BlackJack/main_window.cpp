#pragma once
#include "main_window.h"

main_window::main_window(Game* game, QWidget *parent)
    : QMainWindow(parent),
    _game(game)
{
    _ui.setupUi(this);
    EnableTurnButtons();

    //group the labels
    {
        // add the player labels to array for the future iterating
        _p_cards[0] = _ui.player_card_1;
        _p_cards[1] = _ui.player_card_2;
        _p_cards[2] = _ui.player_card_3;
        _p_cards[3] = _ui.player_card_4;
        _p_cards[4] = _ui.player_card_5;

        // add the dealer labels to array for the future iterating
        _d_cards[0] = _ui.dealer_card_1;
        _d_cards[1] = _ui.dealer_card_2;
        _d_cards[2] = _ui.dealer_card_3;
        _d_cards[3] = _ui.dealer_card_4;
        _d_cards[4] = _ui.dealer_card_5;
    }

    // connect UI to the game
    _game->SetupUi(this);

    // fill the QPixmap for the next cleaning processes
    _clr_map.fill(Qt::transparent);
}


#pragma region CARDS VISUALISATION

void main_window::ShowDealerCards(std::vector<const char*> v_img_url)
{
    //load a new image from v_img_url
    for (int i = 0; i < v_img_url.size() && i < MAX_HAND_CARDS; ++i)
        _d_cards[i]->setPixmap({ v_img_url[i] });
}

void main_window::ShowPlayerCards(std::vector<const char*> v_img_url)
{
    //load a new image from v_img_url
    for (int i = 0; i < v_img_url.size() && i < MAX_HAND_CARDS; ++i)
        _p_cards[i]->setPixmap({ v_img_url[i] });
}

void main_window::ClrCardLabels()
{
    for (int i = 0; i < MAX_HAND_CARDS; ++i)
    {
        _p_cards[i]->setPixmap(_clr_map);
        _d_cards[i]->setPixmap(_clr_map);
    }
}
#pragma endregion


#pragma region TEXT VISUALISATION

void main_window::ShowScore(int user_id, const char* str)
{
    if (!str) return;
    (user_id ? _ui.player_score : _ui.dealer_score)->setText(str);
}

void main_window::ShowDealerStatus(const char* msg)
{
    _ui.dealer_result->setText(msg);
}

void main_window::ShowPlayerStatus(const char* msg)
{
    _ui.player_result->setText(msg);
}

void main_window::ShowBet(int bet)
{
    _ui.bet_value->setText(bet ? itos(bet).c_str() : "");
}

void main_window::ShowCash(int cash)
{
    _ui.cash_value->setText(cash ? itos(cash).c_str() : "0");
}

void main_window::ShowGameOver(bool b)
{
    b ? _ui.game_over_label->show() : _ui.game_over_label->hide();
}

void main_window::ShowMsg(const char* msg)
{
    _ui.statusBar->showMessage(msg);
}
#pragma endregion


#pragma region BUTTONS CLICKED

void main_window::on_hit_button_clicked()
{
    _game->PlayerHit();
}

void main_window::on_stand_button_clicked()
{
    DisableTurnButtons();
    _game->Stand();
}

void main_window::on_restart_button_clicked()
{
    EnableTurnButtons();
    ClrCardLabels();
    _game->Restart();
}

void main_window::on_deck_button_clicked()
{
    //// change the shirt and skins of deck
    // 
    //_ui.deck_1->setPixmap();
    //_ui.deck_2->setPixmap();
    //_ui.deck_3->setPixmap();
}
#pragma endregion


#pragma region ENABLE / DISABLE BUTTONS

void main_window::EnableTurnButtons()
{
    _ui.hit_button->setEnabled(true);
    _ui.stand_button->show();
    _ui.restart_button->hide();
}

void main_window::DisableTurnButtons()
{
    _ui.hit_button->setDisabled(true);
    _ui.stand_button->hide();
    _ui.restart_button->show();
}
void main_window::DisableAllButtons()
{
    DisableTurnButtons();
    _ui.restart_button->setDisabled(true);
    _ui.deck_button->setDisabled(true);
}
#pragma endregion