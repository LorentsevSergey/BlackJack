#pragma once
#include "main_window.h"
#include <QtWidgets/QApplication>

// global container for keeping all decks
std::vector<Deck> all_decks;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    main_window w;
    w.show();
    return a.exec();
}
