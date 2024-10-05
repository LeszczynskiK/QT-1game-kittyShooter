#ifndef CHARACTER_H
#define CHARACTER_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <iostream>

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Character(int size_x,int size_y);
public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // CHARACTER_H
