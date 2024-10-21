#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Bullet.h"
#include "Enemy.h"
#include "Score.h"

extern Game * game;//extern global object

Bullet::Bullet(Game* gameInstance) : game(gameInstance)  {
    setPixmap(textureSetter.bullet_txt(1));

    QTimer *timer3 = new QTimer(this);//this - timer is kid of parent(parent can be for example bullet)
    //if bullet disappear, timer also disapear so it will free memory
    //lags also were made becouse timer was nos free when item was deleted.... this save memory
    connect(timer3,SIGNAL(timeout()),this,SLOT(move()));
    timer3->start(100);
}

void Bullet::move()
{
    if (game->isPaused) {
        return;//if paused - stop object
    }
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
        enemy->deleteLater(); // delete enemy object
    }

    // if bullet hit enemy or out of map - delete
    if (bulletHit || pos().y() < 0) {
        scene()->removeItem(this);
        this->deleteLater(); // delete bullet
        //deletelater - when slot and signal is done - delete
    }
}




