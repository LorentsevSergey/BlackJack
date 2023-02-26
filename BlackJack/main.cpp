#pragma once
#include "main_window.h"
#include <QtWidgets/QApplication>

// global container for keeping all decks
std::vector<Deck> all_decks;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Game g(500);
    main_window w(&g);
    w.show();
    return a.exec();
}
