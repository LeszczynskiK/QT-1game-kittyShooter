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
class Score;//forward declaration to fix problem with include issues
class Character;//full daclaration is in other file
class Shop;//preinitialisation


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent=0,int charTaken=0);
    ~Game();
    QGraphicsScene *scene;
    Character *character;
    Score *score;
    Texture_setter *texture_setter;
    Enemy *enemy;
    Map_setter *map_setter;
    Bullet *bullet;
    Shop *shop;
    Score_record *scoreRecord;
    void togglePause();
    void shopUse();
    int charTaken;
    QPushButton *pauseButton;//button for pause
    bool isPaused;//for pause toggle
    QTimer *gameTimer;//pause usage
    QPushButton *shopButton;
private:

};

#endif // GAME_H
