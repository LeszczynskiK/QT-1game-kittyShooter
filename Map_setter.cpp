#include "Map_setter.h"

QPixmap Map_setter::texture[10];

void Map_setter::initializeTextures(int x,int y)
{
    QPixmap background[10];//maps table
    texture[0]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map10.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[1] =QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map1.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[2]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map2.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[3]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map3.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[4]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map4.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[5]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map5.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[6]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map6.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[7]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map7.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[8]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map8.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[9]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map9.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);

}

Map_setter::Map_setter() {
    setPixmap(texture[3]);
}


