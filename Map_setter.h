#ifndef MAP_SETTER_H
#define MAP_SETTER_H
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "Texture_setter.h"

class Map_setter : public QGraphicsPixmapItem
{
public:
    Map_setter();
private:
    Texture_setter textureSetter;
};

#endif // MAP_SETTER_H
