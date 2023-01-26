//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_PAUSE_STATE_H
#define CAMPUSRUNNER_PAUSE_STATE_H

#include "Menu_State.h"
#include "SFML/Graphics.hpp"
#include "Texture_Manager.h"
#include <vector>
#include <stack>

/**
 * State responsible for showing the pause menu.
 */
class Pause_State : public Menu_State {
public:
    /**
    * Create the state.
    */
    explicit Pause_State();
};


#endif //CAMPUSRUNNER_PAUSE_STATE_H
