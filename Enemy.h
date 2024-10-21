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
#include "Texture_setter.h"
#include "Game.h"

class Game;//initial declaration - to fix resursive adding at Enemy
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Game *game;
    Enemy(int index,int slow_value=0,Game *gameInstance=nullptr);
    int index_ran;
    int get_index();
    int slow_value;
public slots:
    void move();
private:
    Texture_setter textureSetter;

};

#endif // ENEMY_H
