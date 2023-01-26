//
// Created by alexander on 01.12.22.
//

#include "Door.h"

Door::Door(float x, float y, int level) : Game_Object(x, y, 100, 100)
{
    sprite.setTexture(*(Texture_Manager::get_texture("door"
						     + std::to_string(level))));
    sprite.setPosition(position);
}
