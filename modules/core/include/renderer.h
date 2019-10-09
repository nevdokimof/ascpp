#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <algorithm>
#include <queue>

#include "game_scene.h"

namespace ascpp {

class renderer
{
public:
    renderer(size_t viewport_height, size_t viewport_width);
    void draw(const game_scene &scene);

private:
    std::string create_empty_frame();
    std::string fill_frame(const std::vector<std::shared_ptr<drawable>> &drawables);
    void add_to_frame(std::shared_ptr<drawable> drawable, std::string &frame);
    void put_on_screen(const std::string &frame);

    size_t viewport_width = 0;
    size_t viewport_height = 0;
};

} // ascpp

#endif // RENDERER_H
