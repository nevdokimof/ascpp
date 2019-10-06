#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <vector>
#include <memory>

#include "drawable.h"
#include "game_object.h"

namespace ascpp {

class game_scene
{
public:
    game_scene();
    std::vector<std::shared_ptr<drawable>> get_drawables() const;
    void add_object(const game_object &object);

private:
    std::vector<game_object> game_objects{};
};

} // ascpp

#endif // GAME_SCENE_H
