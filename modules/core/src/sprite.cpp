#include "sprite.h"

ascpp::sprite::sprite(const std::string &ascii_string)
{
    ascii_representaion = ascii_string;
}

std::string ascpp::sprite::get_string_to_draw() const
{
    return ascii_representaion;
}

ascpp::coordinates ascpp::sprite::get_coordinates() const
{
    return coordinates{0,0,0};
}
