#pragma once
#ifndef START_GAME_H
#define START_GAME_H
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <QPushButton>//button library
#include "Character.h"
#include "Texture_setter.h"
#include "Character.h"
#include "Game.h"
using namespace std;

class Start_game : public QGraphicsView
{
public:
    Start_game(QWidget *parent=0);
    ~Start_game();
    int char_taken;
    Game *game;
public slots:
    void returnToMenu();
    void char1_fun();//method depends from character taken number
    void char2_fun();
    void char3_fun();
private:
    QGraphicsScene *scene;
    Texture_setter *texture_setter;
    QPushButton *backButton;
    QPushButton *char1Button;
    QPushButton *char2Button;
    QPushButton *char3Button;
    Character *character;
};

#endif // START_GAME_H
