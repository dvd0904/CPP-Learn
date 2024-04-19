#include "person.h"
#include "player.h"

// Player::Player(std::string_view game_param)
//     : m_game(game_param)
// {
//     /* After change this private member to protected member -> Work */
//     first_name = "John"; 
//     last_name = "Snow";
// }

Player::Player(std::string_view game_param, std::string_view first_name_param, std::string_view last_name_param)
{
    m_game = game_param;
    first_name = first_name_param;
    last_name = last_name_param;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
 
    out << "Player : [ game : "  << player.m_game
         << " names : " << player.get_first_name()
             << " " << player.get_last_name() << "]";
    return out;
}