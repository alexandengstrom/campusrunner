//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_TREASURE_H
#define CAMPUSRUNNER_TREASURE_H

#include <SFML/Graphics.hpp>
#include "Game_Object.h"

/**
* A treasure chest containing one of three power ups: 
* Super jump, super speed and ghost mode.
*/
class Treasure : public Game_Object {
public:
    /**
    * Create a treasure chest.
    */
    Treasure(float x, float y);

    /**
    * Sets opened to true.
    */
    void open();

    /**
    * Sets opened to false.
    */
    void close();

    /**
    * Returns true if treasure chest is opened, else false.
    */
    bool is_opened() const;
private:
    /**
    * True if treasure chest has been opened, else false.
    */
    bool opened;
};



#endif //CAMPUSRUNNER_TREASURE_H
