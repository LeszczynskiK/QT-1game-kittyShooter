#ifndef CHARACTER_H
#define CHARACTER_H
#include "Bullet.h"
#include "Texture_setter.h"
#include "Score.h"
#include "Game.h"
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <iostream>

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Character(int size_x,int size_y);
public slots:
    void keyPressEvent(QKeyEvent *event);
private:
    Texture_setter textureSetter;
    Score *score;

};

#endif // CHARACTER_H
