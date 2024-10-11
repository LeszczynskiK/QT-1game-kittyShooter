#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <iostream>
#include "Texture_setter.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Enemy(int index);
    int index_ran;
    int get_index();
public slots:
    void move();
    void spawn();
private:
    Texture_setter textureSetter;

};

#endif // ENEMY_H
