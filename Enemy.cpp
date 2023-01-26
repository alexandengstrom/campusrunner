//
// Created by alexander on 01.12.22.
//

#include "Enemy.h"
#include "constants.h"
#include <iostream>

Enemy::Enemy(float x, float y)
        : Moving_Object(x, y, 50, 100)
        , speed{SPEED}
{
    sprite.setTexture(*(Texture_Manager::get_texture("enemy")));
    sprite.setPosition(position);
    animation_frame_rate = 130;
}

Enemy::Enemy(float x, float y, int w, int h) : Moving_Object(x, y, w, h) {}

void Enemy::render(sf::RenderWindow & window, Camera & camera)
{
    if(alive)
    {
        camera.render(window, sprite);
    }
}
void Enemy::update(float friction, float gravity)
{
    if (alive)
    {
        if (velocity.y <= 30) {
            velocity.y += 1.0f * gravity;
        }
    }
    update_animation_state();
    update_texture();
}

void Enemy::update_animation_state()
{
    if ( velocity.x > 0 ) { current_animation_state = RUNNING_RIGHT; }
    else { current_animation_state = RUNNING_LEFT; }
}

void Enemy::spawn() {
    if (velocity.x == 0.0f)
    {
        velocity.x = -speed/1.5f;
    }
}








