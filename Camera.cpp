//
// Created by alexander on 29.11.22.
//
#include "constants.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>

Camera::Camera() : offset{sf::Vector2f{0,0}}
        , velocity(sf::Vector2f{0,0})
        , width{0}
        , height{0} {}

void Camera::calculate_offset(sf::Vector2f & position, sf::Vector2f & vel)
{
    velocity = vel;
    offset.x = position.x - (WINDOW_WIDTH/2.0f);
    if (offset.x < 0)
    {
        offset.x = 0.0f;
    }
    else if (offset.x > width-WINDOW_WIDTH)
    {
        offset.x = width-WINDOW_WIDTH;
    }


    offset.y = position.y - (WINDOW_HEIGHT/5.0f);
    if (offset.y < 0)
    {
        offset.y = 0;
    }
    else if (offset.y > height-WINDOW_HEIGHT)
    {
        offset.y = height-WINDOW_HEIGHT;
    }
}



void Camera::render(sf::RenderWindow & window, sf::Sprite & object)
{
    object.move(-offset);
    sf::Vector2f position{object.getPosition()};
    if ( position.x > -300 && position.x < WINDOW_WIDTH + 300
    && position.y > -400 && position.y < WINDOW_HEIGHT + 400 )
    {
        window.draw(object);
    }
}

void Camera::render(sf::RenderWindow & window, sf::Text & object) const
{
    object.move(-offset);
    object.move(-65, -150);
    window.draw(object);
}

void Camera::update_dimensions(float w, float h)
{
    width = w;
    height = h;
}

void Camera::move_layer(std::vector<sf::Sprite> & sprites,
                        sf::Vector2f const& move_factor) const
{
    for (sf::Sprite & sprite : sprites)
    {
        if ( offset.x > 0 && offset.x < width-WINDOW_WIDTH )
        {
            sprite.move(sf::Vector2f{-velocity.x / move_factor.x, 0.f});
        }
        if ( offset.y < (height-WINDOW_HEIGHT) && offset.y > 0 )
        {
            if ( velocity.y > 0 )
            {
                sprite.move(sf::Vector2f{0.f, (-velocity.y)/move_factor.y});
            }
            else
            {
                sprite.move(sf::Vector2f{0.f, -velocity.y/ move_factor.y});
            }
        }
        if ( sprite.getPosition().x < - WINDOW_WIDTH )
        {
            sprite.move(WINDOW_WIDTH*2, 0);
        }
        else if ( sprite.getPosition().x > WINDOW_WIDTH )
        {
            sprite.move(-(WINDOW_WIDTH*2), 0);
        }
    }
}



