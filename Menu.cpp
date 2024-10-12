#include "Menu.h"

Menu::Menu(QWidget *parent)
{
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter();//constructor of textures

    scene = new QGraphicsScene(0,0,x_pos,y_pos);//scene creating
    setScene(scene);

    QPixmap background = texture_setter->menu_txt(1);//background from Texture_setter
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(background);
    backgroundItem->setPos(0, 0);
    scene->addItem(backgroundItem);

    setFixedSize(x_pos,y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Create buttons
    startButton = new QPushButton("Start Game", this);
    exitButton = new QPushButton("Exit Game", this);
    scoreButton = new QPushButton("Scoreboard",this);
    infoButton = new QPushButton("Instruction",this);

    //sizes
    int  button_x=350;
    int button_y=75;
    int button_gap=7;

    //style of button
    startButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    exitButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    scoreButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    infoButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");

    //Position and size
    startButton->setGeometry(QRect(QPoint(x_pos / 2 - button_x/2, y_pos / 6 - button_y), QSize(button_x, button_y)));
    infoButton->setGeometry(QRect(QPoint(x_pos / 2 - button_x/2, y_pos / 6 +button_gap), QSize(button_x, button_y)));
    scoreButton->setGeometry(QRect(QPoint(x_pos / 2 - button_x/2, y_pos / 6 +button_y+2*button_gap), QSize(button_x, button_y)));
    exitButton->setGeometry(QRect(QPoint(x_pos / 2 - button_x/2, y_pos / 6 + 2*button_y+3*button_gap), QSize(button_x, button_y)));

    //Connect exact button with method - used reference
    connect(startButton, &QPushButton::clicked, this, &Menu::startGame);
    connect(exitButton, &QPushButton::clicked, this, &Menu::exitGame);
    connect(infoButton, &QPushButton::clicked, this, &Menu::infoGame);
    connect(scoreButton, &QPushButton::clicked, this, &Menu::scoreGame);
}

void Menu::startGame()//method start game
{
    qDebug("Game Started!");
}

void Menu::exitGame()//method exit game
{
    qDebug("Turned off...");
    QApplication::quit();
}

void Menu::infoGame()//method instruction game
{
    qDebug("Instruction!");
}

void Menu::scoreGame()//method scoreboard
{
    qDebug("Scoreboard!");
}
