//
// Created by alexander on 15.12.22.
//

#include "Audio_Manager.h"
#include <cmath>
#include <iostream>
#include "constants.h"

Audio_Manager::Audio_Manager() {
    create_sound("jump", 20.f);
    create_sound("bounce", 60.f);
    create_sound("enemy_killed", 13.f);
    create_sound("player_killed", 70.f);
    create_sound("healthpack", 20.f);
    create_sound("checkpoint", 40.f);
    create_sound("launcher", 30.f);
    create_sound("treasure", 50.f);
    create_sound("rolling_stone", 30.f);
    create_sound("level_completed", 30.f);
    create_sound("fan", 30.f);
    create_sound("flamer", 30.f);
    create_sound("end_of_jump", 15.f);
    create_sound("game_over", 30.f);

    create_music("main_music", 50.f);
    create_music("menu_music", 35.f);
}

void Audio_Manager::jump() {
    instance.sounds.at("jump")->play();
}

void Audio_Manager::bounce() {
    instance.sounds.at("bounce")->play();
}

void Audio_Manager::enemy_killed() {
    instance.sounds.at("enemy_killed")->play();
}

void Audio_Manager::launch() {
    instance.sounds.at("launcher")->play();
}

void Audio_Manager::healthpack_picked_up() {
    instance.sounds.at("healthpack")->play();
}

void Audio_Manager::player_killed() {
    instance.sounds.at("player_killed")->play();
}

void Audio_Manager::checkpoint_reached() {
    instance.sounds.at("checkpoint")->play();
}

void Audio_Manager::open_treasure() {
    instance.sounds.at("treasure")->play();
}

void Audio_Manager::create_sound(const std::string &sound, float volume) {
    buffers[sound] = new sf::SoundBuffer;
    sounds[sound] = new sf::Sound;
    buffers.at(sound)->loadFromFile("sounds/"+ sound + ".ogg");
    sounds.at(sound)->setVolume(volume);
    sounds.at(sound)->setBuffer(*buffers.at(sound));
}

void Audio_Manager::create_music(std::string const & m, float volume)
{
    music[m] = new sf::Music;
    music[m]->openFromFile("music/" + m + ".ogg");
    music[m]->setVolume(volume);
    music[m]->setLoop(true);
}

void Audio_Manager::rolling_stone(sf::Vector2f const& position
                                  , sf::Vector2f const &velocity) {
    if (hearable(position) && velocity.y > 9)
    {
        float volume = (3*velocity.y)-10.f;
        if (!in_screen(position))
        {
            volume -= 0.1f;
        }

        if (volume > 100) {volume = 99;}
        else if (volume < 0) {volume = 0;}

        instance.sounds.at("rolling_stone")->setVolume(volume);
        instance.sounds.at("rolling_stone")->play();
    }
}

Audio_Manager::~Audio_Manager() {
    for (std::pair<std::string, sf::SoundBuffer *> object : buffers)
    {
        delete object.second;
    }

    for (std::pair<std::string, sf::Sound *> object : sounds)
    {
        delete object.second;
    }

    for (std::pair<std::string, sf::Music *> object : music)
    {
        delete object.second;
    }
}

bool Audio_Manager::hearable(const sf::Vector2f &position) {
    return (position.x >= - 300 && position.x <= WINDOW_WIDTH + 300
           && (position.y >= - 500 && position.y <= WINDOW_HEIGHT + 500));
}

bool Audio_Manager::in_screen(sf::Vector2f const & position)
{
    return !(position.x < 0 || position.x > WINDOW_WIDTH ||
     position.y < 0 || position.y > WINDOW_HEIGHT);
}

void Audio_Manager::start_game_music() {
    instance.music.at("main_music")->play();
}

void Audio_Manager::stop_game_music() {
    instance.music.at("main_music")->stop();
}

void Audio_Manager::start_menu_music() {
    instance.music.at("menu_music")->play();
}

void Audio_Manager::stop_menu_music() {
    instance.music.at("menu_music")->stop();
}

void Audio_Manager::level_complete() {
    instance.sounds.at("level_completed")->play();
}

void Audio_Manager::fan(const sf::Vector2f &position) {
    if (hearable(position))
    {
        float volume;
        volume = 20 + (50 / (fabs(position.x - (WINDOW_WIDTH/2))) * 100);
        volume -= (50 / (fabs(position.y - (WINDOW_HEIGHT/2))) * 100);
        if (volume < 0) {volume = 0;}
        instance.sounds.at("fan")->setVolume(volume);

        if ( instance.sounds.at("fan")->getStatus() != sf::SoundSource::Playing )
        {
            instance.sounds.at("fan")->play();
        }
    }
    else
    {
        if (instance.sounds.at("fan")->getVolume() > 1) {
            instance.sounds.at("fan")->setVolume(
                    instance.sounds.at("fan")->getVolume() - 0.2f
            );
        }
    }

}

void Audio_Manager::flame(const sf::Vector2f &position) {
    if (in_screen(position) && instance.sounds.at("flamer")->getStatus() != sf::SoundSource::Playing )
    {
        instance.sounds.at("flamer")->play();
    }
}

void Audio_Manager::end_of_jump() {
    if (instance.sounds.at("end_of_jump")->getStatus() != sf::SoundSource::Playing )
    {
        instance.sounds.at("end_of_jump")->play();
    }
}

void Audio_Manager::game_over() {
    instance.sounds.at("game_over")->play();
}


Audio_Manager Audio_Manager::instance;
