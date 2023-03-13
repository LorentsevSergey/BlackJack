#pragma once
#include "main_window.h"

#pragma region CONSTRUCT and SETUP
main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
{
    _ui.setupUi(this);
    ShowTurnButtons();

    //group the card labels in array
#if MAX_HAND_CARDS == 5 && USER_COUNT == 2

    // add the player labels to array
    _player_card_label[0].first = _ui.player_card_0;
    _player_card_label[1].first = _ui.player_card_1;
    _player_card_label[2].first = _ui.player_card_2;
    _player_card_label[3].first = _ui.player_card_3;
    _player_card_label[4].first = _ui.player_card_4;

    // add the dealer labels to array
    _dealer_card_label[0].first = _ui.dealer_card_0;
    _dealer_card_label[1].first = _ui.dealer_card_1;
    _dealer_card_label[2].first = _ui.dealer_card_2;
    _dealer_card_label[3].first = _ui.dealer_card_3;
    _dealer_card_label[4].first = _ui.dealer_card_4;

    // add the player labels pos to array
    _player_card_label[0].second = _ui.player_card_0->pos();
    _player_card_label[1].second = _ui.player_card_1->pos();
    _player_card_label[2].second = _ui.player_card_2->pos();
    _player_card_label[3].second = _ui.player_card_3->pos();
    _player_card_label[4].second = _ui.player_card_4->pos();

    // add the dealer labels pos to array
    _dealer_card_label[0].second = _ui.dealer_card_0->pos();
    _dealer_card_label[1].second = _ui.dealer_card_1->pos();
    _dealer_card_label[2].second = _ui.dealer_card_2->pos();
    _dealer_card_label[3].second = _ui.dealer_card_3->pos();
    _dealer_card_label[4].second = _ui.dealer_card_4->pos();
#else
    assert(!"MAX_HAND_CARDS != 5 && USER_COUNT != 2");
#endif
    
    // save start point for the cards animation
    _start_pos = _ui.deck_2->pos();

    // fill the QPixmap for the next cleaning processes
    _clr_map.fill(Qt::transparent);
}

void main_window::SetupGame(GameUI* game)
{
    _game = game;
}
#pragma endregion


#pragma region CARDS VISUALISATION

void main_window::ShowCard(UsrType type, int id, std::string url)
{
#ifdef DEBUG
    assert(type == UsrType::dealer || type == UsrType::player);
    assert(id >= 0 && id < MAX_HAND_CARDS);
    assert(url.size() && url != "");
#endif
    // check user type and initialyse the pair lable
    std::pair<QLabel*, QPoint>& p = LabelAndPos(type, id, url);

    // moving label to position
    p.first->move(p.second);
}

//void main_window::ShowCardAnimated(UsrType type, int id, const char* url)
//{
//    DisableAllButtons();
//
//    // check user type and initialyse the pair lable
//    std::pair<QLabel*, QPoint> p = LabelAndPos(type, id, url);
//        
//    // animate the label and start it
//    QPropertyAnimation* animation = AnimateCard(p);
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
//    connect(animation, SIGNAL(finished()), this, SLOT(EnableTurnButtons()));
//}

void main_window::ShowCardsAnimated(std::vector< Triple<UsrType, int, std::string> > v, ButtonStatusAfterAnimation status)
{
    DisableAllButtons();

    QSequentialAnimationGroup* group = new QSequentialAnimationGroup;
    std::pair<QLabel*, QPoint> label_and_pos;
    QPropertyAnimation* animated_card;

    //ShowMsg(v[0].third);
    for (int i = 0; i < v.size(); ++i)
    {
        // check user type and initialyse the pair lable + pos
        label_and_pos = LabelAndPos(v[i].first, v[i].second, v[i].third);

        // made an animation
        animated_card = AnimateCard(label_and_pos);
        group->addAnimation(animated_card);
    }

    // chose what should we do with buttons after the animation
    connect(group, &QSequentialAnimationGroup::finished, this, [=]() { 
        switch (status)
        {
            case showTurnButtons: ShowTurnButtons(); break;
            case hideTurnButtons: HideTurnButtons(); break;
            case disableHitButton: DisableHitButton(); break;
        }
        });

    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void main_window::HideCardLabels()
{
    QLabel* d;
    QLabel* p;

    for (int i = 0; i < MAX_HAND_CARDS; ++i)
    {
        // get the labels
        d = _dealer_card_label[i].first;
        p = _player_card_label[i].first;

        // clear labels
        d->setPixmap(_clr_map);
        p->setPixmap(_clr_map);

        // hide labels under the deck
        d->move(_start_pos);
        p->move(_start_pos);
    }
}

std::pair<QLabel*, QPoint>& main_window::LabelAndPos(UsrType usr_type, int label_id, std::string img_url)
{
    // check user type (dealer or player) and initialyse the pair lable
    std::pair<QLabel*, QPoint>& p = usr_type
        ?
        _player_card_label[label_id]
        :
        _dealer_card_label[label_id];

    p.first->setPixmap({ img_url.c_str()});
    return p;
}

QPropertyAnimation* main_window::AnimateCard(std::pair<QLabel*, QPoint>& p)
{
    QPropertyAnimation* animation = new QPropertyAnimation(p.first, "pos");
    animation->setDuration(MSEC_CARD_ANIMATION_PAUSE);
    animation->setStartValue(_ui.deck_2->pos());
    animation->setEndValue(p.second);
    return animation;
}
#pragma endregion


#pragma region VISUALISATION

void main_window::ShowScore(UsrType user, const char* score)
{
    user ? 
        _ui.player_score->setText(score ? score : "")
        : 
        _ui.dealer_score->setText(score ? score : "");
}

//void main_window::ShowDealerStatus(const char* msg)
//{
//    _ui.dealer_result->setText(msg);
//}
//
//void main_window::ShowPlayerStatus(const char* msg)
//{
//    _ui.player_result->setText(msg);
//}

void main_window::ShowStatus(UsrType user, WinStatus status)
{
    QLabel* status_label = (user ? _ui.player_status : _ui.dealer_status);
    //QTextFormat text_format;
    
    switch (status)
    {
    case loose: 
        status_label->setText("LOOSE"); 
        //status_label->setTextFormat();
        break;

    case win: 
        status_label->setText("WIN"); 
        break;

    default:status_label->setText(""); break;
    }
}

void main_window::ShowBet(const char* bet)
{
    if (bet)
    {
        _ui.bet_value->setText(bet);
        _ui.chip_1->show();
    }
    else
    {
        _ui.bet_value->setText("");
        _ui.chip_1->hide();
    }
}

void main_window::ShowCash(const char* cash)
{
    cash ?
        _ui.cash_value->setText(cash)
        :
        _ui.cash_value->setText("0");
}

void main_window::ShowGameOver(bool b)
{
    b ? 
        _ui.game_over_label->show() 
        : 
        _ui.game_over_label->hide();
}

void main_window::ShowMsg(const char* msg)
{
    _ui.statusBar->showMessage(msg);
}
#pragma endregion


#pragma region BUTTONS CONTROL

void main_window::DisableHitButton()
{
    _ui.deck_button->setEnabled(true);
    _ui.hit_button->setDisabled(true);
    _ui.stand_button->show();
    _ui.stand_button->setEnabled(true);
    _ui.restart_button->hide();
}

void main_window::ShowTurnButtons()
{
    _ui.deck_button->setEnabled(true);
    _ui.hit_button->setEnabled(true);
    _ui.stand_button->show();
    _ui.stand_button->setEnabled(true);
    _ui.restart_button->hide();
}

void main_window::HideTurnButtons()
{
    _ui.deck_button->setEnabled(true);
    _ui.hit_button->setDisabled(true);
    _ui.stand_button->hide();
    _ui.restart_button->show();
    _ui.restart_button->setEnabled(true);
}

void main_window::DisableAllButtons()
{
    _ui.deck_button->setDisabled(true);
    _ui.hit_button->setDisabled(true);
    _ui.stand_button->setDisabled(true);
    _ui.restart_button->setDisabled(true);
}
#pragma endregion


#pragma region BUTTONS CLICKED

void main_window::on_hit_button_clicked()
{
    _game->Hit();
}

void main_window::on_stand_button_clicked()
{
    HideTurnButtons();
    _game->Stand();
}

void main_window::on_restart_button_clicked()
{
    HideCardLabels();
    _game->Restart();
}

void main_window::on_deck_button_clicked()
{
    ShowMsg("Deck changed.");
    _game->Deck();
}

//void main_window::on_push_button_clicked()
//{
//    std::pair<QLabel*, QPoint> p { _ui.bet_label, _ui.bet_label->pos() };
//    QPropertyAnimation* animation = AnimateCard(p);
//    animation->start();
//}
#pragma endregion
