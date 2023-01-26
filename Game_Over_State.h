//
// Created by alexander on 02.12.22.
//

#ifndef CAMPUSRUNNER_GAME_OVER_STATE_H
#define CAMPUSRUNNER_GAME_OVER_STATE_H

#include "Menu_State.h"

/**
 * State responsible for showing the menu when all lives are lost.
 */
class Game_Over_State : public Menu_State {
public:
    /**
    * Create the state.
    */
    explicit Game_Over_State();

private:
    /**
    * Helper that returns a State Action depending on an integer.
    */
    State_Action execute_command(Menu_Choice choice) const override;
};

#endif //CAMPUSRUNNER_GAME_OVER_STATE_H
