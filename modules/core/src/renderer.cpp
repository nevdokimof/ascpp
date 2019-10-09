#include "renderer.h"

ascpp::renderer::renderer(size_t height, size_t width) : viewport_width(width), viewport_height(height)
{

}

void ascpp::renderer::draw(const ascpp::game_scene &scene)
{
    auto &&scene_drawables = scene.get_drawables();
    auto &&frame = fill_frame(scene_drawables);
    put_on_screen(frame);
}

std::string ascpp::renderer::fill_frame(const std::vector<std::shared_ptr<ascpp::drawable> > &drawables)
{
    std::priority_queue z_ordered_drawables{drawables.begin(), drawables.end(), [](const std::shared_ptr<drawable> drawable1,
                const std::shared_ptr<drawable> drawable2) {
            return drawable1->get_coordinates().z > drawable2->get_coordinates().z;
        }};

    std::string &&frame_with_drawables = create_empty_frame();
    while(!z_ordered_drawables.empty()) {
        add_to_frame(z_ordered_drawables.top(), frame_with_drawables);
        z_ordered_drawables.pop();
    }
    return std::move(frame_with_drawables);
}

std::string ascpp::renderer::create_empty_frame()
{
    std::string frame{};
    for(size_t row = 0; row < viewport_height; ++row) {
        for(size_t col = 0; col < viewport_width; ++col)
            frame.push_back(' ');
        frame.push_back('\n');
    }
    return frame;
}

void ascpp::renderer::add_to_frame(std::shared_ptr<ascpp::drawable> drawable, std::string &frame)
{
    auto &&drawable_coords = drawable->get_coordinates();
    // can't draw drawable if it is beyond viewport
    if(drawable_coords.x >= viewport_width || drawable_coords.y >= viewport_height)
        return;

    auto &&drawable_string = drawable->get_string_to_draw();

    long drawable_rows = std::count(drawable_string.begin(), drawable_string.end(), '\n') + 1;
    ulong rows_to_display = std::min(static_cast<ulong>(drawable_rows),
                                     viewport_height - drawable_coords.y);

    ulong drawable_cols = drawable_string.find('\n') + 1;
    ulong cols_to_display = std::min(drawable_cols, viewport_width - drawable_coords.x);

    // fill frame char by char
    for(size_t absolute_y = drawable_coords.y;
        absolute_y < drawable_coords.y + rows_to_display - 1; ++absolute_y) {
        for(size_t absolute_x = drawable_coords.x;
            absolute_x < drawable_coords.x + cols_to_display; ++absolute_x) {
            auto &frame_char = frame.at(absolute_x + (viewport_width+1)*absolute_y);
            auto &&drawable_char = drawable_string.at(absolute_x - drawable_coords.x
                                                      + (absolute_y - drawable_coords.y) * drawable_cols);
            if(frame_char == ' ' && drawable_char != '\n')
                frame_char = drawable_char;
        }
    }
}

void ascpp::renderer::put_on_screen(const std::string &frame)
{
    std::cout << frame;
}
