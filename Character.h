#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include "Texture_setter.h"
#include "Score.h"
#include "Game.h"

class Score;
class Game;
extern Game *game;

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Character(int size_x,int size_y,int charTaken,Game* gameInstance,int speed_left,int speed_right,int speed_up,int speed_down);
    void setChar(int charTaken);
    int speed_left;//variables which upgrade speed bought in shop
    int speed_right;
    int speed_up;
    int speed_down;
public slots:
    void keyPressEvent(QKeyEvent *event);
private:
    Texture_setter textureSetter;
    Score *score;
    int character_txt;//number of character choosen in start_game
    Game *game;


};

#endif // CHARACTER_H
