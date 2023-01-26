//
// Created by alexander on 10.12.22.
//

#include "Healthpack.h"

Healthpack::Healthpack(float x, float y)
        : Game_Object(x, y, 50.f, 50.f)
        , picked_up{false}
        , animation_frame{0}
{
    sprite.setTexture(*(Texture_Manager::get_texture("healthpack")));
    sprite.setPosition(position);
    sprite.setTextureRect(sf::IntRect (0, 0, 50, 50));
}

void Healthpack::update_texture()
{
    if ( animation_timer.getElapsedTime().asMilliseconds() > 50 )
    {
        animation_frame += 50;
        animation_timer.restart();
        if ( animation_frame == 500 ) { animation_frame = 0; }
    }
    sprite.setTextureRect(sf::IntRect (animation_frame, 0, 50, 50));
}

void Healthpack::update()
{
    update_texture();
    sprite.setPosition(position);
}

bool Healthpack::is_used() const
{
    return picked_up;
}

void Healthpack::use()
{
    picked_up = true;
}

void Healthpack::render(sf::RenderWindow & window, Camera & camera)
{
    if ( !picked_up )
    {
        camera.render(window, sprite);
    }
}


