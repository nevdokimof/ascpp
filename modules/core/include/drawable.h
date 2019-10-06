#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

#include "coordinates.h"

namespace ascpp {

class drawable {
public:
    virtual std::string get_string_to_draw() const = 0;
    virtual coordinates get_coordinates() const = 0;
    virtual ~drawable() = default;
};

} // ascpp

#endif // DRAWABLE_H
