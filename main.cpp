#include <QApplication>
#include "Game.h"
using namespace std;

//size of screen
const int x_pos = 1366;
const int y_pos = 768;
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game ->show();

    return a.exec();
}
