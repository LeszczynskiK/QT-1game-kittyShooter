#include "Map_setter.h"
#include "Score.h"

Map_setter::Map_setter(Score *score) :score(score) {
    /*
    int map_update_value = score->getScore();
    if(map_update_value > map[0])
    {
        setPixmap(textureSetter.map_txt(1));
    }
    else if(map_update_value > map[1])
    {
        setPixmap(textureSetter.map_txt(2));
    }
    else if(map_update_value > map[2])
    {
        setPixmap(textureSetter.map_txt(3));
    }
    else if(map_update_value > map[3])
    {
        setPixmap(textureSetter.map_txt(4));
    }
    else if(map_update_value > map[4])
    {
        setPixmap(textureSetter.map_txt(5));
    }
    else if(map_update_value > map[5])
    {
        setPixmap(textureSetter.map_txt(6));
    }
    else if(map_update_value > map[6])
    {
        setPixmap(textureSetter.map_txt(7));
    }
    else if(map_update_value > map[7])
    {
        setPixmap(textureSetter.map_txt(8));
    }
    else if(map_update_value > map[8])
    {
        setPixmap(textureSetter.map_txt(9));
    }
    else if(map_update_value > map[9])
    {
        setPixmap(textureSetter.map_txt(10));
    }
*/
    changeMap();
}

void Map_setter::changeMap()
{
    map_update_value = score->getScore();//get current game points

    //check and set map
    for (int i = 0; i < 10; ++i) {
        if (map_update_value >= map[i]) {
            setPixmap(textureSetter.map_txt(i + 1));//set txt for exact points value
        }
    }
}


