#include "Character.h"

Character::Character(int screenWidth,int screenHeight) {//types of character textures
    QPixmap texture1("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char1.png");
    QPixmap texture2("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char2.jpeg");
    QPixmap texture3("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char3.jpeg");

    setPixmap(texture3.scaled(100,100));
    setPos((screenWidth - pixmap().width()) / 2, screenHeight * 0.9 - pixmap().height());

}

void Character::keyPressEvent(QKeyEvent *event)
{
    int step_size = 7;
    //moving combination of character
    if(event->key() == Qt::Key_Left)
    {
        setPos(x()-step_size,y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        setPos(x()+step_size,y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPos(x(),y()-step_size);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+step_size);
    }

}
