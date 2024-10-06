#include "Enemy.h"

Enemy::Enemy() {//types of enemy textures
    // load textures to board to make acces to them in class method
    enemyTextures[0] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food1.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[1] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food2.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[2] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food3.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[3] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food4.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[4] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food5.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[5] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food6.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[6] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food7.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[7] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food8.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[8] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food9.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    enemyTextures[9] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food10.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);

    //timer to slots usage:
    QTimer *timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(spawn()));
    timer1->start(2500);

    int time_on_beg = 650;
    QTimer *timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(time_on_beg);
    }

void Enemy::move()//movement of enemy
{
    int jump_value = 20;
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
    int index =rand()%10;//random index of enemy texture

    Enemy *newEnemy = new Enemy();
    newEnemy->setPixmap(enemyTextures[index].scaled(100,100));
    newEnemy->setPos(ran_x,ran_y);
    scene()->addItem(newEnemy);
}
