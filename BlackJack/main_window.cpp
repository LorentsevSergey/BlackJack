#include "main_window.h"

main_window::main_window(QWidget *parent)
    : QMainWindow(parent),
    gangsta_cards("gangsta_cards")
{
    ui.setupUi(this);
    //ui.refresh_button->clicked();
    
}

main_window::~main_window()
{}

void main_window::on_refresh_button_clicked()
{
    //ui.dealer_card_1->setPixmap(deck[0]);
    ui.dealer_card_2->setPixmap(gangsta_cards.take_card());
}