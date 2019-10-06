#include "game_scene.h"

ascpp::game_scene::game_scene()
{

}

std::vector<std::shared_ptr<ascpp::drawable> > ascpp::game_scene::get_drawables() const
{
    std::vector<std::shared_ptr<ascpp::drawable>> object_drawables{};
    for(auto &&game_object : game_objects)
        object_drawables.push_back(game_object.get_drawable());
    return object_drawables;
}

void ascpp::game_scene::add_object(const ascpp::game_object &object)
{
    game_objects.push_back(object);
}
