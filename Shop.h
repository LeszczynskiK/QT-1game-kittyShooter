#pragma once
#ifndef SHOP_H
#define SHOP_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsTextItem>
#include "Character.h"
#include "Texture_setter.h"
#include "Score.h"
class Character;//preinitialisation to solve problem with include " class "
class Score;
class Enemy;

class Shop : public QGraphicsView
{
public:
    Character *character;
    Shop(QWidget *parent=0, Score *score = nullptr, Character *character = nullptr,Enemy *enemy=nullptr);//poiter in constructor to other object which i use in methos
    Texture_setter *texture_setter;
    QGraphicsScene *scene;
    void returnToMenu();
    QPushButton *backButton;//back to game
    Score *score;
    Enemy *enemy;
    int MAX_SPEED=20;
    int MAX_SLOWNESS=20;
    int MAX_HP=5;
    int MAX_MONEY_X=10;
    int SPEED_COST_UPGRADE=15;
    int SLOWNESS_COST_UPGRADE=30;
    int HP_COST_UPGRADE =40;
    int MONEY_X_COST_UPGRADE=10;
    //upgrade buttons and methods
    QPushButton *increaseSpeedUpButton;
    QPushButton *increaseSpeedDownButton;
    QPushButton *increaseHeartsButton;
    QPushButton *increaseMoneyButton;
    QPushButton *increaseSpeedLeftButton;
    QPushButton *increaseSpeedRightButton;
    QPushButton *slowDownEnemyButton;
    void increaseSpeedUp();
    void increaseSpeedDown();
    void increaseSpeedLeft();
    void increaseSpeedRight();
    void increaseHearts();
    void increaseMoney();
    void slowDownEnemy();
    void updateDisplay();//update variable from shop on the screen
private:
    //variable display - these from shop upgrade
    QGraphicsTextItem *livesTextItem;
    QGraphicsTextItem *moneyTextItem;
    QGraphicsTextItem *speedUpTextItem;
    QGraphicsTextItem *speedDownTextItem;
    QGraphicsTextItem *speedLeftTextItem;
    QGraphicsTextItem *speedRightTextItem;
    QGraphicsTextItem *slowDownEnemyTextItem;

};

#endif // SHOP_H
