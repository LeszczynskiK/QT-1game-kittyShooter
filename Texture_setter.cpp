#include "Texture_setter.h"

Texture_setter::Texture_setter()
{

}

QPixmap Texture_setter::bullet_txt(int number)
{
    QPixmap txt_bullet;
    switch(number){
    case 1:
    txt_bullet=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/paw1.png").scaled(57,57,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    }
    return txt_bullet;
}

QPixmap Texture_setter::character_txt(int number)
{
    QPixmap txt_character;
        switch(number){
    case 1:
    txt_character=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char1.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 2:
    txt_character=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char2.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 3:
    txt_character=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/char3.png").scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    }
    return txt_character;
}

QPixmap Texture_setter::enemy_txt(int number)
{
    QPixmap txt_enemy;
    switch(number){
    case 1:
    txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food1.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 2:
    txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food2.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 3:
    txt_enemy= QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food3.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 4:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food4.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 5:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food5.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 6:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food6.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 7:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food7.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 8:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food8.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 9:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food9.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 10:
        txt_enemy = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/food10.png").scaled(100,100,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    }
    return txt_enemy;
}

QPixmap Texture_setter::map_txt(int number)
{
    QPixmap txt_map;
    static int x=1366;
    static int y=768;
    switch(number)
    {
    case 1:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map10.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 2:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map1.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 3:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map2.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 4:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map3.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 5:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map4.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 6:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map5.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 7:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map6.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 8:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map7.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 9:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map8.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    case 10:
    txt_map=QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/textures/map9.jpg").scaled(x,y,Qt::KeepAspectRatio, Qt::SmoothTransformation);
        break;
    }
    return txt_map;
}

