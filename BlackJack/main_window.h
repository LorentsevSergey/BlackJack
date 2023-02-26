#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_interface.h"
#include "Global.h"
#include "Game.h"

const int maxCards{ 5 };
class Game;

class main_window : 
    public QMainWindow
{
    Q_OBJECT
private:
    Ui::main_windowClass _ui;
    Game* _game;
    QPixmap _clr_map; // for clear card labels
    QLabel* _d_cards[maxCards]; // dealer card labels
    QLabel* _p_cards[maxCards]; // player card labels

public:
    main_window(Game*, QWidget* parent = nullptr);

    void ShowDealerCards(std::vector<const char*>);
    void ShowPlayerCards(std::vector<const char*>);
    void StatusBarMsg(const char*);
    
    void ClrCardLabels();

private slots:
    void on_hit_button_clicked();
    void on_stand_button_clicked();
    void on_restart_button_clicked();
};
