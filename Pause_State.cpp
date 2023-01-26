//
// Created by alexander on 01.12.22.
//

#include "Pause_State.h"

#include "constants.h"
#include <stack>

Pause_State::Pause_State() : Menu_State()
{
    new_game.setString("RESUME");
    new_game.setPosition((WINDOW_WIDTH/2)-70.f, (WINDOW_HEIGHT / 2)-40);
    background.setTexture(*(Texture_Manager::get_texture("paused_background")));
}
