#pragma once
#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "Texture_setter.h"
using namespace std;

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT // makro signal and slots
public:
    Bullet();
public slots:
    void move(); // Slot for bullet move
private:
    Texture_setter textureSetter; // texture initialization
};

#endif // BULLET_H
