//
// Created by alexander on 28.11.22.
//

#include <iostream>
#include "Texture_Manager.h"
#include "constants.h"

Texture_Manager::Texture_Manager()
{
    //Menu backgrounds
    textures["menu_background"] = new sf::Texture;
    textures["menu_background"]->loadFromFile("textures/menu/menu_background.png");
    textures["prolog_background"] = new sf::Texture;
    textures["prolog_background"]->loadFromFile("textures/menu/prolog_background.png");
    textures["game_over"] = new sf::Texture;
    textures["game_over"]->loadFromFile("textures/menu/game_over_background.png");
    textures["game_complete"] = new sf::Texture;
    textures["game_complete"]->loadFromFile("textures/menu/game_complete_background.png");
    textures["paused_background"] = new sf::Texture;
    textures["paused_background"]->loadFromFile("textures/menu/pause_background.png");


    //Objects
    textures["player"] = new sf::Texture;
    textures["player"]->loadFromFile("textures/common/player.png");
    textures["enemy"] = new sf::Texture;
    textures["enemy"]->loadFromFile("textures/common/enemy.png");
    textures["treasure"] = new sf::Texture;
    textures["treasure"]->loadFromFile("textures/common/treasure.png");
    textures["launcher"] = new sf::Texture;
    textures["launcher"]->loadFromFile("textures/common/launcher.png");
    textures["bouncer"] = new sf::Texture;
    textures["bouncer"]->loadFromFile("textures/common/bouncer.png");
    textures["flamer"] = new sf::Texture;
    textures["flamer"]->loadFromFile("textures/common/flamer.png");
    textures["rolling_stone"] = new sf::Texture;
    textures["rolling_stone"]->loadFromFile("textures/common/rolling_stone.png");
    textures["fan"] = new sf::Texture;
    textures["fan"]->loadFromFile("textures/common/fan.png");
    textures["moving_block"] = new sf::Texture;
    textures["moving_block"]->loadFromFile("textures/common/moving_block.png");
    textures["checkpoint"] = new sf::Texture;
    textures["checkpoint"]->loadFromFile("textures/common/checkpoint.png");
    textures["healthpack"] = new sf::Texture;
    textures["healthpack"]->loadFromFile("textures/common/healthpack.png");
    textures["bridge"] = new sf::Texture;
    textures["bridge"]->loadFromFile("textures/common/bridge.png");

    //Level loop
    for (int i{1}; i < NUMBER_OF_LEVELS+1; i++)
    {
        //Background layers
        textures["level" + std::to_string(i) + "_layer1"] = new sf::Texture;
        textures["level" + std::to_string(i) + "_layer1"]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/layer1.png");
	
        textures["level" + std::to_string(i) + "_layer2"] = new sf::Texture;
        textures["level" + std::to_string(i) + "_layer2"]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/layer2.png");
	
        textures["level" + std::to_string(i) + "_layer3"] = new sf::Texture;
        textures["level" + std::to_string(i) + "_layer3"]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/layer3.png");
	
        textures["level" + std::to_string(i) + "_layer4"] = new sf::Texture;
        textures["level" + std::to_string(i) + "_layer4"]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/layer4.png");

        //Objects
        textures["harmful_block" + std::to_string(i)] = new sf::Texture;
        textures["harmful_block" + std::to_string(i)]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/harmful_block.png");
	
        textures["solid_block" + std::to_string(i)] = new sf::Texture;
        textures["solid_block" + std::to_string(i)]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/solid_block.png");
	
        textures["door" + std::to_string(i)] = new sf::Texture;
        textures["door" + std::to_string(i)]
	  ->loadFromFile("textures/level" + std::to_string(i) + "/door.png");
    }
}

Texture_Manager::~Texture_Manager()
{
    for (std::pair<std::string, sf::Texture *> element: textures)
    {
        delete element.second;
    }
}

sf::Texture* Texture_Manager::get_texture(std::string const& object)
{
    return instance.textures.at(object);
}

Texture_Manager Texture_Manager::instance;
