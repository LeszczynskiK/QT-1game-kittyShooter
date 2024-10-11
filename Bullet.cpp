#include "Bullet.h"

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
    QList<Enemy *> enemiesToRemove; // list of enemy to delete
    bool bulletHit = false; // if bullet hit enemy

    for (auto &item : items) {
        Enemy *enemy = dynamic_cast<Enemy *>(item);
        if (enemy) {
            if (collidesWithItem(enemy)) {
                enemiesToRemove.append(enemy); // add enemy to delete
                bulletHit = true; // is enemy hit- let it know to bullet
            }
        }
    }

    // delete enemy from scene
    for (Enemy *enemy : enemiesToRemove) {
        scene()->removeItem(enemy);
        delete enemy; // delete object ( enemy)
    }

    // if bullet hit enemy or out of map - delete
    if (bulletHit || pos().y() < 0) {
        scene()->removeItem(this);
        delete this; // delete bullet
    }
}


