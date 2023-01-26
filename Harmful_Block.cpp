//
// Created by alexander on 01.12.22.
//

#include "Harmful_Block.h"

Harmful_Block::Harmful_Block(float x, float y, int level, char c)
        : Game_Object(x, y, 50, 50)
{
    sprite.setTexture(*(Texture_Manager::get_texture("harmful_block"
						     + std::to_string(level))));
    sprite.setPosition(position);
    if ( c == '^' )
    {
        sprite.setTextureRect(sf::IntRect (0, 0, BLOCKSIZE, BLOCKSIZE));
    }
    else if ( c == 'v' )
    {
        sprite.setTextureRect(sf::IntRect (50, 0, BLOCKSIZE, BLOCKSIZE));
    }
    else if ( c == '<' )
    {
        sprite.setTextureRect(sf::IntRect (0, 50, BLOCKSIZE, BLOCKSIZE));
    }
    else if ( c == '>' )
    {
        sprite.setTextureRect(sf::IntRect (50, 50, BLOCKSIZE, BLOCKSIZE));
    }
};

sf::FloatRect Harmful_Block::get_rect() const
{
    return sf::FloatRect{position.x+10, position.y+25,
                         static_cast<float>(width-10), static_cast<float>(height-25)};
}
