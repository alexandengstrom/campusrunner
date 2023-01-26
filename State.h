//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_STATE_H
#define CAMPUSRUNNER_STATE_H


#include <SFML/Graphics.hpp>
#include <stack>
#include <sstream>
#include <fstream>
#include "constants.h"
#include "State_Action.h"
#include "Audio_Manager.h"

/**
* Interface of the different states in the game.
*/
class State {
public:
    State() = default;
    /**
    * Virtual destructor of the state.
    */
    virtual ~State() = default;
    State(State const & ) = delete;
    State(State const && ) = delete;

    /**
    * No standard behaviour.
    */
    virtual State_Action update(sf::RenderWindow & window) = 0;
};


#endif //CAMPUSRUNNER_STATE_H
