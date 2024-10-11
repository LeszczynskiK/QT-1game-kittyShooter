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
    score++;
    setPlainText(QString("Score :" + QString::number(score)));

}

int Score::getScore()
{
    return score;
}
