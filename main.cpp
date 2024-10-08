#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <iostream>
#include "Character.h"
#include "Enemy.h"
#include "Map_setter.h"
#include "Bullet.h"
#include "Texture_setter.h"
using namespace std;

//size of screen
const int x_pos = 1366;
const int y_pos = 768;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Texture_setter *texture_setter = new Texture_setter();//constructor of textures


    Character *character = new Character(x_pos,y_pos);//constructor of main character

    //its important to set scene and view size, becouse positioning character without this
    //will not position in the proper place
    QGraphicsScene *scene = new QGraphicsScene(0,0,x_pos,y_pos);//scene creating
    scene->addItem(character);//adding character to scene
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();

    Enemy *enemy = new Enemy();//spawn enemy
    scene->addItem(enemy);


    Map_setter *map_setter = new Map_setter();
    map_setter->setZValue(-1);//background - last layer
    scene->addItem(map_setter);

    QGraphicsView *view = new QGraphicsView(scene);//view creating
    view ->setFixedSize(x_pos,y_pos);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return a.exec();
}
