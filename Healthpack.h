//
// Created by alexander on 10.12.22.
//

#ifndef CAMPUSRUNNER_HEALTHPACK_H
#define CAMPUSRUNNER_HEALTHPACK_H


#include "Game_Object.h"

/**
* A healthpack in the game that the player can pick up to increase its health.
*/
class Healthpack : public Game_Object {
public:
    /**
    * Create a healthpack
    */
    Healthpack(float x, float y);

    /**
    * Updates the texture of the healthpack.
    */
    void update() override;

    /**
    * Returns true if the healthpack is used, else false.
    */
    bool is_used() const;

    /**
    * Tell the healthpack it has been used
    */
    void use();

    /**
    * Tell the camera that the healthpack is ready to be rendered, 
    * but only if it has not been used.
    */
    void render(sf::RenderWindow & window, Camera & camera) override;

private:
    /**
    * The timer responsible for making sure the animation frame is changed 
    * at the right time.
    */
    sf::Clock animation_timer;

    /**
    * The current animation frame.    */
    int animation_frame;

    /**
    * Update the texture of the healthpack.
    */
    void update_texture();

    /**
    * True if the healthpack has been used, else false.
    */
    bool picked_up;



};


#endif //CAMPUSRUNNER_HEALTHPACK_H
