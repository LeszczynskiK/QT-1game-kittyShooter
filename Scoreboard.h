#pragma once
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <QPushButton>//button library
#include "Texture_setter.h"

using namespace std;
class Score_record;

class Scoreboard : public QGraphicsView
{
    Q_OBJECT
public:
    Scoreboard(QWidget *parent=0);
    void displayScores();
    Score_record *scoreRecord;
public slots:
    void returnToMenu();
private:
    QGraphicsScene *scene;
    Texture_setter *texture_setter;
    QPushButton *backButton;
};

#endif // SCOREBOARD_H
