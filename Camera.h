//
// Created by alexander on 29.11.22.
//

#ifndef CAMPUSRUNNER_CAMERA_H
#define CAMPUSRUNNER_CAMERA_H

#include <SFML/Graphics.hpp>

/**
* A camera that follows the player around the map.
*/
class Camera {
public:
    /**
    * Create a camera.
    */
    Camera();

    /**
    * Calculate where to focus the camera depending on the players position.
    */
    void calculate_offset(sf::Vector2f & position, sf::Vector2f & vel);

    /**
    * Render a game object to the window.
    */
    void render(sf::RenderWindow & window, sf::Sprite & object);

    /**
    * Render a text object to the window.
    */
    void render(sf::RenderWindow & window, sf::Text & object) const;

    /**
    * Tell the camera what the width and the height of the current map is.
    */
    void update_dimensions(float w, float h);

    /**
    * Move the background layers the create a parallax effect.
    */
    void move_layer(std::vector<sf::Sprite> & sprites,
		    sf::Vector2f const& move_factor) const;
private:
    /**
    * The current offset that needs to be subtracted from all objects 
    * positions when rendering a frame.
    */
    sf::Vector2f offset;

    /**
    * The velocity of the camera.
    */
    sf::Vector2f velocity;

    /**
    * The width of the current map.
    */
    float width;

    /**
    * The height of the current map.
    */
    float height;
};


#endif //CAMPUSRUNNER_CAMERA_H
