#include "Shop.h"
#include "Menu.h"
#include <QFont>

Shop::Shop(QWidget *parent, Score *score, Character *character,Enemy *enemy) : QGraphicsView(parent), score(score), character(character),enemy(enemy)
{
    QFont font("Cavans", 24);
    QBrush brush(Qt::white);
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
    int button_x1=110;
    int button_y1=85;
    int gap=10;
    backButton->setGeometry(QRect(QPoint(gap,y_pos-10*gap), QSize(button_x1, button_y1)));
    backButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(backButton, &QPushButton::clicked, this, &Shop::returnToMenu);


    int button_x=60;
    int button_y=60;
    // Increase Speed Up Button
    increaseSpeedUpButton = new QPushButton("+1", this);
    increaseSpeedUpButton->setGeometry(QRect(QPoint(550, 100), QSize(button_x, button_y)));
    increaseSpeedUpButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(increaseSpeedUpButton, &QPushButton::clicked, this, &Shop::increaseSpeedUp);

    // Increase Speed Down Button
    increaseSpeedDownButton = new QPushButton("+1", this);
    increaseSpeedDownButton->setGeometry(QRect(QPoint(550, 180), QSize(button_x, button_y)));
    increaseSpeedDownButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(increaseSpeedDownButton, &QPushButton::clicked, this, &Shop::increaseSpeedDown);

    // Increase Speed Left Button
    increaseSpeedLeftButton = new QPushButton("+1", this);
    increaseSpeedLeftButton->setGeometry(QRect(QPoint(80, 100), QSize(button_x, button_y)));
    increaseSpeedLeftButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(increaseSpeedLeftButton, &QPushButton::clicked, this, &Shop::increaseSpeedLeft);

    // Increase Speed Right Button
    increaseSpeedRightButton = new QPushButton("+1", this);
    increaseSpeedRightButton->setGeometry(QRect(QPoint(80, 180), QSize(button_x, button_y)));
    increaseSpeedRightButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(increaseSpeedRightButton, &QPushButton::clicked, this, &Shop::increaseSpeedRight);

    // Increase Hearts Button
    increaseHeartsButton = new QPushButton("+1", this);
    increaseHeartsButton->setGeometry(QRect(QPoint(350, 640), QSize(button_x, button_y)));
    increaseHeartsButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(increaseHeartsButton, &QPushButton::clicked, this, &Shop::increaseHearts);

    // Increase Money Button
    increaseMoneyButton = new QPushButton("*1", this);
    increaseMoneyButton->setGeometry(QRect(QPoint(1030, 580), QSize(button_x, button_y)));
    increaseMoneyButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(increaseMoneyButton, &QPushButton::clicked, this, &Shop::increaseMoney);

    // Slow down enemy Button
    slowDownEnemyButton = new QPushButton("-1", this);
    slowDownEnemyButton->setGeometry(QRect(QPoint(999, 170), QSize(button_x, button_y)));
    slowDownEnemyButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(slowDownEnemyButton, &QPushButton::clicked, this, &Shop::slowDownEnemy);

    //create new display
    livesTextItem = new QGraphicsTextItem();
    livesTextItem->setFont(font);
    livesTextItem->setDefaultTextColor(Qt::yellow);

    moneyTextItem = new QGraphicsTextItem();
    moneyTextItem->setFont(font);
    moneyTextItem->setDefaultTextColor(Qt::yellow);

    speedUpTextItem = new QGraphicsTextItem();
    speedUpTextItem->setFont(font);
    speedUpTextItem->setDefaultTextColor(Qt::yellow);

    speedDownTextItem = new QGraphicsTextItem();
    speedDownTextItem->setFont(font);
    speedDownTextItem->setDefaultTextColor(Qt::yellow);

    speedLeftTextItem = new QGraphicsTextItem();
    speedLeftTextItem->setFont(font);
    speedLeftTextItem->setDefaultTextColor(Qt::yellow);

    speedRightTextItem = new QGraphicsTextItem();
    speedRightTextItem->setFont(font);
    speedRightTextItem->setDefaultTextColor(Qt::yellow);

    slowDownEnemyTextItem = new QGraphicsTextItem();
    slowDownEnemyTextItem->setFont(font);
    slowDownEnemyTextItem->setDefaultTextColor(Qt::yellow);

    //displays positions
    int gap0=1200;
    int gap1=40;
    int gap2=350;
    livesTextItem->setPos(gap0, gap2);
    moneyTextItem->setPos(gap0, gap2+gap1);
    speedUpTextItem->setPos(gap0, gap2+2*gap1);
    speedDownTextItem->setPos(gap0, gap2+3*gap1);
    speedLeftTextItem->setPos(gap0, gap2+4*gap1);
    speedRightTextItem->setPos(gap0, gap2+5*gap1);
    slowDownEnemyTextItem->setPos(gap0,gap2+6*gap1);

    //add these displays to scene
    scene->addItem(livesTextItem);
    scene->addItem(moneyTextItem);
    scene->addItem(speedUpTextItem);
    scene->addItem(speedDownTextItem);
    scene->addItem(speedLeftTextItem);
    scene->addItem(speedRightTextItem);
    scene->addItem(slowDownEnemyTextItem);

    updateDisplay();//actualize current values of variabled from shop upgrades
}

void Shop::returnToMenu()//if game exist(becouse i wanted it to stay opened). close shop
{
    this->close();
}

//if u click upgrade button, add any profit do variable
void Shop::increaseSpeedUp() {
    character->speed_up += 1;
    updateDisplay();
}

void Shop::increaseSpeedDown() {
    character->speed_down += 1;
    updateDisplay();
}

void Shop::increaseSpeedLeft() {
    character->speed_left += 1;
    updateDisplay();
}

void Shop::increaseSpeedRight() {
    character->speed_right += 1;
    updateDisplay();
}

void Shop::increaseMoney(){
    score->money_bonus +=1;
    updateDisplay();
}

void Shop::increaseHearts(){
    score->lives +=1;
    updateDisplay();
}

void Shop::slowDownEnemy()
{
    enemy->slow_value +=1;
    updateDisplay();
}

void Shop::updateDisplay() {
    livesTextItem->setPlainText(QString("Lives: %1").arg(score->lives));
    moneyTextItem->setPlainText(QString("Money: %1").arg(score->money_bonus));
    speedUpTextItem->setPlainText(QString("Up: %1").arg(character->speed_up));
    speedDownTextItem->setPlainText(QString("Down: %1").arg(character->speed_down));
    speedLeftTextItem->setPlainText(QString("Left: %1").arg(character->speed_left));
    speedRightTextItem->setPlainText(QString("Right: %1").arg(character->speed_right));
    slowDownEnemyTextItem->setPlainText(QString("Slow: %1").arg(enemy->slow_value));
}

