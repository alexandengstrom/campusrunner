//
// Created by alexander on 28.11.22.
//

#include "Solid_Block.h"

Solid_Block::Solid_Block(float x, float y, int level, char c) :
        Game_Object(x, y, BLOCKSIZE, BLOCKSIZE)
        {
            sprite.setTexture(*(Texture_Manager::get_texture("solid_block"
						     + std::to_string(level))));
            sprite.setPosition(position);
            if ( c == '#' )
            {
                sprite.setTextureRect(sf::IntRect (0, 0, BLOCKSIZE, BLOCKSIZE));
            }
            else if ( c == '=' )
            {
                sprite.setTextureRect(sf::IntRect (50, 0, BLOCKSIZE, BLOCKSIZE));
            }
            else if ( c == '[' )
            {
                sprite.setTextureRect(sf::IntRect (0, 50, BLOCKSIZE, BLOCKSIZE));
            }
            else if ( c == ']' )
            {
                sprite.setTextureRect(sf::IntRect (50, 50, BLOCKSIZE, BLOCKSIZE));
            }
        }



Solid_Block::Solid_Block(float x, float y, int w, int h)
  : Game_Object(x, y, w, h) {};
