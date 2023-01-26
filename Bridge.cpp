//
// Created by nikhu200 on 2022-12-08.
//

#include "Bridge.h"

Bridge::Bridge(float x, float y)
        :Solid_Block(x, y-15, 300, 25)
        {
    sprite.setTexture(*(Texture_Manager::get_texture("bridge")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (0, 0, 300, 50));
}

sf::FloatRect Bridge::get_rect() const
{
    return sf::FloatRect{position.x, position.y+15,
      static_cast<float>(width), static_cast<float>(height)};
}

