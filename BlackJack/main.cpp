#pragma once
#include "main_window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

    Game g(PLAYER_START_CASH);
    main_window w;
    GameUI gameUI(&g, &w);

    w.show();
    return a.exec();
}
