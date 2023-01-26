//
// Created by alexander on 01.12.22.
//

#include "Treasure.h"

Treasure::Treasure(float x, float y)
        :Game_Object(x, y, 100, 50), opened{false}
        {
    sprite.setTexture(*(Texture_Manager::get_texture("treasure")));
    sprite.setTextureRect(sf::IntRect{0,0, 100, 50});
    sprite.setPosition(position);
}

void Treasure::open()
{
    sprite.setTextureRect(sf::IntRect{100,0, 100, 50});
    opened = true;
}

bool Treasure::is_opened() const
{
    return opened;
}

void Treasure::close()
{
    sprite.setTextureRect(sf::IntRect{0,0, 100, 50});
    opened = false;
}
