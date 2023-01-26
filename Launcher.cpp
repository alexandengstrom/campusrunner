//
// Created by nikhu200 on 2022-12-07.
//

#include <iostream>
#include "Launcher.h"


Launcher::Launcher(float x, float y)
        : Game_Object(x, y+80, 200, 20)
        , launched{false}
        , used{false}
        {
            sprite.setTexture(*(Texture_Manager::get_texture("launcher")));
            sprite.setPosition(position);
            sprite.setTextureRect(sf::IntRect(0, 80, 200, 20));
}

void Launcher::update()
{
    sprite.setPosition(position);
    if (launched && timer.getElapsedTime().asSeconds() > 1)
    {
            launched = false;
            sprite.setTextureRect(sf::IntRect(0, 80, 200, 20));
            position.y += 80;
    }
}

void Launcher::launch()
{
    launched = true;
    used = true;
    timer.restart();
    sprite.setTextureRect(sf::IntRect(0, 100, 200, 100));
    height = 100;
    position.y -= 80;
}

bool Launcher::is_launched() const
{
    return launched;
}


sf::FloatRect Launcher::get_rect() const
{
    return sf::FloatRect{position.x, position.y+10,
      static_cast<float>(width), static_cast<float>(height-10)};
}

void Launcher::reset()
{
    sprite.setTextureRect(sf::IntRect(0, 80, 200, 20));
    if ( used && launched )
    {
        position.y += 80;
    }
    launched = false;
}
