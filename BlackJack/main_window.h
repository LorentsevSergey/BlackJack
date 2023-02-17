#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_interface.h"

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

private:
    Ui::main_windowClass ui;
};
