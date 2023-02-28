#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_interface.h"
#include "Game.h"

class Game;

class main_window : 
    public QMainWindow
{
    Q_OBJECT
private:
    Ui::main_windowClass _ui;
    Game* _game;
    QPixmap _clr_map; // for clear card labels
    QLabel* _d_cards[MAX_HAND_CARDS]; // dealer card labels
    QLabel* _p_cards[MAX_HAND_CARDS]; // player card labels

public:
    main_window(Game*, QWidget* parent = nullptr);

    void ShowDealerCards(std::vector<const char*>);
    void ShowPlayerCards(std::vector<const char*>);
    void ClrCardLabels();

    void ShowScore(int user_id, const char* = "");
    void ShowWinner(int = -1);
    void StatusBarMsg(const char*);
    
private slots:
    void on_hit_button_clicked();
    void on_stand_button_clicked();
    void on_restart_button_clicked();

private:
    void EnableTurnButtons();
    void DisableTurnButtons();
};
