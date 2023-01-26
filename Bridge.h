//
// Created by nikhu200 on 2022-12-08.
//

#ifndef CAMPUSRUNNER_BRIDGE_H
#define CAMPUSRUNNER_BRIDGE_H

#include "Texture_Manager.h"
#include "Solid_Block.h"

/**
* A bridge in the game.
*/
class Bridge : public Solid_Block {
public:
    /**
    * Create a bridge.
    */
    Bridge(float x, float y);

    /**
    * Get the hitbox of the bridge.
    */
    sf::FloatRect get_rect() const override;
};


#endif //CAMPUSRUNNER_BRIDGE_H
