#include "Character.h"
QPixmap Character::texture[3];
void Character::initializeTextures()
{
    texture[0]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char1.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[1]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char2.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    texture[2]=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char3.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);

};



Character::Character(int screenWidth,int screenHeight) {//types of character textures
    setPixmap(texture[2]);//size (x,y), keep proportion, save high quality
    setPos((screenWidth - pixmap().width()) / 2, screenHeight * 0.9 - pixmap().height());//exact half/0.9 from top

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
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }

}
