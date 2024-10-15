#pragma once
#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include <QTimer>
#include "Enemy.h"
#include "Menu.h"
#include "Game.h"
#include "Character.h"

class Character;//forward declaration
class Menu;

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent =0,Game *game=0,int money_bonus=1,int lives=5);
    void increase(Enemy *enemy);
    int getScore();
    int point_tab[10];
    void decreaseLives();//method - if enemy is below y max , -1 heart
    void updateLivesDisplay();//show current lives
    void updateDisplay();//show points AND hearts
    int money_bonus;
    int lives;
private:
    int score;
    Enemy *enemy;
    QGraphicsTextItem *scoreTextItem;//score object
    QGraphicsTextItem *livesTextItem;//lives object
    QGraphicsTextItem *deathTextItem;//death message object
    QTimer *deathTimer;
    Menu *menu;
    Game *game;
    Character *character;
public slots:
    void returnToMenu();

};

#endif // SCORE_H
