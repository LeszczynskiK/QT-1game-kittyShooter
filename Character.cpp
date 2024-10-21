#include "Character.h"
#include "Bullet.h"
#include <iostream>
using namespace std;

Character::Character(int screenWidth,int screenHeight,int charTaken,Game * gameInstance,int speed_left,int speed_right,int speed_up,int speed_down) :
    character_txt(charTaken),game(gameInstance),speed_up(0),speed_down(0),speed_left(0),speed_right(0)//start initial od speed from shop
//character is initialised only once
{//types of character textures
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocusProxy(this);//direct focus set on character
    qDebug() << "Character created!";
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    if (hasFocus()) {
        qDebug() << "Character has focus.";
    } else {
        qDebug() << "Character does NOT have focus!";
    }
    setPixmap(textureSetter.character_txt(character_txt));//size (x,y), keep proportion, save high quality
    setPos((screenWidth - pixmap().width()) / 2, screenHeight * 0.9 - pixmap().height());//exact half/0.9 from top
}

void Character::keyPressEvent(QKeyEvent *event) {
    if (game->isPaused) return; // Sprawdzenie, czy gra jest wstrzymana

    int step_size = 15;
    switch (event->key()) {
    case Qt::Key_Left:
        setPos(x() - step_size - speed_left, y());
        break;
    case Qt::Key_Right:
        setPos(x() + step_size + speed_right, y());
        break;
    case Qt::Key_Up:
        setPos(x(), y() - step_size - speed_up);
        break;
    case Qt::Key_Down:
        setPos(x(), y() + step_size + speed_down);
        break;
    case Qt::Key_Space:
        Bullet *bullet = new Bullet(game);
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
        break;
    }

    // Ograniczenie ruchu w poziomie
    if (pos().x() > 1366 - pixmap().width()) {
        setPos(1366 - pixmap().width(), y());
    } else if (pos().x() < 0) {
        setPos(0, y());
    }
}


void Character::setChar(int charTaken)
{
    character_txt=charTaken;
    setPixmap(textureSetter.character_txt(character_txt));//set texture
}
