#include "Score.h"

Score::Score(QGraphicsItem *parent) :QGraphicsTextItem(parent), lives(5)//initialize
{
    score =0;//start score

    point_tab[0] = 1;
    point_tab[1] = 1;
    point_tab[2] = 2;
    point_tab[3] = 1;
    point_tab[4] = 2;
    point_tab[5] = 3;
    point_tab[6] = 4;
    point_tab[7] = 7;
    point_tab[8] = 2;
    point_tab[9] = 5;

    scoreTextItem = new QGraphicsTextItem(this); //create object for score
    livesTextItem = new QGraphicsTextItem(this); //create object for lives

    scoreTextItem->setDefaultTextColor(Qt::yellow); //points colour
    scoreTextItem->setFont(QFont("Arial", 36)); //points font size

    livesTextItem->setDefaultTextColor(Qt::black); //heart colour
    livesTextItem->setFont(QFont("Arial", 36)); //heart font size

    updateDisplay();
}

void Score::increase(Enemy *enemy)
{
    if(enemy){
    int ind=enemy->get_index();
    int reward_points;
    switch(ind)//reward depends on food type
    {
    case 1:
        reward_points = point_tab[0];
        break;
    case 2:
        reward_points = point_tab[1];
        break;
    case 3:
        reward_points = point_tab[2];
        break;
    case 4:
        reward_points = point_tab[3];
        break;
    case 5:
        reward_points = point_tab[4];
        break;
    case 6:
        reward_points = point_tab[5];
        break;
    case 7:
        reward_points = point_tab[6];
        break;
    case 8:
        reward_points = point_tab[7];
        break;
    case 9:
        reward_points = point_tab[8];
        break;
    case 10:
        reward_points = point_tab[9];
        break;
    default:
        reward_points = 0;
        break;
    }

    score=score + reward_points;
    cout<<"Reward: "<<reward_points<<endl;
    updateDisplay();
    }

}

int Score::getScore()
{
    return score;
}

void Score::decreaseLives() {
    if (lives > 0) {//if lives are ok
        lives--;//decrease
    }
    updateLivesDisplay(); //update hearts amount
}

void Score::updateLivesDisplay() {
    setPlainText(QString("Score :" + QString::number(score) + " | Hearts: " + QString::number(lives)));
}

void Score::updateDisplay() {//show points and hearts in different lines
    scoreTextItem->setPlainText(QString("Score: ") + QString::number(score));//points text
    livesTextItem->setPlainText(QString("Lives: ") + QString::number(lives));//lives text

    scoreTextItem->setPos(10, 10); //score text pos
    livesTextItem->setPos(10, 65); //lives text pos
}
