#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Score.h"



extern Game * game;//extern global object

Bullet::Bullet()  {
    setPixmap(textureSetter.bullet_txt(1));

    QTimer *timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(move()));
    timer3->start(100);
}

void Bullet::move()
{
    setPos(x(), y() - 50);
    QList<QGraphicsItem *> items = scene()->items(); // collision detection (bullet & enemy)
    QList<Enemy *> enemiesToRemove; // list of enemies to delete
    bool bulletHit = false; // if bullet hit enemy

    for (auto &item : items) {
        Enemy *enemy = dynamic_cast<Enemy *>(item);
        if (enemy && collidesWithItem(enemy)) {
            qDebug() << "Bullet hit enemy!";
            enemiesToRemove.append(enemy); // add enemy to delete
            bulletHit = true; // bullet hit enemy
            game->score->increase(enemy); // Increase score
        }
    }

    // delete enemies from scene
    for (Enemy *enemy : enemiesToRemove) {
        scene()->removeItem(enemy);
        delete enemy; // delete enemy object
    }

    // if bullet hit enemy or out of map - delete
    if (bulletHit || pos().y() < 0) {
        scene()->removeItem(this);
        delete this; // delete bullet
    }
}




