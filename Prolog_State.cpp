//
// Created by alexander on 02.12.22.
//

#include "Prolog_State.h"
#include "Audio_Manager.h"
#include <string>

Prolog_State::Prolog_State(std::string const& s)
{
    background.setTexture(*(Texture_Manager::get_texture("prolog_background")));

    std::ifstream stream{"levels/" + s};
    std::stringstream data{};
    data << stream.rdbuf();
    std::string string{data.str()};

    font.loadFromFile("fonts/font.ttf");
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(40);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color{181, 214, 245});
    text.setPosition(sf::Vector2{45.f, (WINDOW_HEIGHT/2) - 300.f});
}

State_Action Prolog_State::update(sf::RenderWindow &window)
{
    sf::Event event;
    while ( window.pollEvent(event) )
    {
        switch ( event.type )
        {
            case sf::Event::Closed:
                    return State_Action::EXIT_GAME;
            case sf::Event::KeyPressed:
                if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return) )
                {
                    return State_Action::NEXT_STATE;
                }
                break;
            default:
                break;
        }
    }
    window.draw(background);
    window.draw(text);
    return State_Action::NO_ACTION;
}
