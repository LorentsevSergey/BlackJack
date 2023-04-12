#pragma once
#include <QtWidgets/QMainWindow>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include "ui_interface.h"
#include "GameUI.h"
#include "Global.h"
#include "CardAnimation.h"
class GameUI;

class main_window : 
    public QMainWindow
{
    Q_OBJECT
private:
    Ui::main_windowClass _ui;
    GameUI* _game = nullptr;
    QPixmap _clr_map; // to clear card labels
    QPoint _start_pos;
    std::pair<QLabel*, QPoint> _dealer_card_label [MAX_HAND_CARDS]; // dealer card labels and their pos
    std::pair<QLabel*, QPoint> _player_card_label [MAX_HAND_CARDS]; // player card labels and their pos

public:
    main_window(QWidget* parent = nullptr);
    void SetupGame(GameUI* game);

// CARDS VISUALISATION

    // shows one card on its position
    virtual void ShowCard(UsrType type, int id, std::string url);

    // create and start group of card animations from triple values:
    // 1. type of user
    // 2. card label id in UI
    // 3. img url
    virtual void ShowCardsAnimated(std::vector< Triple<UsrType, int, std::string> > usrTy_cardLabelID_imgURL, ButtonStatusAfterAnimation);
    virtual void HideCardLabels();
    virtual void SetDeckShirt(std::string url);

private:
    // 1. find the pair by UsrType and ID
    // 2. set pixmap to the pair label
    // 3. return the pair
    std::pair<QLabel*, QPoint>& LabelAndPos(UsrType usr_type, int label_id, std::string img_url);
    // 1. create a label animation
    // 2. move it to position
    // 3. return the animation pointer
    // NOTE: animation without start() func - to start it in the group of animation
    // If you need to launch it - use the returned pointer and start() func
    CardAnimation* AnimateCard(std::pair<QLabel*, QPoint>& label_and_pos);
    QPropertyAnimation* CardSound_Animation();
// VISUALISATION
public:
    virtual void ShowScore(UsrType user, const char* = nullptr);
    virtual void ShowStatus(UsrType user, WinStatus status = clearStatus);
    virtual void ShowBet(const char* = nullptr);
    virtual void ShowCash(const char* = nullptr);
    virtual void ShowGameOver(bool = true);
    virtual void ShowMsg(const char*);


// BUTTONS CONTROL
public slots:
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
public:
    //deck - off
    //hit - off
    //stand - off
    //restart - off
    virtual void DisableAllButtons();


// BUTTONS CLICKED
private slots:
    void on_hit_button_clicked();
    void on_stand_button_clicked();
    void on_restart_button_clicked();
    void on_deck_button_clicked();
    void on_push_button_clicked();
};
