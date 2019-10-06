#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>

#include "game_scene.h"

namespace ascpp {

class renderer
{
public:
    renderer();
    void draw(const game_scene &scene);

private:
    void put_on_screen(const drawable &drawable);
};

} // ascpp

#endif // RENDERER_H
