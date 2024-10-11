#include "Enemy.h"

Enemy::Enemy() {

    //timer to slots usage:
    QTimer *timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(spawn()));
    timer1->start(2500);

    int time_on_beg = 500;
    QTimer *timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(time_on_beg);
    }

void Enemy::move()//movement of enemy
{
    int jump_value = 55;
    setPos(x(),y()+jump_value);
    if(pos().y() > 768)//if enemy is out of screen, delete from memory
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::spawn()//creating enemy
{
    srand(time(NULL));
    int ran_x = rand()%1200 +50;//random x pos ,+50 becouse not in x border
    int ran_y = rand()%150 + 40;//random y pos, +40 becouse not in y border
    index_ran =rand()%10;//random index of enemy texture

    Enemy *newEnemy = new Enemy();
    newEnemy->setPixmap(textureSetter.enemy_txt(index_ran));
    newEnemy->setPos(ran_x,ran_y);
    scene()->addItem(newEnemy);
    if(pos().y()>768)
    {
        scene()->removeItem(this);
        delete this;
    }
}

int Enemy::get_index()
{
    return index_ran;
}
