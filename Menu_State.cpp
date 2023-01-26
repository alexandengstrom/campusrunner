//
// Created by alexander on 01.12.22.
//

#include "Menu_State.h"
#include "constants.h"

Menu_State::Menu_State() : choice{}
{
    background.setTexture(*(Texture_Manager::get_texture("menu_background")));
    init_text();
}

State_Action Menu_State::update(sf::RenderWindow & window)
{

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
    {
        if ( choice == EXIT )
        {
            choice = START_GAME;
        }
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
    {
        if( choice == START_GAME )
        {
            choice = EXIT;
        }
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
    {
        return execute_command(choice);
    }
    switch ( choice )
    {
        case START_GAME:
            new_game.setFillColor(sf::Color(0,74,127,255));
            exit.setFillColor(sf::Color(150, 150, 150));
            break;
        case EXIT:
            exit.setFillColor(sf::Color(0,74,127,255));
            new_game.setFillColor(sf::Color(150, 150, 150));
            break;
    }
    window.draw(background);
    window.draw(new_game);
    window.draw(exit);
    return State_Action::NO_ACTION;
}

void Menu_State::init_text()
{
    font.loadFromFile("fonts/font.ttf");
    new_game = create_text(font, "NEW GAME",
			   sf::Vector2f{(WINDOW_WIDTH / 2) - 110.f,
			     (WINDOW_HEIGHT / 2)-40});
    exit = create_text(font, "EXIT",
		       sf::Vector2{(WINDOW_WIDTH / 2) - 40.f,
			 (WINDOW_HEIGHT / 2) + 50.f});
}

sf::Text Menu_State::create_text(sf::Font const& font,
				 std::string const& text,
				 sf::Vector2f const& position)
{
    sf::Text tmp;
    tmp.setFont(font);
    tmp.setString(text);
    tmp.setCharacterSize(100);
    tmp.setPosition(position);
    tmp.setOutlineColor(sf::Color::White);
    tmp.setOutlineThickness(2);
    return tmp;
}

State_Action Menu_State::execute_command(Menu_Choice choice) const
{
    if( choice == START_GAME )
    {
        Audio_Manager::stop_menu_music();
        Audio_Manager::start_game_music();
        return State_Action::NEXT_STATE;
    }
    return State_Action::EXIT_GAME;
}
