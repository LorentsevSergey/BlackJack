#pragma once
#include "main_window.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    const int plCash = 500;
    srand(time(NULL));
    QApplication a(argc, argv);
    Game g(plCash);
    main_window w(&g);
    w.show();
    return a.exec();
}
