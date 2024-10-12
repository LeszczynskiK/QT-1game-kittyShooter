#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QObject>
#include <iostream>
#include <QFont>
#include <QPushButton>//button library
#include <string>
#include "Character.h"
#include "Texture_setter.h"
#include "Menu.h"
using namespace std;

class Instruction : public QGraphicsView
{
    Q_OBJECT
public:
    Instruction(QWidget *parent=0);
public slots:
    void returnToMenu();
private:
    QGraphicsScene *scene;
    Texture_setter *texture_setter;
    QPushButton *backButton;
};

#endif // INSTRUCTION_H
