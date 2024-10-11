#include "Score.h"

Score::Score(QGraphicsItem *parent) :QGraphicsTextItem(parent)
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

    //print text
    setPlainText(QString("Score :" + QString::number(score)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Times", 25)); // Times New Roman with size 25}
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
    setPlainText(QString("Score :" + QString::number(score)));
    }

}

int Score::getScore()
{
    return score;
}


