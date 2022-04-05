#include "texture.hpp"
#include "engine.hpp"

#include <SDL2/SDL_image.h>

namespace zd {
    // texture constructor / destructor
    Texture::Texture(Application& app, std::string path) {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (surface == nullptr) {
            app.panic("failed to load image");
        }

        tex = SDL_CreateTextureFromSurface(app.ren, surface);
        if (tex == nullptr) {
            app.panic("failed to create texture");
        }

        width = surface->w;
        height = surface->h;

        SDL_FreeSurface(surface);
    }

    Texture::~Texture() {
        SDL_DestroyTexture(tex);
    }

    // texture getter
    SDL_Texture* Texture::getTexture() {
        return tex;
    }

    // width and height getters
    const unsigned Texture::getWidth() const {
        return width;
    }

    const unsigned Texture::getHeight() const {
        return height;
    }
}