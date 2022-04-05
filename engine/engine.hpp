#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>
#include <string>

#include "helpers.hpp"

namespace zd {
    // forward declarations
    class Texture;

    class Application {
        // so the texture class can access our private properties
        friend class Texture;

    public:
        Application(const unsigned width, const unsigned height, const char* title);
        ~Application();
        
        // rendering functions

        void clearScreen(); // simply clears screen with black color
        void clearScreen(uint8_t r, uint8_t g, uint8_t b);
        void clearScreen(Color color);

        // fills a rectangle with a color
        void fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void fillRect(int x, int y, int w, int h, Color color);

        // draws a texture ( default position is top-left corner )
        void drawTexture(Texture& texture, int x, int y);

        // draws a pixel
        void drawPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a); // draw a pixel with size 1
        void drawPixel(int x, int y, Color color); // the same, but using our own color class

        void drawPixel(int x, int y, unsigned size, uint8_t r, uint8_t g, uint8_t b, uint8_t a); // draw a pixel with specified size
        void drawPixel(int x, int y, unsigned size, Color color); // the same, but using our own color class

        // swap buffers, or simply, update the screen contents
        void updateScreen(); 

    protected:
        void panic(const char* reason);
        void assert(void* addr, const char* description);

    private:
        // the window itself
        SDL_Window* win;

        // the renderer ( needed for accelerated 2D rendering )
        SDL_Renderer* ren;

        // surface of our screened ( needed when converting colors )
        SDL_Surface* screen;

        bool panicked;
        std::string panicReason;
    };
}

#endif