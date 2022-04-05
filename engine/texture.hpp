#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL.h>
#include <string>

namespace zd {
    // forward declarations
    class Application;

    class Texture {
    public:
        Texture(Application& app, std::string path);
        Texture(Application& app, SDL_Surface* surface);
        Texture(const Texture& texture);
        ~Texture();

        SDL_Texture* getTexture();

        const unsigned getWidth() const;
        const unsigned getHeight() const;

    private:
        SDL_Texture* tex;
        unsigned width;
        unsigned height;
    };
}

#endif