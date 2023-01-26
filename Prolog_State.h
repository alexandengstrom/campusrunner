//
// Created by alexander on 02.12.22.
//

#ifndef CAMPUSRUNNER_PROLOG_STATE_H
#define CAMPUSRUNNER_PROLOG_STATE_H


#include <SFML/Graphics.hpp>
#include "State.h"
#include "Texture_Manager.h"

class Prolog_State : public State {
public:
    /**
    * Create the state. The constructor needs a filename
    * as a string to load the state from.
    */
    explicit Prolog_State(std::string const& s);

    /**
    * Handles key and close window button presses.
    * Returns a State Action.
    */
    State_Action update(sf::RenderWindow & window) override;

private:
    /**
    * The font used.
    */
    sf::Font font;

    /**
    *  A text.
    */
    sf::Text text;

    /**
    * The background of the state.
    */
    sf::Sprite background;
};


#endif //CAMPUSRUNNER_PROLOG_STATE_H
