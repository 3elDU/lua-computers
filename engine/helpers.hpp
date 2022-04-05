#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <stdint.h>

namespace zd {

    // our own color class
    class Color {
    public:
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
        Color(uint32_t rgba);
        Color(const Color& color);

        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
}

#endif