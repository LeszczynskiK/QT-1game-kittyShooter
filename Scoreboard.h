#ifndef SCOREBOARD_H
#define SCOREBOARD_H
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

class Scoreboard : public QGraphicsView
{
public:
    Scoreboard();
};

#endif // SCOREBOARD_H
