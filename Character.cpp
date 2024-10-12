#include "Character.h"

Character::Character(int screenWidth,int screenHeight) {//types of character textures
    setPixmap(textureSetter.character_txt(2));//size (x,y), keep proportion, save high quality
    setPos((screenWidth - pixmap().width()) / 2, screenHeight * 0.9 - pixmap().height());//exact half/0.9 from top
}

void Character::keyPressEvent(QKeyEvent *event)
{
    int step_size = 15;
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
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
    if(pos().x()>1366-pixmap().width())//save from leaving x map
    {
        setPos(x()-50,y());
    }
    else if(pos().x()<0)
    {
        setPos(x()+50,y());
    }

}
