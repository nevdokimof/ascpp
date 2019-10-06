#include <iostream>

#include "renderer.h"
#include "sprite_loader.h"

int main() {
    ascpp::sprite_loader loader;
    auto sprite = new ascpp::sprite(loader.load("./habr.txt"));
    ascpp::renderer renderer;
    ascpp::game_scene scene;
    scene.add_object(ascpp::game_object(std::shared_ptr<ascpp::sprite>(sprite)));
    renderer.draw(scene);
    return 0;
}
