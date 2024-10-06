#include "Map_setter.h"

Map_setter::Map_setter() {

}

void Map_setter::choose_map(QGraphicsScene *scene_back,int x,int y)
{
    QPixmap background[10];//maps table
    background[0]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map10.jpg");
    background[1] =QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map1.jpg");
    background[2]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map2.jpg");
    background[3]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map3.jpg");
    background[4]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map4.jpg");
    background[5]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map5.jpg");
    background[6]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map6.jpg");
    background[7]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map7.jpg");
    background[8]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map8.jpg");
    background[9]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map9.jpg");

    QGraphicsPixmapItem *backG = new QGraphicsPixmapItem(background[7].scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation));
    backG->setPos(0,0);//put corner of photo in the beginign of scene
    scene_back->addItem(backG);
    backG->setZValue(-1);//put background behind all

}
