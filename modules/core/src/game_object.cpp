#include "game_object.h"

ascpp::game_object::game_object(std::shared_ptr<ascpp::sprite> sprite)
{
    object_drawable = sprite;
}

const std::shared_ptr<ascpp::drawable> ascpp::game_object::get_drawable() const
{
    return object_drawable;
}
