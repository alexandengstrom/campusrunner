//
// Created by alexander on 29.11.22.
//

#ifndef CAMPUSRUNNER_PLAYER_H
#define CAMPUSRUNNER_PLAYER_H

#include "Solid_Block.h"
#include "Moving_Object.h"
#include "Camera.h"
#include "Game_Object.h"
#include "Enemy.h"
#include "Harmful_Block.h"
#include "Door.h"
#include "Treasure.h"
#include <SFML/Audio.hpp>

/**
* The player is the user controlled main character in the game.
*/
class Player : public Moving_Object {
public:
    /**
    * Create a player.
    */
    Player(float x, float y);

    /**
    * Manager players direction and power ups.
    */
    void update(float friction, float gravity) override;

    /**
    * Animates the player.
    */
    void update_graphics(Camera & camera);

    /**
    * Returns number of player lives.
    */
    int get_lives() const;

    /**
    * Returns current power up as a string.
    */
    std::string get_current_power_up() const;

    /**
    * Activates a random power up.
    */
    void activate_random_power_up();

    /**
    * Reset player position, velocity, turns off power ups
    * and turns off active power ups.
    */
    void reset() override;

    /**
    * Adds a life to the player.
    */
    void use_healthpack();

    //Getters
    /**
    * Returns true if player is immortal, else false.
    */
    bool is_ghost() const;

    /**
    * Returns true if power up is active, else false.
  */
    bool has_super_power() const;

    /**
    * Returns true if player is about to die, else false.
    */
    bool is_dying() const;


    //Setters
    /**
    * Player vertical velocity is changed.
    */
    void jump(float force);

    /**
    * Sets jumping to false.
    */
    void stop_jumping();

    /**
    * Reduces player lives by one.
    */
    void loose_life();

    /**
    * Updates player starting position.
    */
    void set_checkpoint(sf::Vector2f new_position);

    /**
    * Starts player death animation.
    */
    void start_death_animation();

private:
    /**
    * True if player has power up "GHOST MODE", else false.
    */
    bool immortal;

    /**
    *  True if player has power up "SUPER SPEED", else false.
    */
    bool super_speed;

    /**
    * True if player is about to die, else false.
    */
    bool dying;

    /**
    * True if player is ducking, else false.
    */
    bool ducking;

    /**
    * Current maximum change in vertical velocity.
    */
    float jump_height;

    /**
    * Current maximum change in horizontal velocity.
    */
    float speed;

    /**
    * A text displaying current active power up.
    */
    std::string power_up_text;

    /**
    * A timer for keeping track on how long a power up has
    * been active.
    */
    sf::Clock power_up_timer;

    /**
    * Ture if a power up is active, else false.
    */
    bool power_up_activated;

    /**
    * Current number of lives.
    */
    int lives;

    /**
    * Handles keyboard input and updates player position accordingly.
    */
    void find_direction(float friction, float gravity);

    /**
    * Checks how long power up has been active. Turns it off
    * if more than specified time.
    */
    void manage_power_ups();

    /**
    * Inactivates all power ups.
    */
    void inactivate_power_up();

    /**
    * Changes animation state based on velocity in all directions,
    * current power up and if ducking.
    */
    void update_animation_state() override;

    /**
    * Updates texture based on frame rate, animation state and
    * active power up.
    */
    void update_texture() override;
};


#endif //CAMPUSRUNNER_PLAYER_H
