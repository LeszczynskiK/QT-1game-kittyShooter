#include "Score.h"

Score::Score(QGraphicsItem *parent) :QGraphicsTextItem(parent)
{
    score =0;//start score

    //print text
    setPlainText(QString("Score :" + QString::number(score)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Times", 25)); // Times New Roman with size 25}
}

void Score::increase()
{
    int reward_points=1;
    score=score + reward_points;

    setPlainText(QString("Score :" + QString::number(score)));

}

int Score::getScore()
{
    return score;
}
