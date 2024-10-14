#pragma once
#ifndef SHOP_H
#define SHOP_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include "Texture_setter.h"

class Shop : public QGraphicsView
{
public:
    Shop(QWidget *parent=0);
    Texture_setter *texture_setter;
    QGraphicsScene *scene;
    void returnToMenu();
    QPushButton *backButton;
};

#endif // SHOP_H
