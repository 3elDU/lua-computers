#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>
#include <string>

#include "helpers.hpp"

namespace zd {
    // forward declarations
    class Texture;

    class Application {
        friend class Texture;

    public:
        Application(const unsigned width, const unsigned height, const char* title);
        ~Application();
        
        void clearScreen(uint8_t r, uint8_t g, uint8_t b);
        void clearScreen(Color color);

        void fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void fillRect(int x, int y, int w, int h, Color color);

        void drawTexture(Texture& texture, int x, int y);

        void drawPixel(int x, int y, unsigned size, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void drawPixel(int x, int y, unsigned size, Color color);

        void updateScreen();

    protected:
        void panic(const char* reason);
        void assert(void* addr, const char* description);

    private:
        SDL_Window* win;
        SDL_Renderer* ren;

        SDL_Surface* screen;

        bool panicked;
        std::string panicReason;
    };
}

#endif