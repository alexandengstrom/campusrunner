//
// Created by alexander on 02.12.22.
//

#include "Game_Over_State.h"

Game_Over_State::Game_Over_State() : Menu_State()
{
    background.setTexture(*(Texture_Manager::get_texture("game_over")));
}

State_Action Game_Over_State::execute_command(Menu_Choice choice) const
{
    if(choice == START_GAME)
    {
        return State_Action::RESTART_GAME;
    }
    return State_Action::EXIT_GAME;
}
