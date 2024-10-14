#include "Game.h"

Game::Game(QWidget *parent,int charTaken) : QGraphicsView(parent), charTaken(charTaken) {
    //size of screen
    qDebug("Game constructor called with charTaken: %d", charTaken);
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter();//constructor of textures
    character = new Character(x_pos, y_pos, charTaken);
    if (!character) {
        qDebug("Failed to create Character!");
    }
    character->setChar(charTaken);

    //bullet = nullptr;//not initialised in this constructor, so need to add this

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

    enemy = new Enemy(0);//spawn enemy - index0 - starting enemy
    if (!enemy) {
        qDebug("Failed to create Enemy!");
    }
    scene->addItem(enemy);

    score = new Score(nullptr,this);//this->Game
    if (!score) {
        qDebug("Failed to create Score!");
    }
    scene->addItem(score);//construct a score object


    map_setter = new Map_setter();
    map_setter->setZValue(-1);//background - last layer
    scene->addItem(map_setter);
}
Game::~Game() {//destructor
    delete character;
    delete enemy;
    delete score;
    delete texture_setter;
    delete map_setter;
    if (enemy) {
        delete enemy;
        enemy = nullptr;
    }
    if (score) {
        delete score;
        score = nullptr;
    }
    if (character) {
        delete character;
        character = nullptr;
    }
    if (texture_setter) {
        delete texture_setter;
        texture_setter = nullptr;
    }
    if (map_setter) {
        delete map_setter;
        map_setter = nullptr;
    }
    qDebug("Destructor worked!");
}

void Game::closeEvent(QCloseEvent *event) {
    qDebug("Game window is about to close.");
    event->ignore();
}
