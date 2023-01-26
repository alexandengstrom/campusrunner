//
// Created by nikhu200 on 2022-12-07.
//

#ifndef CAMPUSRUNNER_STATE_ACTION_H
#define CAMPUSRUNNER_STATE_ACTION_H

/**
* Helps game engine to decide what to do next.
*/
enum class State_Action {
    NO_ACTION,
    NEXT_STATE,
    PAUSE,
    GAME_OVER,
    RESTART_GAME,
    EXIT_GAME,
    GAME_COMPLETE
};


#endif //CAMPUSRUNNER_STATE_ACTION_H
