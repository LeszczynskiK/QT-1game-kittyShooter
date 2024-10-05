#ifndef MAP_SETTER_H
#define MAP_SETTER_H
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Map_setter
{
public:
    Map_setter();
    void choose_map(QGraphicsScene *scene_back,int x,int y);
};

#endif // MAP_SETTER_H
