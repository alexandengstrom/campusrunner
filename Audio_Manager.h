//
// Created by alexander on 15.12.22.
//

#ifndef CAMPUSRUNNER_AUDIO_MANAGER_H
#define CAMPUSRUNNER_AUDIO_MANAGER_H


#include <SFML/Audio.hpp>
#include <map>

/**
 * The Audio Manager handles all the sound in the game.
 */
class Audio_Manager {
public:
    /**
    * Handles the memory.
    */
    ~Audio_Manager();
    Audio_Manager(Audio_Manager const & ) = delete;
    Audio_Manager(Audio_Manager const && ) = delete;

    /**
    * Starts the main theme.
    */
    static void start_game_music();

    /**
    * Stops the main theme.
    */
    static void stop_game_music();

    /**
    * Starts the menu music.
    */
    static void start_menu_music();

    /**
    * Stops the menu music.
    */
    static void stop_menu_music();

    /**
    * Plays a jump-sound.
    */
    static void jump();

    /**
    * Plays a bounce-sound.
    */
    static void bounce();

    /**
    * Plays a enemy killed-sound.
    */
    static void enemy_killed();

    /**
    * Plays the launcher-sound.
    */
    static void launch();

    /**
    * Plays the healthpack pickup-sound.
    */
    static void healthpack_picked_up();

    /**
    * Plays the death-sound.
    */
    static void player_killed();

    /**
    * Plays the checkpoint-sound.
    */
    static void checkpoint_reached();

    /**
    * Plays the treasure-sound.
    */
    static void open_treasure();

    /**
    * Plays the rolling stone-sound. The volume varies depending on
     * how far away the stone is and how fast the stone is falling.
    */
    static void rolling_stone(sf::Vector2f const & position, sf::Vector2f const & velocity);

    /**
    * Plays the level complete-sound.
    */
    static void level_complete();

    /**
    * Plays the fan-sound.
    */
    static void fan(sf::Vector2f const & position);

    /**
    * Plays flamer-sound when it is flaming, but only if a flamer is visible.
    */
    static void flame(sf::Vector2f const & position);

    /**
    * Plays the sound of landing a jump.
    */
    static void end_of_jump();

    /**
    * Plays the game over-sound.
    */
    static void game_over();

    /**
    * Contains all soundbuffers.
    */
    std::map<std::string, sf::SoundBuffer *> buffers;

    /**
   * Contains all sounds.
   */
    std::map<std::string, sf::Sound *> sounds;

    /**
    * Contains all music.
    */
    std::map<std::string, sf::Music *> music;

private:
    /**
    * Only we can create an instance of the class.
    */
    Audio_Manager();

    /**
    * The only instance.
    */
    static Audio_Manager instance;

    /**
    * Initialize a sound.
    */
    void create_sound(std::string const & sound, float volume);

    /**
    * Initialize music.
    */
    void create_music(std::string const & music, float volume);

    /**
    * Returns true if the object can be heard, else false.
    */
    static bool hearable(sf::Vector2f const & position);

    /**
    * Returns true if the object is visible, else false.
    */
    static bool in_screen(sf::Vector2f const & position);
};


#endif //CAMPUSRUNNER_AUDIO_MANAGER_H
