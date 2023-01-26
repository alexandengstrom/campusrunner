//
// Created by nikhu200 on 2022-12-08.
//

#include "Fan.h"

Fan::Fan(float x, float y)
        : Solid_Block(x, y, 200, 50)
        , animation_frame{0}

{
    sprite.setTexture(*(Texture_Manager::get_texture("fan")));
    sprite.setPosition(sf::Vector2f{position.x, position.y-550.f});
}

void Fan::update() {
    if ( animation_timer.getElapsedTime().asMilliseconds() > 40 )
    {
        animation_frame += 200;
        if ( animation_frame >= 1600 )
        {
            animation_frame = 0;
        }
        animation_timer.restart();
    }

    Audio_Manager::fan(sprite.getPosition());
    sprite.setTextureRect(sf::IntRect (animation_frame, 0, 200, 600));
    sprite.setPosition(sf::Vector2f{position.x, position.y-550.f});

}
