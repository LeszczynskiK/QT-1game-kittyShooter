#pragma once
#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Character.h"
#include "Enemy.h"
#include "Map_setter.h"
#include "Bullet.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=0,int charTaken=0);
    QGraphicsScene *scene;
    Character *character;
    Score *score;
    Texture_setter *texture_setter;
    Enemy *enemy;
    Map_setter *map_setter;
    Bullet *bullet;
    void setCharacter(int charType);
private:
    int charTaken;
};

#endif // GAME_H
