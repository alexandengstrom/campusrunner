//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_MOVING_OBJECT_H
#define CAMPUSRUNNER_MOVING_OBJECT_H

#include <SFML/Graphics.hpp>
#include "Game_Object.h"

/**
* Animation states to support animation of sprites.
*/
enum Animation_State {
    RUNNING_RIGHT = 0,
    RUNNING_LEFT = 100,
    IDLE = 200,
    JUMPING_RIGHT = 300,
    JUMPING_LEFT = 400,
    FALLING_RIGHT = 500,
    FALLING_LEFT = 600,
    SLIDING_RIGHT = 700,
    SLIDING_LEFT = 800,
    DUCKING_RIGHT = 900,
    DUCKING_LEFT = 1000,
    DYING = 3300
};

/**
* The interface of all moving game objects.
*/
class Moving_Object: public Game_Object {
public:
    /**
    * Creates a moving object.
    */
    Moving_Object(float x, float y, int w, int h);

    virtual void update(float friction, float gravity) = 0;

    //Getters
    /**
    * Returns the current velocity as a Vector2f.
    */
    sf::Vector2f get_velocity() const;

    /**
    * Returns the hitbox of the next frame by adding the velocity.
    */
    sf::FloatRect get_rect() const override;

    /**
    * Returns the current starting position as a Vector2f.
    */
    sf::Vector2f get_starting_position() const;

    //Setters
    /**
    * Sets the vertical velocity to 0.
    */
    virtual void stop_vertical();

    /**
    * Sets the horizontal velocity to 0.
    */
    virtual void stop_horizontal();

    /**
    * Updates the position.
    */
    void update_position();

    /**
    * Resets velocity, position and alive of the moving object.
    */
    virtual void reset();

    /**
    * True if the moving object is alive, else false.
    */
    bool is_alive() const;

    /**
    * Sets alive to false.
    */
    void kill();

    /**
    * Pushes the moving object left or right.
    */
    void push(float force);

    /**
    * Pushes the moving object upwards in a soaring manner.
    * The push gets more fierce close to the blowing object.
    */
    void blow(float force);

    /**
    * Inverts horizontal velocity.
    */
    virtual void change_direction();


protected:
    /**
    * Returns true if moving objects has jumped, else false.
    */
    bool jumping;

    /**
    * Current velocity of the moving object.
    */
    sf::Vector2f velocity;

    /**
    * Current starting position of the moving object.
    */
    sf::Vector2f starting_position;

    /**
    * True if the object is alive, else false.
    */
    bool alive;

    /**
    * An animation timer to support animation of textures.
    */
    sf::Clock animation_timer;

    /**
    * Frame to render.
    */
    int animation_frame;

    /**
    * Animation state of the moving object,
    * such as "RUNNING LEFT" or "JUMPING RIGHT".
    */
    Animation_State current_animation_state;

    /**
    * Frame rate.
    */
    int animation_frame_rate;

    /**
    * Used in derived classes.
    * Updates animation state, such as "RUNNING LEFT" or "JUMPING RIGHT".
    */
    virtual void update_animation_state();

    /**
    * Updates sprite texture depending on animation state,
    * such as "RUNNING LEFT" or "JUMPING RIGHT".
    */
    virtual void update_texture();
};


#endif //CAMPUSRUNNER_MOVING_OBJECT_H
