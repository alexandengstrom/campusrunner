//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_PLAY_STATE_H
#define CAMPUSRUNNER_PLAY_STATE_H


#include "Map.h"
#include "State.h"
#include <iostream>

/**
* A state in the game. The play state creates a map.
*/
class Play_State : public State {
public:
    /**
    * Create a Play State. 
    * The constructor needs a filename as a string to load the map from.
    */
    Play_State(std::string const& level, int lvl);

    /**
    * Responsible for updating all the objects existing on the map. 
    * Returns a new State Action if the game need to change state.
    */
    State_Action update(sf::RenderWindow & window) override;

private:
    /**
    * The map of the play state.
    */
    Map map;
};


#endif //CAMPUSRUNNER_PLAY_STATE_H
