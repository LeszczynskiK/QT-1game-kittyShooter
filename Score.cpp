#include "Score.h"
#include "Menu.h"
#include <iostream>
using namespace std;

Score::Score(QGraphicsItem *parent,Game *game,int money_bonus,int lives) :QGraphicsTextItem(parent),game(game),money_bonus(1), lives(5)//initialize
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
    deathTextItem = new QGraphicsTextItem(this); //create object for death message

    scoreTextItem->setDefaultTextColor(Qt::yellow); //points colour
    scoreTextItem->setFont(QFont("Arial", 36)); //points font size

    livesTextItem->setDefaultTextColor(Qt::black); //heart colour
    livesTextItem->setFont(QFont("Arial", 36)); //heart font size

    deathTextItem->setDefaultTextColor(Qt::red);//death message colour
    deathTextItem->setFont(QFont("Arial", 185));//death message font size
    deathTextItem->setPlainText(""); //initially empty - fill with text after losing

    updateDisplay();
    deathTimer = new QTimer(this);//initialize on the beginning
    connect(deathTimer, &QTimer::timeout, this, &Score::returnToMenu);
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

    score=score + reward_points*money_bonus;
    qDebug() << "Reward:" << reward_points;
    qDebug() << "Bonus:" << money_bonus;
    qDebug() << "Hearts:" << lives;

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
    else
    {
        qDebug("hearts below 0!");
        //here is place to go back to menu after being informed about the end of game
        deathTextItem->setPlainText("You Died!!!");
        deathTextItem->setPos(75, 270);//set pos of message about losing game
        this->scene()->addItem(deathTextItem);
        deathTimer->start(5000);//after 5 sec after death, go to main menu
    }
    updateDisplay(); //update hearts amount
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

void Score::returnToMenu()
{
    game->close();
    menu = new Menu();
    menu->show();
}
