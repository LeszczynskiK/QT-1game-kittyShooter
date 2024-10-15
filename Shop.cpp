#include "Shop.h"
#include "Menu.h"

Shop::Shop(QWidget *parent, Score *score, Character *character) : QGraphicsView(parent), score(score), character(character)
{
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter(); //texture constructor

    scene = new QGraphicsScene(0, 0, x_pos, y_pos); //create scene for instruction
    setScene(scene);

    QPixmap background = texture_setter->shop_txt(1); //set texture background
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(background);
    backgroundItem->setPos(0, 0);
    scene->addItem(backgroundItem);

    setFixedSize(x_pos, y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create button back to menu
    backButton = new QPushButton("Resume", this);
    int button_x=110;
    int button_y=85;
    int gap=10;
    backButton->setGeometry(QRect(QPoint(gap,gap), QSize(button_x, button_y)));
    backButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(backButton, &QPushButton::clicked, this, &Shop::returnToMenu);

    // Increase Speed Up Button
    increaseSpeedUpButton = new QPushButton("Increase Speed Up", this);
    increaseSpeedUpButton->setGeometry(QRect(QPoint(50, 200), QSize(200, 50)));
    increaseSpeedUpButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    connect(increaseSpeedUpButton, &QPushButton::clicked, this, &Shop::increaseSpeedUp);

    // Increase Speed Down Button
    increaseSpeedDownButton = new QPushButton("Increase Speed Down", this);
    increaseSpeedDownButton->setGeometry(QRect(QPoint(50, 260), QSize(200, 50)));
    increaseSpeedDownButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    connect(increaseSpeedDownButton, &QPushButton::clicked, this, &Shop::increaseSpeedDown);

    // Increase Speed Left Button
    increaseSpeedLeftButton = new QPushButton("Increase Speed Left", this);
    increaseSpeedLeftButton->setGeometry(QRect(QPoint(50, 320), QSize(200, 50)));
    increaseSpeedLeftButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    connect(increaseSpeedLeftButton, &QPushButton::clicked, this, &Shop::increaseSpeedLeft);

    // Increase Speed Right Button
    increaseSpeedRightButton = new QPushButton("Increase Speed Right", this);
    increaseSpeedRightButton->setGeometry(QRect(QPoint(50, 380), QSize(200, 50)));
    increaseSpeedRightButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    connect(increaseSpeedRightButton, &QPushButton::clicked, this, &Shop::increaseSpeedRight);

    // Increase Hearts Button
    increaseHeartsButton = new QPushButton("Increase Hearts", this);
    increaseHeartsButton->setGeometry(QRect(QPoint(50, 440), QSize(200, 50)));
    increaseHeartsButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    connect(increaseHeartsButton, &QPushButton::clicked, this, &Shop::increaseHearts);

    // Increase Money Button
    increaseMoneyButton = new QPushButton("Increase Money", this);
    increaseMoneyButton->setGeometry(QRect(QPoint(50, 500), QSize(200, 50)));
    increaseMoneyButton->setStyleSheet("background-color: green; color: white; font-size: 16px;");
    connect(increaseMoneyButton, &QPushButton::clicked, this, &Shop::increaseMoney);
}

void Shop::returnToMenu()//if game exist(becouse i wanted it to stay opened). close shop
{
    this->close();
}

//if u click upgrade button, add any profit do variable
void Shop::increaseSpeedUp() {
    character->speed_up += 1;
}

void Shop::increaseSpeedDown() {
    character->speed_down += 1;
}

void Shop::increaseSpeedLeft() {
    character->speed_left += 1;
}

void Shop::increaseSpeedRight() {
    character->speed_right += 1;
}

void Shop::increaseMoney(){
    score->money_bonus +=1;
}

void Shop::increaseHearts(){
    score->lives +=1;
}
