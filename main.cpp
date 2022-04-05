#include <iostream>

#include "engine/engine.hpp"
#include "engine/texture.hpp"

int main(int argc, char** argv) {
    // create application
    zd::Application app(640, 480, "ZD Engine");

    // create texture
    zd::Texture tex(app, "assets/bebra.png");

    // draw texture
    app.drawTexture(tex, 0, 0);

    // update screen
    app.updateScreen();

    // wait for user input
    SDL_Event event;
    while (true) {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    std::cout << "Done!" << std::endl;

    return 0;
}