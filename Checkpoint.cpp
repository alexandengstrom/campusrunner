//
// Created by nikhu200 on 2022-12-09.
//

#include "Checkpoint.h"

Checkpoint::Checkpoint(float x, float y)
        : Game_Object(x, y-160, 179, 359)
        , reached{false}
        {
    sprite.setTexture(*(Texture_Manager::get_texture("checkpoint")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (0, 0, 179, 359));
    sprite.setScale(0.6, 0.6);
}

bool Checkpoint::is_reached() const
{
    return reached;
}

void Checkpoint::touchdown()
{
    reached = true;
}
