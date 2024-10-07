#ifndef MAP_SETTER_H
#define MAP_SETTER_H
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Map_setter : public QGraphicsPixmapItem
{
public:
    Map_setter();
    static void initializeTextures(int x,int y);
private:
    static QPixmap texture[10];
};

#endif // MAP_SETTER_H
