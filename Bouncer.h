//
// Created by nikhu200 on 2022-12-07.
//

#ifndef CAMPUSRUNNER_BOUNCER_H
#define CAMPUSRUNNER_BOUNCER_H


#include "Texture_Manager.h"
#include "Game_Object.h"
/**
 * A bouncer object in the game.
 */

class Bouncer : public Game_Object {
public:
    /**
    * Create the bouncer.
    */
    Bouncer(float x, float y);

    /**
    * Update the bouncer.
    */
    void update() override;

    /**
    * Run the bounce animation when the player is using the bouncer.
    */
    void bounce();

    /**
    * Get the force of the bouncer.
    */
    float get_force() const;

    /**
    * Get the bouncers hitbox.
    */
    sf::FloatRect get_rect() const override;
private:
    /**
    * The force of the bouncer, decides how powerful the bounce will be.
    */
    float force;

    /**
    * The timer that handles the animation of the bouncer.
    */
    sf::Clock timer;

};


#endif //CAMPUSRUNNER_BOUNCER_H
