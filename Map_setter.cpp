#include "Map_setter.h"

Map_setter::Map_setter() {

}

void Map_setter::choose_map(QGraphicsScene *scene_back,int x,int y)
{
    QPixmap background1("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map1.jpeg");
    QPixmap background2("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map2.jpeg");
    QPixmap background3("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map3.jpeg");
    QPixmap background4("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map4.jpeg");
    QPixmap background5("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map5.jpeg");
    QPixmap background6("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map6.jpeg");
    QPixmap background7("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map7.jpeg");
    QPixmap background8("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map8.jpeg");
    QPixmap background9("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map9.jpeg");
    QPixmap background10("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map10.jpeg");

    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(background1.scaled(x,y));
    background->setPos(0,0);//put corner of photo in the beginign of scene
    scene_back->addItem(background);
    background->setZValue(-1);//put background behind all

}
