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
using namespace std;

class Start_game : public QGraphicsView
{
public:
    Start_game();
};

#endif // START_GAME_H
