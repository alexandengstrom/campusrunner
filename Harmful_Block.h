//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_HARMFUL_BLOCK_H
#define CAMPUSRUNNER_HARMFUL_BLOCK_H


#include "Game_Object.h"

/**
* A block in the game that is harmful for the player.
*/
class Harmful_Block : public Game_Object {
public:
    /**
    * Create a harmful block.
    */
    Harmful_Block(float x, float y, int level, char c);

    /**
    * Get the blocks hitbox.
    */
    sf::FloatRect get_rect() const override;
};


#endif //CAMPUSRUNNER_HARMFUL_BLOCK_H
