//
// Created by nikhu200 on 2022-12-08.
//

#ifndef CAMPUSRUNNER_FAN_H
#define CAMPUSRUNNER_FAN_H


#include "Solid_Block.h"
/**
* A fan in the game. Pushes the player up in the air when the player is above 
* the fan.
*/
class Fan : public Solid_Block {
public:
    /**
    * Create a fan.
    */
    Fan(float x, float y);

    /**
    * Update the animation frame.
    */
    void update() override;

private:
    /**
    * Timer to keep make sure the animation frame is changed at the right time.
    */
    sf::Clock animation_timer;

    /**
    * The current animation frame of the fan.
    */
    int animation_frame;
};


#endif //CAMPUSRUNNER_FAN_H
