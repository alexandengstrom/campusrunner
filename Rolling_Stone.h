//
// Created by nikhu200 on 2022-12-08.
//

#ifndef CAMPUSRUNNER_ROLLING_STONE_H
#define CAMPUSRUNNER_ROLLING_STONE_H


#include "Enemy.h"

/**
* A rolling enemy.
*/
class Rolling_Stone : public Enemy {
public:
    /**
    * Create a rolling stone.
    */
    Rolling_Stone(float x, float y);

    /**
    * Updates rolling stone texture based on velocity.
    */
    void update_texture() override;

    /**
    * Returns the hitbox of the rolling stone.
    */
    sf::FloatRect get_rect() const override;

    /**
    * Stops vertical movement in a bouncy manner.
    */
    void stop_vertical() override;

    /**
    * Inverts horizontal movement and adds a slight bounce vertically.
    */
    void change_direction() override;

    /**
    * Updates texture based on moving left or right.
    */
    void update_animation_state() override;

private:
    /**
    * Helps updating texture.
    */
    enum Direction {
        LEFT = 0,
        RIGHT = 100
    };

    /**
    * A direction, left or right.
    */
    Direction direction;

};


#endif //CAMPUSRUNNER_ROLLING_STONE_H
