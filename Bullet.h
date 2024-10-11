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
    Q_OBJECT // Makro dla slotów i sygnałów
public:
    Bullet();
    int return_killed();
public slots:
    void move(); // Slot do ruchu pocisku

private:
    Texture_setter textureSetter; // Instancja metody
    int enemy_killed; // Liczba zabitych wrogów
};

#endif // BULLET_H
