#include "Start_game.h"

Start_game::Start_game(QWidget *parent) : QGraphicsView(parent)
{
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter(); //texture constructor

    scene = new QGraphicsScene(0, 0, x_pos, y_pos); //create scene for instruction
    setScene(scene);

    QPixmap background = texture_setter->start_txt(1); //set texture background
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(background);
    backgroundItem->setPos(0, 0);
    scene->addItem(backgroundItem);

    setFixedSize(x_pos, y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create buttons
    backButton = new QPushButton("Menu", this);
    char1Button = new QPushButton("Char.1", this);
    char2Button = new QPushButton("Char.2", this);
    char3Button = new QPushButton("Char.3", this);
    int button_x=140;
    int button_y=90;
    int gap=60;

    backButton->setGeometry(QRect(QPoint(x_pos-gap-button_x, 0 + gap), QSize(button_x, button_y)));
    backButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(backButton, &QPushButton::clicked, this, &Start_game::returnToMenu);

    char1Button->setGeometry(QRect(QPoint(gap,y_pos*7/8 ), QSize(button_x, button_y)));
    char1Button->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(char1Button, &QPushButton::clicked, this, &Start_game::char1_fun);

    char2Button->setGeometry(QRect(QPoint(button_x + 2*gap,y_pos*7/8 ), QSize(button_x, button_y)));
    char2Button->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(char2Button, &QPushButton::clicked, this, &Start_game::char2_fun);

    char3Button->setGeometry(QRect(QPoint(2*button_x + 3*gap,y_pos*7/8 ), QSize(button_x, button_y)));
    char3Button->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(char3Button, &QPushButton::clicked, this, &Start_game::char3_fun);

}

void Start_game::returnToMenu() {
    this->close(); //close instruction
    Menu *menuWindow = new Menu(); //open menu
    menuWindow->show(); //show
    qDebug("Menu");

}

void Start_game::char1_fun()
{
    qDebug("Char1");

}

void Start_game::char2_fun()
{
    qDebug("Char2");

}

void Start_game::char3_fun()
{
    qDebug("Char3");

}