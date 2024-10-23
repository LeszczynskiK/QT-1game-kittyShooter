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
#include "Menu.h"
#include "Score.h"
#include "Score_record.h"

class Game;//initial declaration - to fix resursive adding at Enemy
class Menu;
class Score;
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Game *game;
    Score_record *scoreRecord;
    Enemy(int index,int slow_value=0,Game *gameInstance=nullptr);
    int index_ran;
    int get_index();
    int slow_value;
    Score *score;
public slots:
    void move();
private:
    Texture_setter textureSetter;

};

#endif // ENEMY_H
