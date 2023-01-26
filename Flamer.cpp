//
// Created by nikhu200 on 2022-12-07.
//

#include <iostream>
#include "Flamer.h"

Flamer::Flamer(float x, float y)
        : Game_Object(x, y-100, 50, 150)
        , flaming{false}
        , growth_factor{10}
        , starting_position{sf::Vector2f{x, y}}
        , flame_state{UP}
        , flame_height{0}
        , animation_step{50}
        , animation_frame{0}
        {
    sprite.setTexture(*(Texture_Manager::get_texture("flamer")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 150));
}

void Flamer::update()
{
    if ( timer.getElapsedTime().asSeconds() > 2 && !flaming )
    {
        flaming = true;
        timer.restart();
        animation_timer.restart();
        flame_state = UP;
    }
    else if ( timer.getElapsedTime().asSeconds() > 1 && flaming )
    {
        flaming = false;
        timer.restart();
        growth_factor = 10;
        flame_height = 0;
        animation_frame = 0;
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 150));
    }
    if ( flaming )
    {
        Audio_Manager::flame(sprite.getPosition());
        if ( animation_timer.getElapsedTime().asMilliseconds() > 45 )
        {
            sprite.setTextureRect(sf::IntRect(animation_frame, flame_state, 50,
					      150));
            animation_frame += animation_step;
            flame_height += growth_factor;
            if ( animation_frame == 500 )
            {
                flame_state = DOWN;
                animation_frame = 0;
                growth_factor *= -1.f;
            }
            animation_timer.restart();
        }
    }
    sprite.setPosition(position);
}

sf::FloatRect Flamer::get_rect() const
{
    return sf::FloatRect{position.x, position.y+100-flame_height,
      static_cast<float>(width), static_cast<float>(height)-100+flame_height};
}

bool Flamer::is_flaming() const
{
    return flaming;
}
