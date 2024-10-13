#pragma once
#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include "Enemy.h"


class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent =0);
    void increase(Enemy *enemy);
    int getScore();
    int point_tab[10];
    void decreaseLives();//method - if enemy is below y max , -1 heart
    void updateLivesDisplay();//show current lives
    void updateDisplay();//show points AND hearts
private:
    int score;
    Enemy *enemy;
    int lives;
    QGraphicsTextItem *scoreTextItem;//score object
    QGraphicsTextItem *livesTextItem;//lives object

};

#endif // SCORE_H
