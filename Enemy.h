//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_ENEMY_H
#define CAMPUSRUNNER_ENEMY_H


#include "Moving_Object.h"
#include "Solid_Block.h"
#include "Harmful_Block.h"
/**
* An enemy in the game.
*/
class Enemy : public Moving_Object {
public:
    /**
    * Create an enemy.
    */
    Enemy(float x, float y);
    Enemy(float x, float y, int w, int h);

    /**
    * Tell the camera that the enemy wants to be rendered, but only if 
    * the enemy is alive.
    */
    void render(sf::RenderWindow & window, Camera & camera) override;

    /**
    * Update the enemy's position if the enemy is alive, also updated 
    * the animation state and texture.
    */
    void update(float friction, float gravity) override;

    /**
    * Tell the enemy to start moving.
    */
    void spawn();

protected:
    /**
    * The speed of the enemy.
    */
    float speed;

    /**
    * Update the animation state of the enemy.
    */
    void update_animation_state() override;
};


#endif //CAMPUSRUNNER_ENEMY_H
