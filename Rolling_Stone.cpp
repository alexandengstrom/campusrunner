//
// Created by nikhu200 on 2022-12-08.
//

#include "Rolling_Stone.h"
#include "Audio_Manager.h"
#include <math.h>
#include <iostream>

Rolling_Stone::Rolling_Stone(float x, float y)
        : Enemy(x, y, 100, 100)
        , direction{LEFT}
        {
    sprite.setTexture(*(Texture_Manager::get_texture("rolling_stone")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (0, 0, 100, 100));
    animation_frame_rate = 50;
    speed = 9.f;
        }

void Rolling_Stone::update_texture()
{
    if ( animation_timer.getElapsedTime().asMilliseconds() > 450/fabs(velocity.x) )
    {
        switch ( direction )
        {
            case LEFT:
                animation_frame += 100;
                if ( animation_frame == 800 )
                {
                    animation_frame = 0;
                }
                break;
            case RIGHT:
                animation_frame -= 100;
                if ( animation_frame <= 0 )
                {
                    animation_frame = 700;
                }
                break;
        }
        sprite.setTextureRect(sf::IntRect{animation_frame,
                                          0,100,100});
        animation_timer.restart();
    }
}

sf::FloatRect Rolling_Stone::get_rect() const
{
    return sf::FloatRect{position.x+10 + velocity.x, position.y+10 + velocity.y,
                         static_cast<float>(width-20), static_cast<float>(height-10)};
}

void Rolling_Stone::stop_vertical()
{
    Audio_Manager::rolling_stone(sprite.getPosition(), velocity);
    velocity.y = -(velocity.y*0.5f);
}

void Rolling_Stone::change_direction()
{
    velocity.x *= -0.8f;
    if ( fabs(velocity.x) > 2.f )
    {
        velocity.y = -(fabs(velocity.x) * 1.5f);
    }
}

void Rolling_Stone::update_animation_state()
{
    if ( velocity.x > 0 )
    {
        direction = RIGHT;
    }
    else
    {
        direction = LEFT;
    }
}
