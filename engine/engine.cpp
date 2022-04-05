#include "engine.hpp"
#include "texture.hpp"

namespace zd {
    // application constructor / destructor
    Application::Application(const unsigned width, const unsigned height, const char* title) {

        // create a window
        win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        assert(win, "Failed to create window");

        // create a renderer ( for accelerated 2D rendering )
        ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        assert(ren, "Failed to create renderer");

        // get the surface of the window, for converting colors
        screen = SDL_GetWindowSurface(win);
        assert(screen, "Failed to get window surface");

        // set default values
        panicked = false;
        panicReason = "";
    }

    Application::~Application() {
        // clean up
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
    }


    // rendering functions

    void Application::clearScreen() {
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
    }

    void Application::clearScreen(uint8_t r, uint8_t g, uint8_t b) {
        SDL_SetRenderDrawColor(ren, r, g, b, 255);
        SDL_RenderClear(ren);
    }

    void Application::fillRect(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        SDL_SetRenderDrawColor(ren, r, g, b, a);

        SDL_Rect rect = {x, y, w, h};
        SDL_RenderFillRect(ren, &rect);
    }

    void Application::fillRect(int x, int y, int w, int h, Color color) {
        fillRect(x, y, w, h, color.r, color.g, color.b, color.a);
    }

    void Application::drawTexture(Texture& texture, int x, int y) {
        SDL_Rect rect = { x, y, (int)texture.getWidth(), (int)texture.getHeight() };
        SDL_RenderCopy(ren, texture.getTexture(), NULL, &rect);
    }

    void Application::drawPixel(int x, int y, unsigned size, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        SDL_Rect rect = { x, y, (int)size, (int)size };
        SDL_FillRect(screen, &rect, SDL_MapRGBA(screen->format, r, g, b, a));
    }

    void Application::drawPixel(int x, int y, unsigned size, Color color) {
        drawPixel(x, y, size, color.r, color.g, color.b, color.a);
    }

    void Application::updateScreen() {
        SDL_RenderPresent(ren);
    }

    // helper functions

    void Application::assert(void* addr, const char* description) {
        if (!addr) {
            panic(description);
        }
    }

    void Application::panic(const char* reason) {
        panicked = true;
        panicReason = reason;
        printf("[Application::panic] %s\n", reason);

        // since we're panicking, we can't continue
        exit(1);
    }
}