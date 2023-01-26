//
// Created by alexander on 28.11.22.
//

#ifndef CAMPUSRUNNER_TEXTURE_MANAGER_H
#define CAMPUSRUNNER_TEXTURE_MANAGER_H


#include <string>
#include <map>
#include <SFML/Graphics.hpp>

/**
* Library of all textures.
*/
class Texture_Manager {
public:
    /**
    * Deletes all heap allocated textures.
    */
    ~Texture_Manager();
    Texture_Manager(Texture_Manager const & ) = delete;
    Texture_Manager(Texture_Manager const && ) = delete;

    /**
    * Returns a texture to the called object.
    */
    static sf::Texture* get_texture(std::string const& object);
private:
    /**
    * Private constructor.
    */
    Texture_Manager();

    /**
    * Library of all loaded textures.
    */
    std::map<std::string, sf::Texture*> textures;

    /**
    * The one and only instance.
    */
    static Texture_Manager instance;

};


#endif //CAMPUSRUNNER_TEXTURE_MANAGER_H
