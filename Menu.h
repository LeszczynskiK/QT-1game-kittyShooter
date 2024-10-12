#ifndef MENU_H
#define MENU_H
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
using namespace std;

class Menu : public QGraphicsView
{
    Q_OBJECT
public:
    Menu(QWidget *parent=0);
public slots:
    void startGame();//method - start game
    void exitGame();//method - exit game
    void infoGame();//method - go to instruction
    void scoreGame();//method - go to scoreboard

private:
    QGraphicsScene *scene;
    Character *character;
    Texture_setter *texture_setter;
    QPushButton *startButton;//start game
    QPushButton *exitButton;//exit game
    QPushButton *infoButton;//instruction about game
    QPushButton *scoreButton;//last scores, and best scores
};

#endif // MENU_H
