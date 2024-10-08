#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "Enemy.h"
#include "Texture_setter.h"
#include <iostream>
using namespace std;

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Bullet();
public slots:
    void move();
private:
    Texture_setter textureSetter;//instance of method
};

#endif // BULLET_H
