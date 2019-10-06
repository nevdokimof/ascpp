#ifndef SPRITE_LOADER_H
#define SPRITE_LOADER_H

#include <filesystem>
#include <fstream>
#include <stdexcept>

#include "sprite.h"

namespace ascpp {

class sprite_loader
{
public:
    class not_an_ascii : public std::runtime_error {
    public:
        not_an_ascii();
    };

    class not_a_file : public std::runtime_error {
    public:
        not_a_file();
    };

    sprite_loader();
    sprite load(const std::filesystem::path &path_to_ascii_text_file);

private:
    bool check_for_ascii(char c);
    std::string load_file(const std::filesystem::path &path_to_file);
};

} //ascpp

#endif // SPRITE_LOADER_H
