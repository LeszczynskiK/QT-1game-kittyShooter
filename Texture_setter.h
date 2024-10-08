#ifndef TEXTURE_SETTER_H
#define TEXTURE_SETTER_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>
using namespace std;

class Texture_setter : public QGraphicsPixmapItem
{
public:
    Texture_setter();
    QPixmap bullet_txt(int nr);
    QPixmap character_txt(int nr);
    QPixmap enemy_txt(int nr);
    QPixmap map_txt(int nr);

};

#endif // TEXTURE_SETTER_H
