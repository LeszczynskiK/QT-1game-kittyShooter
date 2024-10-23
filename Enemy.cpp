#include "Enemy.h"

Enemy::Enemy(int index,int slow_value,Game * gameInstance) : index_ran(index),slow_value(0), game(gameInstance){

    //timer to slots usage:
    int time_on_beg = 500;
    QTimer *timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(time_on_beg);
    }

void Enemy::move()//movement of enemy
{
    if (game && game->isPaused) {//if game exist and game is - stop game
        return;
    }
    int jump_value = 40-slow_value;
    setPos(x(),y()+jump_value);
    if (pos().y() > 768) // if enemy is out of screen
    {
        if (game) {//if pointer game exist
            game->score->decreaseLives(); // -1 serce
        }
        scene()->removeItem(this);
        this->deleteLater();//delete after cycle (safer than delete->this)
    }
}

int Enemy::get_index()
{
    return index_ran;
}
