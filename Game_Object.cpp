//
// Created by alexander on 28.11.22.
//

#include "Game_Object.h"
#include "Camera.h"

Game_Object::Game_Object(float x, float y, int w, int h)
        : position{sf::Vector2f{x, y}}, width{w}, height{h} {}

void Game_Object::render(sf::RenderWindow & window, Camera & camera)
{
    camera.render(window, sprite);
}

void Game_Object::update()
{
    sprite.setPosition(position);
}

sf::FloatRect Game_Object::get_rect() const
{
    return sf::FloatRect{position.x, position.y,
                         static_cast<float>(width), static_cast<float>(height)};
}

sf::Vector2f Game_Object::get_position() const
{
    return position;
}