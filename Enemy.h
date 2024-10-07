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
    static void initializeTextures();
public slots:
    void move();
    void spawn();
private:
    static QPixmap texture[10];
};

#endif // ENEMY_H
