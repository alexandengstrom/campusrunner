//
// Created by alexander on 01.12.22.
//

#ifndef CAMPUSRUNNER_CONSTANTS_H
#define CAMPUSRUNNER_CONSTANTS_H

#include <SFML/System/Vector2.hpp>

/**
* The height of the window.
*/
constexpr int WINDOW_HEIGHT{768};

/**
* The width of the window.
*/
constexpr int WINDOW_WIDTH{1024};

/**
* The number of available levels.
*/
constexpr int NUMBER_OF_LEVELS{6};

/**
* The diameter of a standard block.
*/
constexpr float BLOCKSIZE{50.0f};

/**
* The timelimit of all levels.
*/
constexpr float TIME_LIMIT{151};

/**
* The players jumpforce.
*/
constexpr float JUMP{20.f};

/**
* How much the superjump powerup affects the normal jumpforce.
*/
constexpr float SUPER_JUMP{1.5f};

/**
* The normal speed of the player
*/
constexpr float SPEED{5.f};

/**
* How much the speed is incresed when using a superspeed powerup.
*/
constexpr float SUPER_SPEED{2.5f};

/**
* How much the second background-layer should move when the player moves.
*/
sf::Vector2f const MOVE_RATE_LAYER2{25.f, 15.f};

/**
* How much the third background-layer should move when the player moves.
*/
sf::Vector2f const MOVE_RATE_LAYER3{15.f, 7.f};

/**
* How much the fourth background-layer should move when the player moves.
*/
sf::Vector2f const MOVE_RATE_LAYER4{4.f, 2.f};


#endif //CAMPUSRUNNER_CONSTANTS_H
