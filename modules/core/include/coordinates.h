#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdint>

namespace ascpp {

struct coordinates {
    uint16_t x = 0;
    uint16_t y = 0;
    uint8_t z = 0;
};

} // ascpp

#endif // COORDINATES_H
