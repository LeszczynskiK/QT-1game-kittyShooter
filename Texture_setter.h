#pragma once
#ifndef TEXTURE_SETTER_H
#define TEXTURE_SETTER_H
#include <QPixmap>
#include <QGraphicsPixmapItem>
using namespace std;

class Texture_setter : public QGraphicsPixmapItem
{
public:
    Texture_setter();
    QPixmap bullet_txt(int nr);
    QPixmap character_txt(int nr);
    QPixmap enemy_txt(int nr);
    QPixmap map_txt(int nr);
    QPixmap menu_txt(int nr);
    QPixmap score_txt(int nr);
    QPixmap instruction_txt(int nr);
    QPixmap start_txt(int nr);
    QPixmap shop_txt(int nr);

};

#endif // TEXTURE_SETTER_H
