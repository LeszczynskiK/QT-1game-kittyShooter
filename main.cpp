#include <QApplication>
#include "Game.h"
#include "Menu.h"
using namespace std;

//size of screen
const int x_pos = 1366;
const int y_pos = 768;
Game *game;
Menu *menu;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menu = new Menu();
    menu->show();

    return a.exec();
}
