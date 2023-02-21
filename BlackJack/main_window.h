#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_interface.h"
#include <string>
#include "Game.h"

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(Game* game = new Game(), QWidget* parent = nullptr);
    ~main_window();

private slots:
    void on_hit_button_clicked();
    void on_stand_button_clicked();
    void on_restart_button_clicked();

private:
    Ui::main_windowClass _ui;
    Game* _game;
};
