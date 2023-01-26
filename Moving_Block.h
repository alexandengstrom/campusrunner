//
// Created by nikhu200 on 2022-12-08.
//

#ifndef CAMPUSRUNNER_MOVING_BLOCK_H
#define CAMPUSRUNNER_MOVING_BLOCK_H

#include "Texture_Manager.h"
#include "Moving_Object.h"

/**
* A moving block in the game. The player can walk on the moving block,
* but cant jump through it.
*/
class Moving_Block : public Moving_Object {
public:
    /**
   * Create a moving block.
   */
    Moving_Block(float x, float y);

    /**
    * Update the moving block. Responsible for moving the block right or left.
    */
    void update(float friction, float gravity) override;

    /**
    * Sets position to starting position of the moving block.
    */
    void reset() override;

    /**
    * Get the hitbox of the game object.
    */
    sf::FloatRect get_rect() const override;

private:
    /**
    * The distance the block is allowed to move.
    */
    float distance;
};


#endif //CAMPUSRUNNER_MOVING_BLOCK_H
