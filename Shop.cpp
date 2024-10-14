#include "Shop.h"
#include "Menu.h"

Shop::Shop(QWidget *parent) : QGraphicsView(parent)
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
}

void Shop::returnToMenu()//if game exist(becouse i wanted it to stay opened). close shop
{
    this->close();
}

