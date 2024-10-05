#include "Enemy.h"

Enemy::Enemy() {//types of enemy textures
    // load textures to board to make acces to them in class method
    enemyTextures[0] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food1.jpeg").scaled(100,100);
    enemyTextures[1] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food2.jpeg").scaled(100,100);
    enemyTextures[2] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food3.jpeg").scaled(100,100);
    enemyTextures[3] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food4.jpeg").scaled(100,100);
    enemyTextures[4] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food5.jpeg").scaled(100,100);
    enemyTextures[5] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food6.jpeg").scaled(100,100);
    enemyTextures[6] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food7.jpeg").scaled(100,100);
    enemyTextures[7] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food8.jpeg").scaled(100,100);
    enemyTextures[8] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food9.jpeg").scaled(100,100);
    enemyTextures[9] = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food10.jpeg").scaled(100,100);

    //timer to slots usage:
    QTimer *timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(spawn()));
    timer1->start(1250);
    }

void Enemy::move()
{

}

void Enemy::spawn()
{
    srand(time(NULL));
    int ran_x = rand()%1366;//random x pos
    int ran_y = rand()%350;//random y pos
    int index =rand()%10;//random index of enemy texture
    setPixmap(enemyTextures[index].scaled(100,100));
    setPos(ran_x,ran_y);

}
