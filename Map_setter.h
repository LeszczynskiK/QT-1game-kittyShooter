#pragma once
#ifndef MAP_SETTER_H
#define MAP_SETTER_H
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "Texture_setter.h"



class Score;
class Map_setter : public QGraphicsPixmapItem
{
public:
    Map_setter(Score *score);
    Score *score;
    int map_update_value;
    void changeMap();
private:
    Texture_setter textureSetter;
    int map[10]={-1,50,125,350,790,1250,1900,3000,5000,10001};
};

#endif // MAP_SETTER_H
