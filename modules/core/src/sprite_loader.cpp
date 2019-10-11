#include "sprite_loader.h"

ascpp::sprite_loader::not_an_ascii::not_an_ascii() : runtime_error("")
{

}

ascpp::sprite_loader::not_a_file::not_a_file() : runtime_error("")
{

}

ascpp::sprite_loader::sprite_loader()
{

}

ascpp::sprite ascpp::sprite_loader::load(const std::filesystem::path &path_to_ascii_text_file)
{
    if(!path_to_ascii_text_file.has_filename())
        throw not_a_file();

    try {
        auto &&loaded_file = load_file(path_to_ascii_text_file);
        return sprite(loaded_file);
    }
    catch (not_an_ascii&) {
        throw;
    }
}

bool ascpp::sprite_loader::check_for_ascii(char c)
{
    static const std::string ascii_charset = " !\"#$%&'()*+,-./0123456789:;<=>?@`"
                                             "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]~^_`"
                                             "abcdefghijklmnopqrstuvwxyz{|}\n\r";
    return ascii_charset.find(c) != std::string::npos;
}

std::string ascpp::sprite_loader::load_file(const std::filesystem::path &path_to_file)
{
    std::string file_buffer;
    char char_buffer = 0;
    std::ifstream file_stream(path_to_file);
    //disable skipping whitechars
    file_stream.unsetf(std::ios_base::skipws);
    while(file_stream >> char_buffer) {
        if(check_for_ascii(char_buffer)) {
            file_buffer.push_back(char_buffer);
        }
        else {
            file_stream.close();
            throw not_an_ascii();
        }
    }

    file_stream.close();
    return file_buffer;
}
