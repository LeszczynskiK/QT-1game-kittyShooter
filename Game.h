#pragma once
#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QTimer>
#include "Character.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Score.h"
#include "Texture_setter.h"
#include "Map_setter.h"
#include "Shop.h"
#include "Score_record.h"
#include "Score.h"
#include "Menu.h"
class Score;//forward declaration to fix problem with include issues
class Character;//full daclaration is in other file
class Shop;//preinitialisation
class Enemy;
class Bullet;


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent=0,int charTaken=0);
    ~Game();
    Menu *menu;
    Texture_setter *textureSetter;
    QGraphicsScene *scene;
    Character *character;
    Score *score;
    Texture_setter *texture_setter;
    Enemy *enemy;
    Map_setter *map_setter;
    Bullet *bullet;
    Shop *shop;
    Game *game;
    Score_record *scoreRecord;
    void togglePause();
    void shopUse();
    int charTaken;
    QPushButton *pauseButton;//button for pause
    bool isPaused;//for pause toggle
    QTimer *gameTimer;//pause usage
    void spawnEnemy();
    QPushButton *shopButton;
    void updateMap();
private:

};

#endif // GAME_H
