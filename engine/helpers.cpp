#include "helpers.hpp"

namespace zd {
    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
    Color::Color(uint32_t rgba) : r((rgba >> 24) & 0xFF), g((rgba >> 16) & 0xFF), b((rgba >> 8) & 0xFF), a(rgba & 0xFF) {}
    Color::Color(const Color& color) : r(color.r), g(color.g), b(color.b), a(color.a) {}
}