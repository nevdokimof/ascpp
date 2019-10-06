#ifndef SPRITE_H
#define SPRITE_H

#include <filesystem>

#include "drawable.h"

namespace ascpp {

class sprite : public drawable {
public:
    sprite(const std::string &ascii_string);
    std::string get_string_to_draw() const override;
    coordinates get_coordinates() const override;

private:
    std::string ascii_representaion{};
};

} // ascpp

#endif // SPRITE_H
