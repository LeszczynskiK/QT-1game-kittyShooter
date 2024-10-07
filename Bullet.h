#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "Enemy.h"
#include <iostream>
using namespace std;

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Bullet();
    static void initializeTextures();
public slots:
    void move();
private:
    static QPixmap texture;//static - all bullets the same texture, not loading new
};

#endif // BULLET_H
