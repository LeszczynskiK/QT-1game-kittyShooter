#include "Scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent)
{
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter(); //texture constructor

    scene = new QGraphicsScene(0, 0, x_pos, y_pos); //create scene for instruction
    setScene(scene);

    QPixmap background = texture_setter->score_txt(1); //set texture background
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(background);
    backgroundItem->setPos(0, 0);
    scene->addItem(backgroundItem);

    setFixedSize(x_pos, y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create button back to menu
    backButton = new QPushButton("Menu", this);
    int button_x=300;
    int button_y=160;
    int gap=10;
    backButton->setGeometry(QRect(QPoint(x_pos/2 - button_x*2/3, y_pos*6/8), QSize(button_x, button_y)));
    backButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(backButton, &QPushButton::clicked, this, &Scoreboard::returnToMenu);

}

void Scoreboard::returnToMenu()
{
    this->close(); //close instruction
    Menu *menuWindow = new Menu(); //open menu
    menuWindow->show(); //show
    qDebug("Menu");
}
