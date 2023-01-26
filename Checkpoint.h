
//
// Created by nikhu200 on 2022-12-09.
//

#ifndef CAMPUSRUNNER_CHECKPOINT_H
#define CAMPUSRUNNER_CHECKPOINT_H


#include "Game_Object.h"

/**
* A checkpoint in the game.
*/
class Checkpoint : public Game_Object {
public:
    /**
    * Create a checkpoint.
    */
    Checkpoint(float x, float y);

    /**
    * Returns if the checkpoint has been reached or not.
    */
    bool is_reached() const;

    /**
    * Tell the checkpoint it has been reached.
    */
    void touchdown();

private:
    /**
    * True if the checkpoint has been reached, else false.
    */
    bool reached;
};


#endif //CAMPUSRUNNER_CHECKPOINT_H
