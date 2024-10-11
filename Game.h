#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Bullet.h"
#include "Character.h"
#include "Enemy.h"
#include "Map_setter.h"
#include "Score.h"
#include "Texture_setter.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent=0);
    QGraphicsScene *scene;
    Character *character;
    Score *score;
    Texture_setter *texture_setter;
    Enemy *enemy;
    Map_setter *map_setter;
    Bullet *bullet;


};

#endif // GAME_H
