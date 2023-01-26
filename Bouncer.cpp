//
// Created by nikhu200 on 2022-12-07.
//

#include "Bouncer.h"

Bouncer::Bouncer(float x, float y)
        : Game_Object(x, y+20, BLOCKSIZE, BLOCKSIZE), force{JUMP*1.3}
{
    sprite.setTexture(*(Texture_Manager::get_texture("bouncer")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect(0, 0, 50, 30));
}


void Bouncer::update()
{
    sprite.setPosition(position);
    if (timer.getElapsedTime().asMilliseconds() > 100)
    {
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 30));
    }
}

void Bouncer::bounce()
{
    timer.restart();
    sprite.setTextureRect(sf::IntRect(50, 0, 50, 30));
}

float Bouncer::get_force() const
{
    return force;
}

sf::FloatRect Bouncer::get_rect() const
{
    return sf::FloatRect{position.x, position.y+20,
      static_cast<float>(width), static_cast<float>(height-20)};
}
