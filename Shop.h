#pragma once
#ifndef SHOP_H
#define SHOP_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include "Character.h"
#include "Texture_setter.h"
#include "Score.h"
class Character;//preinitialisation to solfe problem with include Character
class Score;

class Shop : public QGraphicsView
{
public:
    Character *character;
    Shop(QWidget *parent=0, Score *score = nullptr, Character *character = nullptr);//poiter in constructor to other object which i use in methos
    Texture_setter *texture_setter;
    QGraphicsScene *scene;
    void returnToMenu();
    QPushButton *backButton;//back to game
    Score *score;

    //upgrade buttons and methods
    QPushButton *increaseSpeedUpButton;
    QPushButton *increaseSpeedDownButton;
    QPushButton *increaseHeartsButton;
    QPushButton *increaseMoneyButton;
    QPushButton *increaseSpeedLeftButton;
    QPushButton *increaseSpeedRightButton;
    void increaseSpeedUp();
    void increaseSpeedDown();
    void increaseSpeedLeft();
    void increaseSpeedRight();
    void increaseHearts();
    void increaseMoney();

};

#endif // SHOP_H
