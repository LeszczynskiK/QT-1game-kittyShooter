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
private:
    int score;
    Enemy *enemy;

};

#endif // SCORE_H
