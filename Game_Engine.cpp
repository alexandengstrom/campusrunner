//
// Created by alexander on 28.11.22.
//

#include "Game_Engine.h"
#include "Texture_Manager.h"
#include "Play_State.h"
#include "Prolog_State.h"
#include "Menu_State.h"
#include "constants.h"
#include "Pause_State.h"
#include "Game_Over_State.h"
#include "Game_Complete_State.h"
#include "Audio_Manager.h"
#include <string>
#include <SFML/Audio.hpp>
#include <memory>

Game_Engine::Game_Engine()
        : window{sf::VideoMode (WINDOW_WIDTH, WINDOW_HEIGHT), "Campus Runner"}
        , action{State_Action::NO_ACTION}
        {
            window.setKeyRepeatEnabled(false);
	    window.setVerticalSyncEnabled(true);
	}

void Game_Engine::run()
{
    init_game("levels/levels.cpr");
    Audio_Manager::start_menu_music();

    while ( !states.empty() )
    {
        sf::Event event{};
        while ( window.pollEvent(event) )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    while ( !states.empty() )
                    {
                        states.pop();
                    }
                    action = State_Action::EXIT_GAME;
                    break;
                case sf::Event::KeyPressed:
                    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::N) )
                    {
                        states.pop();
                    }
                    break;
                default:
                    break;
            }
        }
        window.clear(sf::Color::Black);
        if (!states.empty()) {
            action = states.top().get()->update(window);
        }

        switch ( action )
        {
            case State_Action::NEXT_STATE:
                states.pop();
                break;
            case State_Action::PAUSE:
                states.push(std::unique_ptr<State>(new Pause_State{}));
                break;
            case State_Action::GAME_OVER:
                while ( !states.empty() )
                {
                    states.pop();
                }
                states.push(std::unique_ptr<State>(new Game_Over_State{}));
                break;
            case State_Action::RESTART_GAME:
                states.pop();
                init_game("levels/levels.cpr");
                break;
            case State_Action::EXIT_GAME:
                while ( !states.empty() )
                {
                    states.pop();
                }
                break;
            case State_Action::GAME_COMPLETE:
                while ( !states.empty() )
                {
                    states.pop();
                }
                states.push(std::unique_ptr<State>(new Game_Complete_State{}));
                break;
        }
        window.display();
    }
}

void Game_Engine::init_game(std::string const& filename)
{
    std::ifstream stream{filename};
    if ( stream.good() )
    {
        std::string tmp{};
        int level{NUMBER_OF_LEVELS};
        while ( true )
        {
            stream >> tmp;
            if ( tmp == "end" ) { break; }
            states.push(std::unique_ptr<State>(new Play_State{tmp,level}));
            level--;

            stream >> tmp;
            states.push(std::unique_ptr<State>(new Prolog_State{tmp}));

        }
        states.push(std::unique_ptr<State>(new Menu_State{}));
    }
    else
    {
        std::cerr << "Failed to load file: " << filename << std::endl;
    }

}


