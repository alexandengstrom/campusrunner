//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_MAP_H
#define CAMPUSRUNNER_MAP_H


#include "Game_Object.h"
#include "Camera.h"
#include "State_Action.h"
#include "Player.h"
#include "Solid_Block.h"
#include "Enemy.h"
#include "Door.h"
#include "Treasure.h"
#include "Launcher.h"
#include "Bouncer.h"
#include "Flamer.h"
#include "Rolling_Stone.h"
#include "Fan.h"
#include "Moving_Block.h"
#include "Bridge.h"
#include "Checkpoint.h"
#include "Healthpack.h"
#include <vector>
#include <stack>
#include <SFML/Audio/Music.hpp>

/**
* A map in the game. The map creates and holds all game objects 
* that exists on the map.
*/
class Map {
public:
    /**
    * Create a map. The constructor needs a filename as a string to load 
    * the map from.
    */
    Map(std::string const& level, int lvl);

    Map(Map const & ) = delete;
    Map(Map const && ) = delete;

    /**
    * Destructor to make sure all game objects are deleted.
    */
    ~Map();

    /**
    * The camera used in the map
    */
    Camera camera{};

    /**
    * The timer of the map.
    */
    float time;

    /**
    * Responsible for updating all the objects existing on the map. 
    * Returns a new State Action if the game need to change state.
    */
    State_Action update(sf::RenderWindow & window);

private:
    /**
    * The width of the map.
    */
    float width;

    /**
    * The height of the map.
    */
    float height;

    /**
    * The level of the map
    */
    int lvl;

    /**
    * The opacity of the checkpoint text.
    */
    int checkpoint_opacity;

    /**
    * The gravity of the map.
    */
    float gravity;

    /**
    * The friction of the map.
    */
    float friction;

    /**
    * True if the map has been completed, else false.
    */
    bool level_complete;

    /**
    * True if the game is over, else false.
    */
    bool game_over;

    /**
    * True if the player is colliding with a treasure, else false. 
    * This variable is used to show a helper text.
    */
    bool standing_on_treasure;

    /**
    * True if the player is colliding with a door, else false. 
    * This variable is used to show a helper text.
    */
    bool standing_on_door;

    /**
    * True if the player is colliding with a launcher, else false. 
    * This variable is used to show a helper text.
    */
    bool standing_on_launcher;

    /**
    * True when the checkpoint animation is running, else false.
    */
    bool checkpoint_animation_active;

    /**
    * Timer to handle the animation of the checkpoint text.
    */
    sf::Clock checkpoint_timer;

    //Background layers
    /**
    * A vector that holds two copies of the background layer 1. 
    * This is used for parallax scrolling.
    */
    std::vector<sf::Sprite> layer1;

    /**
    * A vector that holds two copies of the background layer 2. 
    * This is used for parallax scrolling.
    */
    std::vector<sf::Sprite> layer2;

    /**
    * A vector that holds two copies of the background layer 3. 
    * This is used for parallax scrolling.
    */
    std::vector<sf::Sprite> layer3;

    /**
    * A vector that holds two copies of the background layer 4. 
    * This is used for parallax scrolling.
    */
    std::vector<sf::Sprite> layer4;

    //Game objects
    /**
    * A vector that holds pointers to all game objects 
    * that exists on the map.
    */
    std::vector<Game_Object*> game_objects;

    //Text objects
    /**
    * The font used.
    */
    sf::Font font;

    /**
    * Text that shows the players lives.
    */
    sf::Text lives;

    /**
    * Text that shows how much time is left to complete the level.
    */
    sf::Text timer;

    /**
    * Text that shows the current level.
    */
    sf::Text current_level;

    /**
    * Text that shows the current powerup, 
    * empty if the player doesn't have a powerup.
    */
    sf::Text current_power_up;

    /**
    * Text that described how to open a treasure. 
    * Only visible when it is possible to interact with the treasure.
    */
    sf::Text treasure_helper;

    /**
    * Text that described how to open a door. 
    * Only visible when it is possible to interact with the door.
    */
    sf::Text door_helper;

    /**
    * Text that described how to use a launcher. 
    * Only visible when it is possible to interact with the launcher.
    */
    sf::Text launcher_helper;

    /**
    * Text that shows up when the player has reached a checkpoint.
    */
    sf::Text checkpoint_helper;

    //Init map
    /**
    * Function that initializes all text-objects used.
    */
    void init_text();

    /**
    * Create a text-object.
    */
    sf::Text create_text(sf::Font const& font, std::string const& text,
			 int char_size, sf::Color fill_color,
			 sf::Color outline_color, float outline_thickness,
			 sf::Vector2f const& position);

    /**
    * Initialize the map and all game objects that exists in the map. 
    * The functions need a filename as a string to load the map from.
    */
    void init_map(std::string const& level);

    /**
    * Initialize the background layers.
    */
    void init_backgrounds();

    /**
    * Initialize one background layer.
    */
    std::vector<sf::Sprite> init_layer(int layer);

    //Draw
    /**
    * Update the positions of the background-layers.
    */
    void update_backgrounds();

    /**
    * Render the backgrounds to the window.
    */
    void render_backgrounds(sf::RenderWindow & window);

    /**
    * Go through all game objects in the map and let them render if they want.
    */
    void render_objects(sf::RenderWindow & window);

    /**
    * Render the text-objects that should be visible.
    */
    void manage_text(sf::RenderWindow & window);

    /**
    * Start the checkpoint animation.
    */
    void run_checkpoint_animation();

    //End
    /**
    * Restart the level, resets all moving objects to their 
    * starting positions or checkpoint position.
    */
    void restart();

    /**
    * Check if the player if outside the map. 
    * If the player tries to go out of the map horizontally the player will be
    * stopped. If the player falls below the map the player is killed.
    */
    void out_of_bounds(Player * player) const;

    //Collisions
    enum Collision_Direction
    {
        NO_COLLISION,
        FROM_TOP,
        FROM_BOTTOM,
        FROM_LEFT,
        FROM_RIGHT
    };

    /**
    * Function responsible for detecting collisions between game objects.
    */
    void manage_collisions();

    //Player
    /**
    * Check if a player is colliding with a solid block. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Solid_Block * block);

    /**
    * Check if a player is colliding with an enemy. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Enemy * enemy);

    /**
    * Check if a player is colliding with an harmful block. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Harmful_Block * block);

    /**
    * Check if a player is colliding with an door. 
    * If a collision is detected the player has the option to open the door
    * and complete the level.
    */
    void check_collision(Player * player, Door * door);

    /**
    * Check if a player is colliding with an treasure. 
    * If a collection is detected the player can open the treasure and
    * gain a random powerup.
    */
    void check_collision(Player * player, Treasure * treasure);

    /**
    * Check if a player is colliding with an lanucher. 
    * If a collision is detected the player can launch the laucher.
    */
    void check_collision(Player * player, Launcher *  launcher);

    /**
    * Check if a player is colliding with a bouncer. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Bouncer * bouncer);

    /**
    * Check if a player is colliding with a flamer. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Flamer * flamer);

    /**
    * Check if a player is colliding with a fan. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Fan * fan);

    /**
    * Check if a player is colliding with a moving block. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Player * player, Moving_Block * block);

    /**
    * Check if a player is colliding with a checkpoint. 
    * If a collection is detected, update the players starting position.
    */
    void check_collision(Player * player, Checkpoint * checkpoint);

    /**
    * Check if a player is colliding with a healthpack. 
    * If a collection is detected, increase the players health
    */
    void check_collision(Player * player, Healthpack * healthpack);

    //Enemy
    /**
    * Check if an enemy is colliding with a solid block. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Enemy * enemy, Solid_Block * block);

    /**
    * Check if an enemy is colliding with an enemy. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Enemy * enemy, Enemy * other_enemy);

    /**
    * Check if an enemy is colliding with a harmful block. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Enemy * enemy, Harmful_Block * block);

    /**
    * Check if the enemy is trying to walk outside the map, 
    * in that case, tell the enemy to turn around.
    */
    void out_of_bounds(Enemy * enemy) const;

    //Moving_Block
    /**
    * Check if a moving block is colliding with any game object. 
    * If a collection is detected, tell the objects what to do.
    */
    void check_collision(Moving_Block * block, Game_Object * object);

    /**
    * Responsible for detecting from which direction a collisions occurs.
    */
    Collision_Direction detect_collision_direction(Moving_Object * lhs,
						   Game_Object * rhs);
};


#endif //CAMPUSRUNNER_MAP_H
