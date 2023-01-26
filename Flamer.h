//
// Created by nikhu200 on 2022-12-07.
//

#ifndef CAMPUSRUNNER_FLAMER_H
#define CAMPUSRUNNER_FLAMER_H

#include "Game_Object.h"

/**
* A flamer in the game. The player can walk on the flamer when the flame 
* is turned off but when the flame is turned on the player can't pass through.
*/
class Flamer : public Game_Object {
public:
    /**
    * Create a flamer.
    */
    Flamer(float x, float y);

    /**
    * Update the flamer. Responsible for changing the height of the flame 
    * depending on the timer.
    */
    void update() override;

    /**
    * Returns if the flame is active or not.
    */
    bool is_flaming() const;

    /**
    * Returns the hitbox of the flamer. The hitbox grows when the flame height 
    * gets bigger.
    */
    sf::FloatRect get_rect() const override;
private:
    /**
    * The animation states of the Flamer.
    */
    enum Flame_State {
        UP = 0,
        DOWN = 150
    };

    /**
    * The starting position of the flamer.
    */
    sf::Vector2f starting_position;

    /**
    * True if the flame is active, else false.
    */
    bool flaming;

    /**
    * The state of the flame, can be UP or DOWN.
    */
    Flame_State flame_state;

    /**
    * The height of the flame, will be a value between 0-100.
    */
    float flame_height;

    /**
    * The current animation frame.
    */
    float animation_frame;

    /**
    * How much the the texture should move when changing animation frame.
    */
    float animation_step;

    /**
    * Will be 1 or -1 depending on if the flame is going up or down.
    */
    float growth_factor;

    /**
    * The timer of the flamer, is used to decide when to start the flame.
    */
    sf::Clock timer;

    /**
    * The animation timer, is used to make sure the animation frame is changed 
    * at the right time.
    */
    sf::Clock animation_timer;
};


#endif //CAMPUSRUNNER_FLAMER_H
