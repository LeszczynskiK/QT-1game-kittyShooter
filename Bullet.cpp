#include "Bullet.h"

Bullet::Bullet() {
    setPixmap(textureSetter.bullet_txt(1));

    QTimer *timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(move()));
    timer3->start(250);
}

void Bullet::move()
{
    setPos(x(),y()-30);

    QList<QGraphicsItem *> items = scene()->items(); // collision detection (bullet & enemy)
    QList<Enemy *> enemiesToRemove; // lista do usunięcia

    for (auto &item : items) {
        Enemy *enemy = dynamic_cast<Enemy *>(item);
        if (enemy) {
            if (collidesWithItem(enemy)) {
                enemiesToRemove.append(enemy); // dodajemy do listy do usunięcia
            }
        }
    }

    // Usuwamy wrogów z sceny
    for (Enemy *enemy : enemiesToRemove) {
        scene()->removeItem(enemy);
        delete enemy; // usuwamy obiekt
    }

    if(pos().y() <0)//if bullet is out of screen - delete
    {
        scene()->removeItem(this);
        delete this;
    }
}
