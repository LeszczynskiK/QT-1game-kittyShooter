#include "Bullet.h"

Bullet::Bullet() {
    QPixmap bullett_text("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/paw1.png");
    setPixmap(bullett_text.scaled(57,57,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QTimer *timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(move()));
    timer3->start(250);
}

void Bullet::move()
{
    setPos(x(),y()-30);

    QList<QGraphicsItem *> items = scene()->items();//collision detection (bullet & enemy)
    for(auto &item : items)
    {
        Enemy *enemy = dynamic_cast<Enemy *>(item);
        if(enemy)
        {
            if(collidesWithItem(enemy))
            {
                scene()->removeItem(enemy);
                delete enemy;
                scene()->removeItem(this);
                delete this;//this -> bullet
            }
        }
    }

    if(pos().y() <0)//if bullet is out of screen - delete
    {
        scene()->removeItem(this);
        delete this;
    }
}
