#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "Enemy.h"
class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
