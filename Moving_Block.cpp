//
// Created by nikhu200 on 2022-12-08.
//

#include "Moving_Block.h"

Moving_Block::Moving_Block(float x, float y)
        : Moving_Object(x, y, 100, 50)
        , distance{500}
        {
    sprite.setTexture(*(Texture_Manager::get_texture("moving_block")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (0, 0, 100, 50));
    velocity.x = 2.f;
}

void Moving_Block::update(float friction, float gravity)
{
    if ( position.x - starting_position.x > distance )
    {
        velocity.x *= -1;
    }
    else if ( position.x < starting_position.x )
    {
        velocity.x *= -1;
    }
    position.x += velocity.x;
    sprite.setPosition(position);
}

sf::FloatRect Moving_Block::get_rect() const
{
    return sf::FloatRect{position.x + velocity.x,
                         position.y+25,
                         static_cast<float>(width),
                         static_cast<float>(height-25)};
}

void Moving_Block::reset()
{
    position = starting_position;
}