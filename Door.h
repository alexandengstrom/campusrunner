//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_DOOR_H
#define CAMPUSRUNNER_DOOR_H


#include "Texture_Manager.h"
#include "Game_Object.h"

/**
* A door in the game. The door is the finish of a level and when entering 
* the door the level is complete.
*/
class Door : public Game_Object {
    public:
        /**
        * Create a door.
        */
        Door(float x, float y, int level);
};


#endif //CAMPUSRUNNER_DOOR_H
