#include "renderer.h"

ascpp::renderer::renderer()
{

}

void ascpp::renderer::draw(const ascpp::game_scene &scene)
{
    auto &&drawables = scene.get_drawables();
    for(auto&& drawable : drawables)
        put_on_screen(*drawable);
}

void ascpp::renderer::put_on_screen(const ascpp::drawable &drawable)
{
    auto &&coords = drawable.get_coordinates();
    std::cout << drawable.get_string_to_draw();
}
