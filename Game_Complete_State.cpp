//
// Created by nikhu200 on 2022-12-12.
//

#include "Game_Complete_State.h"

Game_Complete_State::Game_Complete_State() : Game_Over_State()
{
    background.setTexture(*(Texture_Manager::get_texture("game_complete")));
}
