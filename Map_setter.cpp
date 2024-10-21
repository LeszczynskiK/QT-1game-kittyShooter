#include "Map_setter.h"
#include "Score.h"

Map_setter::Map_setter(Score *score) :score(score) {
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


