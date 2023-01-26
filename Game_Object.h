//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_GAME_OBJECT_H
#define CAMPUSRUNNER_GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "Texture_Manager.h"
#include "Camera.h"
#include "State.h"

/**
* The interface of all game objects.
*/
class Game_Object {
public:
    /**
    * Create a game object.
    */
    Game_Object(float x, float y, int w, int h);
    virtual ~Game_Object() = default;

    /**
    * Update the game object. The default behavior is to update 
    * the sprites position to the current position.
    */
    virtual void update();

    /**
    * Tell the camera that the object is ready to be rendered to the screen.
    */
    virtual void render(sf::RenderWindow & window, Camera & camera);

    /**
    * Get the hitbox of the game object.
    */
    virtual sf::FloatRect get_rect() const;

    /**
    * Returns the position of the game object.
    */
    sf::Vector2f get_position() const;

protected:
    /**
    * The current position of the game object.
    */
    sf::Vector2f position;

    /**
    * The width of the game object.
    */
    int width;

    /**
    * The height of the game object.
    */
    int height;

    /**
    * The sprite of the game object.
    */
    sf::Sprite sprite;
};


#endif //CAMPUSRUNNER_GAME_OBJECT_H
