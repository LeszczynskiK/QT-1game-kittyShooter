#include "Game.h"

Game::Game(QWidget *parent,int charTaken) : QGraphicsView(parent), charTaken(charTaken) {
    //size of screen
    qDebug("Game constructor called with charTaken: %d", charTaken);
    const int x_pos = 1366;
    const int y_pos = 768;
    int button_x=90;
    int button_y=55;
    int gap=15;

    //pause button setting
    pauseButton = new QPushButton("Pause", this);
    pauseButton->setGeometry(QRect(QPoint(x_pos-gap-button_x, 0 + gap), QSize(button_x, button_y)));
    pauseButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;"); //
    connect(pauseButton, &QPushButton::clicked, this, &Game::togglePause);

    //shop button setting
    shopButton = new QPushButton("Shop", this);
    shopButton->setGeometry(QRect(QPoint(x_pos-gap-button_x, 0 + 2*gap+button_y), QSize(button_x, button_y)));
    shopButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;"); //
    connect(shopButton, &QPushButton::clicked, this, &Game::shopUse);

    texture_setter = new Texture_setter();//constructor of textures
    character = new Character(x_pos, y_pos, charTaken,0,0,0,0);
    if (!character) {
        qDebug("Failed to create Character!");
    }

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

    scoreRecord = new Score_record(0);//initialise score_record

    enemy = new Enemy(0,1);//spawn enemy - index0,slow value - starting enemy
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
    if (scoreRecord) {
        delete scoreRecord;
        scoreRecord = nullptr;
    }
    qDebug("Destructor worked!");
}

void Game::togglePause() {
    isPaused = !isPaused;//toggle pause state
    pauseButton->setText(isPaused ? "Resume" : "Pause");//change word on button if true/falsce
    if (isPaused) {
        qDebug("Game paused.");
    } else {
        qDebug("Game resumed.");
    }
}

void Game::shopUse()//open shop...
{
    qDebug("Shop is working...");
    if (!shop) {//if no shop, create new one
        shop = new Shop(nullptr, score, character, enemy);
        shop->show();
    }
    togglePause();//shop opened/closed - use pauze machanism
}


