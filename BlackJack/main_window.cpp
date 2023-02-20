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

void main_window::on_hit_button_clicked()
{

}

void main_window::on_stand_button_clicked()
{
}

void main_window::on_restart_button_clicked()
{
    ui.dealer_card_1->setPixmap(gangsta_cards.take_card());
    // make a variable card from constant 
    Card* dealer_card_2 = new Card (gangsta_cards.take_card());
    // and turn it over
    dealer_card_2->turn_over();
    ui.dealer_card_2->setPixmap(*dealer_card_2);

    ui.player1_card_1->setPixmap(gangsta_cards.take_card());
    ui.player1_card_2->setPixmap(gangsta_cards.take_card());

    ui.player2_card_1->setPixmap(gangsta_cards.take_card());
    ui.player2_card_2->setPixmap(gangsta_cards.take_card());
}