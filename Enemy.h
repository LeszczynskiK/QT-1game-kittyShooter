#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <iostream>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Enemy();
public slots:
    void move();
    void spawn();
private:
    QPixmap enemyTextures[10];
};

#endif // ENEMY_H
