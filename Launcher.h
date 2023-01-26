//
// Created by nikhu200 on 2022-12-07.
//

#ifndef CAMPUSRUNNER_LAUNCHER_H
#define CAMPUSRUNNER_LAUNCHER_H

#include "Game_Object.h"

/**
* A laucher in the game that the player can use to launch himself up in the air.
*/
class Launcher : public Game_Object {
public:
    /**
    * Create a launcher
    */
    Launcher(float x, float y);

    /**
    * Update the texture of the object depending on if the launcher recently 
    * has been launched or not.
    */
    void update() override;

    /**
    * Get the hitbox of the launcher.
    */
    sf::FloatRect get_rect() const override;

    /**
    * Tell the laucher that it has been used.
    */
    void launch();

    /**
    * Returns true if the laucher has been launched in the last second, else false.
    */
    bool is_launched() const;

    /**
    * Reset the laucher.
    */
    void reset();
private:
    /**
    * True if the laucher has been used the last second, else false.
    */
    bool launched;
    bool used;

    /**
    * The timer responsible for resetting the launcher after one second.
    */
    sf::Clock timer;

};


#endif //CAMPUSRUNNER_LAUNCHER_H
