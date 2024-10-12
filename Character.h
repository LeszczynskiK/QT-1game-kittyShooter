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
#include <iostream>
#include "Texture_setter.h"
#include "Score.h"
#include "Bullet.h"

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Character(int size_x,int size_y);
    void setChar(int charTaken);
public slots:
    void keyPressEvent(QKeyEvent *event);
private:
    Texture_setter textureSetter;
    Score *score;
    int character_txt;//number of character choosen in start_game

};

#endif // CHARACTER_H
