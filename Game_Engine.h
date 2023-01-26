//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_GAME_ENGINE_H
#define CAMPUSRUNNER_GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Texture_Manager.h"
#include <stack>
#include <string>
#include "State_Action.h"

/**
* The Game Engine. The Game Engine is responsible for keeping track of 
* the current state of the game.
*/
class Game_Engine {
public:
    /**
    * Create a Game Engine.
    */
    Game_Engine();
    Game_Engine(Game_Engine const & ) = delete;
    Game_Engine(Game_Engine const && ) = delete;

    /**
    * Responsible for initializing the game and then starting the game loop. 
    * The function is also responsible for changing the current state of the game 
    * when needed.
    */
    void run();
private:
    /**
    * The window of the game.
    */
    sf::RenderWindow window;

    /**
    * A stack containing game states.
    */
    std::stack<std::unique_ptr<State>> states;

    /**
    * Responsible for reading a file containing all levels and then creating 
    * one playstate per level.
    */
    void init_game(std::string const& filename);

    /**
    * The current state action. Decides if states should added or removed from 
    * the stack.
    */
    State_Action action;
};


#endif //CAMPUSRUNNER_GAME_ENGINE_H
