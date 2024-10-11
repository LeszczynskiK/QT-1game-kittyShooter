
#include "Game.h"



Game::Game(QWidget *parent) {
    //size of screen
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter();//constructor of textures
    character = new Character(x_pos,y_pos);//constructor of main character

    //its important to set scene and view size, becouse positioning character without this
    //will not position in the proper place
    scene = new QGraphicsScene(0,0,x_pos,y_pos);//scene creating
    setScene(scene);
    setFixedSize(x_pos,y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addItem(character);//adding character to scene
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();

    enemy = new Enemy();//spawn enemy
    scene->addItem(enemy);

    score = new Score();
    scene->addItem(score);//construct a score object


    map_setter = new Map_setter();
    map_setter->setZValue(-1);//background - last layer
    scene->addItem(map_setter);
}
