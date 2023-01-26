//
// Created by alexander on 29.11.22.
//

#include "Player.h"
#include "Game_Object.h"
#include "Camera.h"
#include "constants.h"
#include "Enemy.h"
#include "Audio_Manager.h"
#include <random>
#include <iostream>


Player::Player(float x, float y)
        : Moving_Object(x, y, 45, 100)
        , lives{5}
        , jump_height{JUMP}
        , power_up_activated{false}
        , speed{SPEED}
        , immortal{false}
        , super_speed{false}
        , dying{false}
        , ducking{false}
{
    sprite.setTexture(*(Texture_Manager::get_texture("player")));
    sprite.setTextureRect(sf::IntRect{0,0, 50, 100});
    sprite.setPosition(position);
}

void Player::update(float friction, float gravity)
{
    find_direction(friction, gravity);
    if ( power_up_activated )
    {
        manage_power_ups();
    }
}

void Player::update_graphics(Camera & camera)
{
    update_animation_state();
    update_texture();
    if ( !dying )
    {
        camera.calculate_offset(position, velocity);
    }
}
void Player::update_animation_state()
{
    if ( ducking && velocity.x >= 0 )
    {
        current_animation_state = DUCKING_RIGHT;
    }
    else if ( ducking&& velocity.x < 0 )
    {
        current_animation_state = DUCKING_LEFT;
    }
    else if ( jumping && velocity.y < 0 && velocity.x >= 0 )
    {
        current_animation_state = JUMPING_RIGHT;
    }
    else if ( jumping && velocity.y < 0 && velocity.x < 0 )
    {
        current_animation_state = JUMPING_LEFT;
    }
    else if ( jumping && velocity.y > 0 && velocity.x >= 0 )
    {
        current_animation_state = FALLING_RIGHT;
    }
    else if ( jumping && velocity.y > 0 && velocity.x < 0 )
    {
        current_animation_state = FALLING_LEFT;
    }
    else if (  velocity.x > 0 )
    {
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
        {
            current_animation_state = RUNNING_RIGHT;
        }
        else
        {
            current_animation_state = SLIDING_RIGHT;
        }
    }
    else if ( velocity.x < 0 )
    {
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
        {
            current_animation_state = RUNNING_LEFT;
        }
        else
        {
            current_animation_state = SLIDING_LEFT;
        }
    }
    else
    {
        current_animation_state = IDLE;
    }

    if ( dying )
    {
        current_animation_state = DYING;
    }
}


void Player::find_direction(float friction, float gravity)
{
    if ( velocity.y <= 30 )
    {
        velocity.y += 1.0f * gravity;
    }
    if ( !dying )
    {
        if ( velocity.x > 1 || velocity.x < -1 )
        {
            velocity.x *= friction;
        }
        else
        {
            velocity.x = 0;
        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
        {
            if ( !jumping )
            {
                velocity.y = -jump_height;
                jumping = true;
                Audio_Manager::jump();
            }
        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
        {
            height = 45;
            ducking = true;
        }
        else
        {
            if ( ducking )
            {
                height = 95;
                position.y -= 65;
                ducking = false;
            }
        }
        if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
        {
            if ( velocity.x > -SPEED)
            {
                velocity.x -= 2.f;
            }
            else
            {
                velocity.x = -speed;
            }
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
            && velocity.x > -SPEED * 2.f )
            {
                velocity.x -= 2.f;
            }
            else
            {
                if ( velocity.x < -SPEED * 2.f )
                {
                    velocity.x += 2.f;
                }
            }
        }
        else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
        {
            if ( velocity.x < SPEED )
            {
                velocity.x += 2.f;
            }
            else
            {
                velocity.x = speed;
            }
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
            && velocity.x < SPEED * 2.f )
            {
                velocity.x += 2.f;
            }
            else
            {
                if ( velocity.x > SPEED * 2.f )
                {
                    velocity.x -= 2.f;
                }
            }
        }
        else
        {
            if ( !power_up_activated )
            {
                speed = SPEED;
            }
        }
    }
}

int Player::get_lives() const
{
    return lives;
}

void Player::manage_power_ups()
{
    if ( power_up_activated && power_up_timer.getElapsedTime().asSeconds() > 10 )
    {
        inactivate_power_up();
    }
}

void Player::inactivate_power_up()
{
    jump_height = JUMP;
    speed = SPEED;
    immortal = false;
    super_speed = false;
    power_up_activated = false;
    power_up_text = "";
}

void Player::activate_random_power_up()
{
    std::random_device GENERATOR;
    std::uniform_int_distribution<int> RANDOM(1,3);
    int number{RANDOM(GENERATOR)};
    switch ( number )
    {
        case 1:
            jump_height = JUMP * SUPER_JUMP;
            power_up_text = "SUPER JUMP!";
            break;
        case 2:
            speed = SPEED * SUPER_SPEED;
            power_up_text = "SUPER SPEED!";
            super_speed = true;
            break;
        case 3:
            immortal = true;
            power_up_text = "GHOST MODE!";
            break;
        default:
            break;

    }
    power_up_activated = true;
    power_up_timer.restart();
}

std::string Player::get_current_power_up() const
{
    return power_up_text;
}

void Player::stop_jumping()
{
    if (jumping)
    {
        Audio_Manager::end_of_jump();
        jumping = false;
    }
}

bool Player::is_ghost() const
{
    return immortal;
}

void Player::jump(float force)
{
    velocity.y = -force;
    jumping = true;
}

bool Player::has_super_power() const
{
    return power_up_activated;
}

void Player::loose_life()
{
    lives--;
}

void Player::reset()
{
    Moving_Object::reset();
    velocity = sf::Vector2f{0, 0};
    inactivate_power_up();
    dying = false;
}

void Player::set_checkpoint(sf::Vector2f new_position)
{
    starting_position = new_position;
}

void Player::start_death_animation()
{
    dying = true;
    velocity.x = 0;
    velocity.y = -17.f;
}

bool Player::is_dying() const
{
    return dying;
}

void Player::update_texture()
{
    if ( animation_timer.getElapsedTime().asMilliseconds() > animation_frame_rate )
    {
        animation_frame += 50;
        if ( animation_frame == 300 )
        {
            animation_frame = 0;
        }
        else if ( immortal && !dying )
        {
            sprite.setTextureRect(sf::IntRect{animation_frame,
                                              current_animation_state+1100,50,100});
        }
        else if ( super_speed && !dying )
        {
            sprite.setTextureRect(sf::IntRect{animation_frame,
                                              current_animation_state+2200,50,100});
        }
        else
        {
            sprite.setTextureRect(sf::IntRect{animation_frame,
                                              current_animation_state, 50, 100});
        }
        animation_timer.restart();
    }
}

void Player::use_healthpack() {
    lives++;
}
