#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "drawable.h"
#include "sprite.h"

namespace ascpp {

class game_object
{
public:
    game_object(std::shared_ptr<sprite> sprite);
    const std::shared_ptr<drawable> get_drawable() const;

private:
    std::shared_ptr<drawable> object_drawable;
};

} //ascpp

#endif // GAME_OBJECT_H
