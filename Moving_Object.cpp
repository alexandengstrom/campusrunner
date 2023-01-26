//
// Created by alexander on 28.11.22.
//

#include <iostream>
#include "Moving_Object.h"
#include "Game_Object.h"
#include <math.h>

Moving_Object::Moving_Object(float x, float y, int w, int h)
        : Game_Object(x, y, w, h)
        , starting_position{sf::Vector2f{x, y}}
        , velocity{sf::Vector2f{0.0,0.0}}
        , alive{true}
        , animation_frame{0}
        , animation_frame_rate{75}
        , jumping{false} {}

sf::Vector2f Moving_Object::get_velocity() const
{
    return velocity;
}

sf::FloatRect Moving_Object::get_rect() const
{
    return sf::FloatRect{position.x + velocity.x, position.y+10 + velocity.y,
      static_cast<float>(width), static_cast<float>(height-10)};
}

void Moving_Object::stop_vertical()
{
    velocity.y = 0.f;
}

void Moving_Object::stop_horizontal()
{
    velocity.x = 0.f;
}

bool Moving_Object::is_alive() const
{
    return alive;
}

void Moving_Object::reset()
{
    velocity = sf::Vector2f{0,0};
    position = starting_position;
    alive = true;
}

void Moving_Object::kill()
{
    alive = false;
}

void Moving_Object::update_position()
{
    position += velocity;
    sprite.setPosition(position);
}

sf::Vector2f Moving_Object::get_starting_position() const
{
    return starting_position;
}

void Moving_Object::update_texture()
{
    if ( animation_timer.getElapsedTime().asMilliseconds() > animation_frame_rate )
    {
        animation_frame += 50;
        if ( animation_frame == 300 )
        {
            animation_frame = 0;
        }
        sprite.setTextureRect(sf::IntRect{animation_frame, current_animation_state,
					  50, 100});
        animation_timer.restart();
    }
}

void Moving_Object::push(float force)
{
    if ( fabs(velocity.x) <= fabs(force) )
    {
        velocity.x = force;
    }
    else
    {
        velocity.x += force * 0.01f;
    }
}

void Moving_Object::change_direction() {
    velocity.x *= -1.0f;
}

void Moving_Object::blow(float force) {
    velocity.y += -force;
    jumping = true;
    velocity.y *= 0.98f;
}

void Moving_Object::update_animation_state() {}


