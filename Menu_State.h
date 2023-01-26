//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_MENU_STATE_H
#define CAMPUSRUNNER_MENU_STATE_H

#include "State.h"
#include "SFML/Graphics.hpp"
#include "Texture_Manager.h"
#include <vector>
#include <stack>

enum Menu_Choice {
    START_GAME,
    EXIT
};

/**
 * State responsible for showing the start menu .
 */
class Menu_State : public State {
public:
    /**
     * Create the state.
     */
    explicit Menu_State();

    /**
     * Handles key presses. Updates and renders the menu table.
     * Returns a State Action.
     */
    State_Action update(sf::RenderWindow & window) override;

protected:
    /**
    * The background of the menu.
    */
    sf::Sprite background;

    /**
    * Text in the menu table.
    */
    sf::Text new_game;

    /**
    * Text in the menu table.
    */
    sf::Text exit;

    /**
    * The font used.
    */
    sf::Font font;

    /**
    * A menu choice used to choose which color to render the menu table.
    * Used in execute_command to decide what State Action to return.
    */
    Menu_Choice choice;

    /**
    * Helper that initializes all text-objects used.
    */
    void init_text();

    /**
    * Helper that returns a State Action depending on an integer.
    */
    virtual State_Action execute_command(Menu_Choice choice) const;

    /**
    * Helper to create a text object.
    */
    sf::Text create_text(sf::Font const& font, std::string const& text,
			 sf::Vector2f const&  position);
};


#endif //CAMPUSRUNNER_MENU_STATE_H
