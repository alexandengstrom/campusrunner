//
// Created by alexander on 28.11.22.
//

#include "Map.h"
#include <iostream>
#include <vector>
#include "constants.h"
#include "Healthpack.h"
#include "Audio_Manager.h"


Map::Map(std::string const& level, int lvl)
        : lives{}
        , lvl{lvl}
        , time{TIME_LIMIT}
        , level_complete{false}
        , game_over{false}
        , standing_on_treasure{false}
        , standing_on_door{false}
        , standing_on_launcher{false}
        , checkpoint_animation_active{false}
        , checkpoint_opacity{255}
{
    init_text();
    init_map(level);
    init_backgrounds();
}

Map::~Map() {
    for ( Game_Object* element : game_objects )
    {
        delete element;
    }
}

State_Action Map::update(sf::RenderWindow & window)
{
    standing_on_treasure = false;
    standing_on_door = false;
    standing_on_launcher = false;

    manage_collisions();

    time -= 1.f/60.f;

    render_backgrounds(window);
    render_objects(window);

    if ( level_complete )
    {
        Audio_Manager::level_complete();
        if ( lvl == NUMBER_OF_LEVELS )
        {
            return State_Action::GAME_COMPLETE;
        }
        return State_Action::NEXT_STATE;
    }
    if ( game_over )
    {
        Audio_Manager::stop_game_music();
        Audio_Manager::game_over();
        return State_Action::GAME_OVER;
    }
    manage_text(window);
    return State_Action::NO_ACTION;
}

void Map::init_text()
{
    font.loadFromFile("fonts/font.ttf");
    lives = create_text(font
            , "Lives: "
            , 40
            , sf::Color::Black
            , sf::Color::White
            ,1.f
            ,sf::Vector2{WINDOW_WIDTH - 125.f, 50.0f});
    timer = create_text(font
            , "Time: "
            , 40
            , sf::Color::Black
            , sf::Color::White
            ,1.f
            , sf::Vector2{WINDOW_WIDTH / 2 - 25.f, 50.0f});
    current_level = create_text(font
            , "Level: " + std::to_string(lvl)
            , 40
            , sf::Color::Black
            , sf::Color::White
            ,1.f
            , sf::Vector2{50.f, 50.0f});
    current_power_up = create_text(font
            , "", 40
            , sf::Color::Red
            , sf::Color::Black
            ,1.f
            ,sf::Vector2{WINDOW_WIDTH / 2 - 140.f, 200.0f});

    treasure_helper = create_text(font
            , "PRESS SPACE TO OPEN"
            , 50
            , sf::Color::Black
            ,sf::Color::White
            , 2.f
            ,sf::Vector2{50.f, 50.0f});
    door_helper = create_text(font
            , "PRESS SPACE TO PROCEED"
            , 50
            , sf::Color::Black
            ,sf::Color::White
            , 2.f
            ,sf::Vector2{50.f, 50.0f});
    launcher_helper = create_text(font
            , "     PRESS SPACE TO LAUNCH"
            , 50
            , sf::Color::Black
            ,sf::Color::White
            , 2.f
            ,sf::Vector2{50.f, 50.0f});
    checkpoint_helper = create_text(font
            , "CHECKPOINT"
            , 250
            , sf::Color(0,0,204,checkpoint_opacity)
            , sf::Color::White
            , 5.f
            ,sf::Vector2{200.f, 100.f});
}

sf::Text Map::create_text(sf::Font const& font, std::string const& text
                          , int char_size, sf::Color fill_color
                          , sf::Color outline_color, float outline_thickness
                          , sf::Vector2f const& position)
{
    sf::Text tmp;
    tmp.setFont(font);
    tmp.setString(text);
    tmp.setCharacterSize(char_size);
    tmp.setFillColor(fill_color);
    tmp.setOutlineColor(outline_color);
    tmp.setOutlineThickness(outline_thickness);
    tmp.setPosition(position);
    return tmp;
}
void Map::manage_text(sf::RenderWindow & window)
{
    if ( standing_on_treasure )
    {
        camera.render(window, treasure_helper);
    }
    if ( standing_on_door )
    {
        camera.render(window, door_helper);
    }
    if ( standing_on_launcher )
    {
        camera.render(window, launcher_helper);
    }
    if ( checkpoint_animation_active )
    {
        window.draw(checkpoint_helper);
        run_checkpoint_animation();
    }
    timer.setString("Time: " + std::to_string(static_cast<int>(time)));
    window.draw(current_level);
    window.draw(timer);
    window.draw(lives);
    window.draw(current_power_up);
}

void Map::init_map(std::string const& level)
{
    std::ifstream stream{"levels/" + level};
    if ( stream.good() ) {
        stream >> gravity;
        stream >> friction;
        std::stringstream data{};
        data << stream.rdbuf();
        std::string map{data.str()};
        std::cout << map << std::endl;
        float row{0};
        float col{0};
        for (char element: map) {
            if (element == '#' || element == '[' || element == ']' || element == '=') {
                game_objects.push_back(new Solid_Block{
                        col * BLOCKSIZE, row * BLOCKSIZE, lvl, element});
            } else if (element == '@') {
                game_objects.push_back(new Player{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == '!') {
                game_objects.push_back(new Enemy{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == '^' || element == 'v' || element == '<' || element == '>') {
                game_objects.insert(game_objects.begin(), new Harmful_Block{
                        col * BLOCKSIZE, row * BLOCKSIZE, lvl, element});
            } else if (element == '+') {
                game_objects.insert(game_objects.begin(),
                                    new Door{col * BLOCKSIZE,
                                             row * BLOCKSIZE,
                                             lvl});
            } else if (element == '$') {
                game_objects.insert(game_objects.begin(),
                                    new Treasure{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'O') {
                game_objects.insert(game_objects.begin(),
                                    new Launcher{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'o') {
                game_objects.insert(game_objects.begin(),
                                    new Bouncer{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'F') {
                game_objects.insert(game_objects.begin(),
                                    new Flamer{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'B') {
                game_objects.insert(game_objects.begin(),
                                    new Bridge{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'R') {

                game_objects.insert(game_objects.begin(),
                                    new Rolling_Stone{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'f') {
                game_objects.insert(game_objects.begin(),
                                    new Fan{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == '~') {
                game_objects.insert(game_objects.begin(),
                                    new Moving_Block{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == 'C') {
                game_objects.insert(game_objects.begin(),
                                    new Checkpoint{col * BLOCKSIZE, row * BLOCKSIZE});
            } else if (element == '*') {
                game_objects.insert(game_objects.begin(),
                                    new Healthpack{col * BLOCKSIZE, row * BLOCKSIZE});
            }

            if (element == '\n') {
                row += 1;
                width = col * BLOCKSIZE;
                col = 0;
            } else {
                col += 1;
            }
        }
        std::cout << game_objects.size() << std::endl;
        height = row * BLOCKSIZE;
        camera.update_dimensions(width, height);
    }
    else
    {
        std::cerr << "Failed to load level " << lvl << " from file " << level << std::endl;
    }
}

std::vector<sf::Sprite> Map::init_layer(int layer)
{
    std::vector<sf::Sprite> tmp{};
    for ( int i{1}; i < 5; i++ )
    {    
        sf::Sprite layer1_1;
        sf::Sprite layer1_2;
        layer1_1.setTexture(*(Texture_Manager::get_texture("level"
		  + std::to_string(lvl) + "_layer" + std::to_string(layer))));
        layer1_1.setPosition(0.f, 0.f);
        layer1_2.setTexture(*(Texture_Manager::get_texture("level"
		  + std::to_string(lvl) + "_layer" + std::to_string(layer))));
        layer1_2.setPosition(WINDOW_WIDTH, 0.f);
        tmp.push_back(layer1_1);
        tmp.push_back(layer1_2);
    }
    return tmp;
}

void Map::init_backgrounds()
{
    layer1 = init_layer(1);
    layer2 = init_layer(2);
    layer3 = init_layer(3);
    layer4 = init_layer(4);
}

void Map::update_backgrounds()
{
    for (sf::Sprite & sprite : layer1)
    {
        sprite.move(sf::Vector2f{-0.2f, 0});
        if ( sprite.getPosition().x <= -WINDOW_WIDTH )
        {
            sprite.setPosition(WINDOW_WIDTH, 0);
        }
    }
    camera.move_layer(layer2, MOVE_RATE_LAYER2);
    camera.move_layer(layer3, MOVE_RATE_LAYER3);
    camera.move_layer(layer4, MOVE_RATE_LAYER4);
}

void Map::render_backgrounds(sf::RenderWindow & window)
{
    for ( sf::Sprite & sprite : layer1 )
    {
        window.draw(sprite);
    }
    for ( sf::Sprite & sprite : layer2 )
    {
        window.draw(sprite);
    }
    for ( sf::Sprite & sprite : layer3 )
    {
        window.draw(sprite);
    }
    for ( sf::Sprite & sprite : layer4 )
    {
        window.draw(sprite);
    }
}

void Map::check_collision(Player * player, Solid_Block * block)
{
    if ( !player->is_dying() )
    {
        switch ( detect_collision_direction(player, block) )
        {
            case FROM_TOP:
                player->stop_vertical();
                player->stop_jumping();
                break;
            case FROM_BOTTOM:
                player->stop_vertical();
                break;
            case FROM_RIGHT:
            case FROM_LEFT:
                player->stop_horizontal();
            default:
                break;
        }
    }
}

void Map::check_collision(Player * player, Enemy * enemy)
{
    if ( enemy->is_alive() && !player->is_ghost() )
    {
        switch ( detect_collision_direction(player, enemy) )
        {
            case FROM_TOP:
                if ( !dynamic_cast<Rolling_Stone *>(enemy) )
                {
                    player->jump(JUMP / 2);
                    enemy->kill();
                    Audio_Manager::enemy_killed();
                    Audio_Manager::jump();
                }
                else
                {
                    player->stop_vertical();
                    player->stop_jumping();
                }
                break;
            case FROM_BOTTOM:
            case FROM_RIGHT:
            case FROM_LEFT:
                player->start_death_animation();
                Audio_Manager::player_killed();
            default:
                break;
        }
    }
    if ( enemy->get_rect().left - player->get_rect().left < WINDOW_WIDTH )
    {
        enemy->spawn();
    }
}

void Map::check_collision(Player * player, Harmful_Block * block)
{
    if ( !player->is_ghost() )
    {
        switch ( detect_collision_direction(player, block) )
        {
            case NO_COLLISION:
                break;
            default:
                player->start_death_animation();
                Audio_Manager::player_killed();
                break;
        }
    }
}

void Map::check_collision(Player * player, Door * door)
{
    switch ( detect_collision_direction(player, door) )
    {
        case NO_COLLISION:
            break;
        default:
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
            {
                level_complete = true;
            }
            else
            {
                standing_on_door = true;
                door_helper.setPosition(door->get_position());
            }
            break;
    }
}

void Map::check_collision(Player * player, Treasure * treasure)
{
    switch ( detect_collision_direction(player, treasure) )
    {
        case NO_COLLISION:
            break;
        default:
            if( !player->has_super_power() && !treasure->is_opened()
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
            {
                player->activate_random_power_up();
                treasure->open();
                Audio_Manager::open_treasure();
            }
            else if ( !player->has_super_power() && !treasure->is_opened() )
            {
                standing_on_treasure = true;
                treasure_helper.setPosition(treasure->get_position());
            }
            break;
    }
}

void Map::check_collision(Player * player, Launcher * launcher)
{
    switch ( detect_collision_direction(player, launcher) )
    {
        case FROM_TOP:
            player->stop_vertical();
            player->stop_jumping();
            if ( !launcher->is_launched() )
            {
                if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
                {
                    launcher->launch();
                    player->jump(JUMP * 2.f);
                    Audio_Manager::launch();
                }
                standing_on_launcher = true;
                launcher_helper.setPosition(launcher->get_position());
            }
            break;
        case FROM_LEFT:
        case FROM_RIGHT:
            player->stop_horizontal();
            break;
        default:
            break;

    }
}

void Map::check_collision(Player * player, Bouncer * bouncer)
{
    switch ( detect_collision_direction(player, bouncer) )
    {
        case FROM_TOP:
            player->jump(bouncer->get_force());
            bouncer->bounce();
            Audio_Manager::bounce();
            break;
        case FROM_LEFT:
        case FROM_RIGHT:
            player->stop_horizontal();
            break;
        default:
            break;
    }
}

void Map::check_collision(Player * player, Flamer * flamer)
{
    switch ( detect_collision_direction(player, flamer) )
    {
        case FROM_TOP:
            if ( flamer->is_flaming() )
            {
                if ( !player->is_ghost() )
                {
                    player->start_death_animation();
                    Audio_Manager::player_killed();
                }
                else
                {
                    player->stop_vertical();
                    player->stop_jumping();
                }
            }
            else
            {
                player->stop_vertical();
                player->stop_jumping();
            }
            break;
        case FROM_BOTTOM:
            player->stop_vertical();
            break;
        case FROM_LEFT:
        case FROM_RIGHT:
            if ( flamer->is_flaming() )
            {
                if ( !player->is_ghost() )
                {
                    player->start_death_animation();
                    Audio_Manager::player_killed();
                }
                else
                {
                    player->stop_vertical();
                    player->stop_jumping();
                }
            }
            else
            {
                player->stop_horizontal();
            }
            break;
        default:
            break;
    }
}

void Map::check_collision(Player * player, Fan * fan)
{
    sf::FloatRect element{fan->get_rect()};
    sf::FloatRect player_rect{player->get_rect()};
    sf::Vector2f position{player->get_position()};
    if ( position.x + player_rect.width / 2 > element.left
    && position.x + player_rect.width / 2 < element.left + element.width
    && position.y + player_rect.height < element.top
    && position.y > element.top - 1500 )
    {
        player->blow(150 / (element.top - (position.y + player_rect.height)));
    }

}

void Map::check_collision(Player * player, Moving_Block * block)
{
    switch ( detect_collision_direction(player, block) )
    {
        case FROM_TOP:
            player->stop_vertical();
            player->stop_jumping();
            player->push(block->get_velocity().x);
            break;
        case FROM_BOTTOM:
            player->stop_vertical();
            break;
        case FROM_LEFT:
        case FROM_RIGHT:
            if ( (player->get_velocity().y < 0 && block->get_velocity().x >= 0)
                 || (player->get_velocity().y > 0 && block->get_velocity().x <= 0) )
            {
                player->stop_horizontal();
                player->push(block->get_velocity().x);
            }
        default:
            break;
    }
}

void Map::check_collision(Player * player, Checkpoint * checkpoint)
{
    switch ( detect_collision_direction(player, checkpoint) )
    {
        case NO_COLLISION:
            break;
        default:
            if ( !checkpoint->is_reached() )
            {
                player->set_checkpoint(checkpoint->get_position());
                checkpoint_animation_active = true;
                checkpoint->touchdown();
                Audio_Manager::checkpoint_reached();
            }
            break;
    }
}

void Map::check_collision(Player * player, Healthpack * healthpack)
{
    switch ( detect_collision_direction(player, healthpack) )
    {
        case NO_COLLISION:
            break;
        default:
            if ( !healthpack->is_used() )
            {
                healthpack->use();
                player->use_healthpack();
                Audio_Manager::healthpack_picked_up();
            }
            break;
    }
}

//Enemy
void Map::check_collision(Enemy * enemy, Solid_Block * block)
{
    switch ( detect_collision_direction(enemy, block) )
    {
        case FROM_TOP:
        case FROM_BOTTOM:
            enemy->stop_vertical();
            break;
        case FROM_LEFT:
        case FROM_RIGHT:
            enemy->change_direction();
            break;
        default:
            break;
    }
}

void Map::check_collision(Enemy * enemy, Enemy * other_enemy)
{
    switch ( detect_collision_direction(enemy, other_enemy) )
    {
        case NO_COLLISION:
            break;
        case FROM_TOP:
            enemy->stop_vertical();
            enemy->change_direction();
            other_enemy->change_direction();
        default:
            if ( enemy->is_alive() && other_enemy->is_alive() )
            {
                sf::FloatRect element{other_enemy->get_rect()};
                if ( enemy->get_rect().intersects(element) )
                {
                    enemy->change_direction();
                    other_enemy->change_direction();
                    if (dynamic_cast<Rolling_Stone *>(other_enemy)) {
                        enemy->push((enemy->get_velocity().x) * 1.3);
                        other_enemy->push((other_enemy->get_velocity().x) * 1.3);
                    }
                }
            }
            break;
    }
}

void Map::check_collision(Enemy * enemy, Harmful_Block * block)
{
    switch ( detect_collision_direction(enemy, block) )
    {
        case NO_COLLISION:
            break;
        default:
            enemy->change_direction();
            break;
    }
}

void Map::check_collision(Moving_Block * block, Game_Object * object)
{
    switch ( detect_collision_direction(block, object) )
    {
        case NO_COLLISION:
            break;
        default:
            block->change_direction();
            if ( dynamic_cast<Moving_Block*>(object) )
            {
                dynamic_cast<Moving_Block*>(object)->change_direction();
            }
            break;
    }
}

void Map::restart() {
    for ( Game_Object *&object: game_objects )
    {
        if ( dynamic_cast<Moving_Object *>(object) )
        {
            Moving_Object *tmp{ dynamic_cast<Moving_Object *>(object) };
            tmp->reset();
        }
        else if ( dynamic_cast<Treasure *>(object) )
        {
            Treasure *tmp{dynamic_cast<Treasure *>(object)};
            tmp->close();
        }
    }
}

void Map::out_of_bounds(Player * player) const
{
    sf::Vector2f position{player->get_position()};
    sf::Vector2f velocity{player->get_velocity()};
    if ( position != player->get_starting_position() )
    {
        if ( position.x <= 0 && velocity.x < 0 )
        {
            player->stop_horizontal();
        }
        else if ( position.x >= width - BLOCKSIZE - 10 && velocity.x > 0 )
        {
            player->stop_horizontal();
        }
        if ( position.y > (height + 200.0f) )
        {
            player->kill();
        }
    }
}

void Map::out_of_bounds(Enemy * enemy) const
{
    sf::Vector2f position{enemy->get_position()};
    sf::Vector2f velocity{enemy->get_velocity()};
    if ( position != enemy->get_starting_position() )
    {
        if ( position.x <= 0 && velocity.x < 0 )
        {
            enemy->change_direction();
        }
        if ( position.x >= width - BLOCKSIZE - 10 && velocity.x > 0 )
        {
            enemy->change_direction();
        }
        if ( position.y > (height + 200.0f) )
        {
            enemy->kill();
        }
    }
}

void Map::run_checkpoint_animation()
{
    checkpoint_opacity -= 3;
    checkpoint_helper.setFillColor(sf::Color(0,0,204,checkpoint_opacity));
    checkpoint_helper.setOutlineColor(sf::Color(255,255,255, checkpoint_opacity));
    checkpoint_helper.move(0, 2.f);
    if ( checkpoint_opacity < 0 )
    {
        checkpoint_animation_active = false;
        checkpoint_helper.setFillColor(sf::Color(0,0,204,255));
        checkpoint_helper.setPosition(200, 100);
        checkpoint_opacity = 255;
    }
}

void Map::manage_collisions()
{
    for ( Game_Object* object : game_objects )
    {
        if ( dynamic_cast<Player*>(object) )
        {
            Player* player{dynamic_cast<Player*>(object)};
            player->update(friction, gravity);
            out_of_bounds(player);
            if ( !player->is_dying() )
            {
                update_backgrounds();
                for ( Game_Object *opponent: game_objects )
                {
                    if ( dynamic_cast<Solid_Block *>(opponent) )
                    {
                        Solid_Block *tmp{dynamic_cast<Solid_Block *>(opponent)};
                        check_collision(player, tmp);
                        if ( dynamic_cast<Fan *>(tmp) )
                        {
                            Fan *fan{dynamic_cast<Fan *>(tmp)};
                            check_collision(player, fan);
                        }
                    }
                    else if ( dynamic_cast<Enemy *>(opponent) )
                    {
                        Enemy *tmp{dynamic_cast<Enemy *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Harmful_Block *>(opponent) )
                    {
                        Harmful_Block *tmp{dynamic_cast<Harmful_Block *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Door *>(opponent) )
                    {
                        Door *tmp{dynamic_cast<Door *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Treasure *>(opponent) )
                    {
                        Treasure *tmp{dynamic_cast<Treasure *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Launcher *>(opponent) )
                    {
                        Launcher *tmp{dynamic_cast<Launcher *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Bouncer *>(opponent) )
                    {
                        Bouncer *tmp{dynamic_cast<Bouncer *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Flamer *>(opponent) )
                    {
                        Flamer *tmp{dynamic_cast<Flamer *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Moving_Block *>(opponent) )
                    {
                        Moving_Block *tmp{dynamic_cast<Moving_Block *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Checkpoint *>(opponent) )
                    {
                        Checkpoint *tmp{dynamic_cast<Checkpoint *>(opponent)};
                        check_collision(player, tmp);
                    }
                    else if ( dynamic_cast<Healthpack *>(opponent) )
                    {
                        Healthpack *tmp{dynamic_cast<Healthpack *>(opponent)};
                        check_collision(player, tmp);
                    }


                }
            }
            player->update_position();
            if ( !player->is_alive() )
            {
                player->loose_life();
                time = TIME_LIMIT;
                restart();
            }
            if ( time <= 0 && !player->is_dying() ) { player->start_death_animation(); }
            if ( player->get_lives() < 1 ) { game_over = true; }

            std::string player_lives{std::to_string(player->get_lives())};
            lives.setString("Lives: " + player_lives);
            current_power_up.setString(player->get_current_power_up());
            player->update_graphics(camera);
        }
        else if ( dynamic_cast<Enemy*>(object) )
        {
            Enemy* enemy{dynamic_cast<Enemy*>(object)};
            enemy->update(friction, gravity);
            out_of_bounds(enemy);
            for ( Game_Object* opponent : game_objects )
            {
                if ( dynamic_cast<Solid_Block *>(opponent) )
                {
                    Solid_Block* tmp{dynamic_cast<Solid_Block *>(opponent)};
                    check_collision(enemy, tmp);
                }
                else if ( dynamic_cast<Enemy *>(opponent) )
                {
                    Enemy* tmp{dynamic_cast<Enemy *>(opponent)};
                    if ( enemy != tmp )
                    {
                        check_collision(enemy, tmp);
                    }
                } else if ( dynamic_cast<Harmful_Block *>(opponent) )
                {
                    Harmful_Block* tmp{dynamic_cast<Harmful_Block *>(opponent)};
                    check_collision(enemy, tmp);
                }
            }
            enemy->update_position();
        }
        else if ( dynamic_cast<Moving_Block*>(object) )
        {
            Moving_Block *block{dynamic_cast<Moving_Block *>(object)};
            for ( Game_Object * opponent: game_objects )
            {
                if ( !dynamic_cast<Player*>(opponent) )
                {
                    check_collision(block, opponent);
                }
            }
            block->update(friction, gravity);
        }
        else
        {
            object->update();
        }
    }
}

void Map::render_objects(sf::RenderWindow &window)
{
    for ( Game_Object* & object : game_objects )
    {
        object->render(window, camera);
    }
}

Map::Collision_Direction Map::detect_collision_direction(Moving_Object *lhs,
							 Game_Object *rhs)
{
    sf::FloatRect rhs_rect{rhs->get_rect()};
    sf::FloatRect lhs_rect{lhs->get_rect()};
    sf::Vector2f lhs_position{lhs->get_position()};
    sf::Vector2f lhs_velocity{lhs->get_velocity()};
    if ( lhs_rect.intersects(rhs_rect) )
    {
        if ( lhs_position.y + lhs_rect.height < rhs_rect.top )
        {
            return FROM_TOP;
        }
        else if ( lhs_rect.top
		  < rhs_rect.top + rhs_rect.height
		  && lhs_position.y - lhs_velocity.y
		  >= rhs_rect.top + rhs_rect.height - 1.f )
        {
            return FROM_BOTTOM;
        }
        else if ( (lhs_position.x + lhs_velocity.x + lhs_rect.width)
		  > (rhs_rect.left + lhs_velocity.x) )
        {
            return FROM_LEFT;
        }
        else if ( (lhs_position.x - lhs_velocity.x)
		  < (rhs_rect.left + rhs_rect.width - lhs_velocity.x) )
        {
            return FROM_RIGHT;
        }
    }
    return NO_COLLISION;
}
