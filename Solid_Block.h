//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_SOLID_BLOCK_H
#define CAMPUSRUNNER_SOLID_BLOCK_H

#include <SFML/Graphics.hpp>
#include "Game_Object.h"

/**
* The most common object in the game. A block to walk on.
*/
class Solid_Block : public Game_Object {
public:
    /**
    * Create a solid block.
    */
    Solid_Block(float x, float y, int level, char c);
    Solid_Block(float x, float y, int w, int h);
};

#endif //CAMPUSRUNNER_SOLID_BLOCK_H
