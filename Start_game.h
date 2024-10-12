#ifndef START_GAME_H
#define START_GAME_H
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <iostream>
#include <QPushButton>//button library
#include "Character.h"
#include "Texture_setter.h"
#include "Menu.h"
using namespace std;

class Start_game : public QGraphicsView
{
public:
    Start_game(QWidget *parent=0);
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
};

#endif // START_GAME_H
