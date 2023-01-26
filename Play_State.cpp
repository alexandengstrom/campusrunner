//
// Created by alexander on 28.11.22.
//

#include "Play_State.h"

Play_State::Play_State(const std::string &level, int lvl)
        : map{level, lvl} {}

State_Action Play_State::update(sf::RenderWindow &window)
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
    {
        Audio_Manager::stop_game_music();
        Audio_Manager::start_menu_music();
        return State_Action::PAUSE;
    }
    return map.update(window);
};


