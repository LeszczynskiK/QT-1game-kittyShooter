#include "Instruction.h"

Instruction::Instruction(QWidget *parent) : QGraphicsView(parent)
{
    const int x_pos = 1366;
    const int y_pos = 768;
    texture_setter = new Texture_setter(); //texture constructor

    scene = new QGraphicsScene(0, 0, x_pos, y_pos); //create scene for instruction
    setScene(scene);

    QPixmap background = texture_setter->instruction_txt(1); //set texture background
    QGraphicsPixmapItem *backgroundItem = new QGraphicsPixmapItem(background);
    backgroundItem->setPos(0, 0);
    scene->addItem(backgroundItem);

    //set text of instruction
    string instruction_text = "Instruction about game:";//need to convert string->QString
    QGraphicsTextItem *textItem = new QGraphicsTextItem(QString::fromStdString(instruction_text));
    QFont font;
    font.setPointSize(27); //size 20 of font
    textItem->setFont(font); //use font settings to textItem
    textItem->setPos(100, 100); //setpos of text
    scene->addItem(textItem);

    setFixedSize(x_pos, y_pos);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create button back to menu
    backButton = new QPushButton("Menu", this);
    int button_x=150;
    int button_y=100;
    int gap=10;
    backButton->setGeometry(QRect(QPoint(x_pos-gap-button_x, 0 + gap), QSize(button_x, button_y)));
    backButton->setStyleSheet("background-color: orange; color: #1D4E89; font-size: 20px;");
    connect(backButton, &QPushButton::clicked, this, &Instruction::returnToMenu);
}

void Instruction::returnToMenu() {
    this->close(); //close instruction
    Menu *menuWindow = new Menu(); //open menu
    menuWindow->show(); //show
    qDebug("Menu");
}

